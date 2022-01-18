#include "Thread.h"
#include <thread>
#include <iostream>
#include <event2/event.h>
#include "Task.h"

#ifdef _WIN32
#else
#include <unistd.h>
#endif

using namespace std;

//激活线程任务的回调函数
static void NotifyCB(evutil_socket_t clientSock, short what, void *arg)
{
    CThread *th = (CThread *)arg;
    th->Notify(clientSock, what);
}

void CThread::Notify(evutil_socket_t clientSock, short what)
{
    //水平触发，只要没有接受完成，会再次进入
    char buf[2] = {0};
    int ret = 0;
#ifdef _WIN32
    ret = recv(clientSock, buf, 1, 0);
#else
    //linux中是管道，不能recv
    ret = read(clientSock, buf, 1);
#endif
    if (ret < 0) {
        return;
    }

    std::cout << m_nId << " thread " << buf << std::endl;

    //获取任务，并初始化任务
    m_tasksMutex.lock();
    if (m_tasks.empty()) {
        m_tasksMutex.unlock();
        return;
    }

    CTask *task = nullptr;
    task = m_tasks.front();
    m_tasks.pop_front();
    m_tasksMutex.unlock();
    task->Init();

    return;
}

void CThread::Start()
{
    Setup();
    std::thread th(&CThread::Main, this);
    th.detach(); //断开于主线程关系
}

void CThread::Main()
{
    std::cout << m_nId << std::endl;

    //设置为不阻塞分发消息
    // event_base_dispatch(m_base);
    while (!m_is_exit) {
        //一次处理多条消息
        event_base_loop(m_base, EVLOOP_NONBLOCK);
        this_thread::sleep_for(chrono::milliseconds(1));
    }
    
    event_base_free(m_base);
}

bool CThread::Setup()
{
    //windows用配对socket linux用管道
#ifdef _WIN32

    evtutil_socket_t fds[2];
    if (evutil_socket_pair(AF_INET, SOCK_STREAM, 0, fds) < 0) {
        return false;
    }
    
    //设置为非阻塞
    evutil_make_socket_nonblocking(fds[0]);
    evutil_make_socket_nonblocking(fds[1]);

#else

    //创建的管道 不能用send recv读取 read write
	int fds[2];
	if (pipe(fds)) {
		std::cerr << "pipe failed!" << std::endl;
		return false;
    }

#endif

    //读取绑定到event事件中，写入要保存
    m_nNotifySendFd = fds[1];

    //创建libevent上下文(无锁)
    event_config *ev_config = event_config_new();
    event_config_set_flag(ev_config, EVENT_BASE_FLAG_NOLOCK);
    m_base = event_base_new_with_config(ev_config);
    event_config_free(ev_config);
    if (!m_base) {
        std::cerr << "event_base_new_with_config failed" << std::endl;
        return false;
    }
    
    //添加管道监听事件，用于激活线程执行人物
    event *ev = event_new(m_base, fds[0], EV_READ | EV_WRITE, NotifyCB, this);
    event_add(ev, 0);

    return true;

}

void CThread::Activate() 
{
#ifdef _WIN32
    int ret = send(m_nNotifySendFd, "c", 1, 0);
#else
    int ret = write(m_nNotifySendFd, "c", 1);
#endif

    if (ret <= 0) {
        std::cerr << "CThread::Activate failed" << std::endl;
    }
}

void CThread::AddTask(CTask *task)
{
    if (!task) return;
    task->m_base = m_base;
    m_tasksMutex.lock();
    m_tasks.push_back(task);
    m_tasksMutex.unlock();
}


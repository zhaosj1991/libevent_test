#include "xthread.h"
// #include "xlog_client.h"
#include <thread>
#include <iostream>
#include <sstream>
#include <event2/event.h>
#include "xtask.h"
#include "xtools.h"
#ifdef _WIN32
#else
#include <unistd.h>
#endif

using namespace std;

//�����߳�����Ļص�����
static void NotifyCB(int fd, short which, void *arg)
{
	XThread *t = (XThread *)arg;
	t->Notify(fd, which);
}

class CXThread :public XThread
{
public:
    void Notify(int fd, short which)
    {
        //ˮƽ���� ֻҪû�н�����ɣ����ٴν���
        char buf[2] = { 0 };
#ifdef _WIN32
        int re = recv(fd, buf, 1, 0);
#else
        //linux���ǹܵ���������recv
        int re = read(fd, buf, 1);
#endif
        if (re <= 0)
            return;

        stringstream ss;
        ss << id << " thread " << buf;
        LOGDEBUG(ss.str().c_str());
        XTask *task = NULL;
        //��ȡ���񣬲���ʼ������
        tasks_mutex_.lock();
        if (tasks_.empty())
        {
            tasks_mutex_.unlock();
            return;
        }
        task = tasks_.front(); //�Ƚ��ȳ�
        tasks_.pop_front();
        tasks_mutex_.unlock();
        task->Init();
    }

    void AddTask(XTask *t)
    {
        if (!t)return;
        t->set_base(this->base_);
        tasks_mutex_.lock();
        tasks_.push_back(t);
        tasks_mutex_.unlock();
    }
    //�̼߳���
    void Activate()
    {
#ifdef _WIN32
        int re = send(this->notify_send_fd_, "c", 1, 0);
#else
        int re = write(this->notify_send_fd_, "c", 1);
#endif
        if (re <= 0)
        {
            //stringstream ss;
            //ss << "XThread::Activate() failed!" ;
            LOGERROR("XThread::Activate() failed!");
        }
    }
    //�����߳�
    void Start()
    {
        Setup();
        //�����߳�
        thread th(&CXThread::Main, this);

        //�Ͽ������߳���ϵ
        th.detach();
    }
    //��װ�̣߳���ʼ��event_base�͹ܵ������¼����ڼ���
    bool Setup()
    {
        //windows�����socket linux�ùܵ�
#ifdef _WIN32
    //����һ��socketpair ���Ի���ͨ�� fds[0] �� fds[1]д 
        evutil_socket_t fds[2];
        if (evutil_socketpair(AF_INET, SOCK_STREAM, 0, fds) < 0)
        {
            //cout << "evutil_socketpair failed!" << endl;
      //      stringstream ss;
      //      ss << "XThread::Activate() failed!";
            LOGERROR("evutil_socketpair failed!");

            return false;
        }
        //���óɷ�����
        evutil_make_socket_nonblocking(fds[0]);
        evutil_make_socket_nonblocking(fds[1]);
#else
    //�����Ĺܵ� ������send recv��ȡ read write
        int fds[2];
        if (pipe(fds))
        {
            //cerr << "pipe failed!" << endl;
            LOGERROR("pipe failed!");
            return false;
        }
#endif

        //��ȡ�󶨵�event�¼��У�д��Ҫ����
        notify_send_fd_ = fds[1];

        //����libevent�����ģ�������
        event_config *ev_conf = event_config_new();
        //��Ҫ���Ǵ��������̵߳���ʱ
        event_config_set_flag(ev_conf, EVENT_BASE_FLAG_NOLOCK);
        this->base_ = event_base_new_with_config(ev_conf);
        event_config_free(ev_conf);
        if (!base_)
        {
            //cerr << "event_base_new_with_config failed in thread!" << endl;
            LOGERROR("event_base_new_with_config failed in thread!");
            return false;
        }

        //��ӹܵ������¼������ڼ����߳�ִ������
        event *ev = event_new(base_, fds[0], EV_READ | EV_PERSIST, NotifyCB, this);
        event_add(ev, 0);

        return true;
    }
private:
    //�߳���ں���
    void Main()
    {
        stringstream ss;
        ss << id << " XThread::Main() begin" << endl;
        LOGDEBUG(ss.str().c_str());
        if (!base_)
        {
            cerr << "XThread::Main faield! base_ is null " << endl;
            cerr << "In windows set WSAStartup(MAKEWORD(2, 2), &wsa)" << endl;
            return;
        }

        //����Ϊ�������ַ���Ϣ
        while (!is_exit_)
        {
            //һ�δ��������Ϣ
            event_base_loop(base_, EVLOOP_NONBLOCK);
            this_thread::sleep_for(chrono::milliseconds(1));
        }


        //event_base_dispatch(base_);

        event_base_free(base_);

        //cout << id << " XThread::Main() end" << endl;
        ss.str("");
        ss << id << " XThread::Main() end" << endl;
        LOGDEBUG(ss.str().c_str());
    }


    bool is_exit_ = false;
    int notify_send_fd_ = 0;
    struct event_base *base_ = 0;

    //�����б�
    std::list<XTask*> tasks_;
    //�̰߳�ȫ ����
    std::mutex tasks_mutex_;
};

XThread * XThread::Create()
{
    return new CXThread();
}

XThread::XThread()
{
}


XThread::~XThread()
{
}

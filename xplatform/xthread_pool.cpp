#include "xthread_pool.h"
#include "xthread.h"
#include <thread>
#include <iostream>
#include "xtask.h"
#include <thread>
#include <sstream>
#include "xtools.h"
// #include "xlog_client.h"
#ifdef _WIN32
//��protobufͷ�ļ����г�ͻ ��protobuf��ͷ�ļ�Ҫ��windows.h֮ǰ
#include <windows.h>
#else
#include <signal.h>
#endif
using namespace std;

///�����̵߳�ѭ���˳��ж�
static bool is_exit_all = false;

///���е��̶߳���
static vector<XThread *>all_threads;
static mutex all_threads_mutex;
//////////////////////////////////////////////////////
///�˳����е��߳�
void XThreadPool::ExitAllThread()
{
    is_exit_all = true;
    all_threads_mutex.lock();
    for (auto t : all_threads)
    {
        t->Exit();
    }
    all_threads_mutex.unlock();
    this_thread::sleep_for(chrono::milliseconds(200));
}

void XThreadPool::Wait()
{
    while (!is_exit_all)
    {
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}
class CXThreadPool :public XThreadPool
{
public:
    //�ַ��߳�
    void Dispatch(XTask *task)
    {
        //��ѯ
        if (!task)return;
        int tid = (last_thread_ + 1) % thread_count_;
        last_thread_ = tid;
        XThread *t = threads_[tid];

        t->AddTask(task);

        //�����߳�
        t->Activate();

    }
    //��ʼ�������̲߳������߳�
    void Init(int thread_count)
    {
        this->thread_count_ = thread_count;
        this->last_thread_ = -1;
        for (int i = 0; i < thread_count; i++)
        {
            XThread *t = XThread::Create();// new XThread();
            t->id = i + 1;
            stringstream ss;
            ss << "Create thread " << i;
            LOGDEBUG(ss.str().c_str());
            //�����߳�
            t->Start();
            threads_.push_back(t);
            all_threads_mutex.lock();
            all_threads.push_back(t);
            all_threads_mutex.unlock();
            this_thread::sleep_for(chrono::milliseconds(10));
        }
    }
private:

    ///�߳�����
    int thread_count_ = 0;

    ///��һ�ηַ��õ��̣߳�������ѯ
    int last_thread_ = -1;

    ///�̳��̶߳���
    std::vector<XThread *>threads_;
};

XThreadPool *XThreadPoolFactory::Create()
{
    //socket���ʼ��
    static mutex mux;
    static bool is_init = false;
    mux.lock();
    if (!is_init)
    {
#ifdef _WIN32 
        //��ʼ��socket��
        WSADATA wsa;
        WSAStartup(MAKEWORD(2, 2), &wsa);
#else
        //ʹ�öϿ�����socket���ᷢ�����źţ���ɳ����˳�
        if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
            return NULL;
#endif
        is_init = true;
    }
    mux.unlock();
    return new CXThreadPool();
}

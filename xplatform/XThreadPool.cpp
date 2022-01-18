#include <iostream>
#include <thread>
#include <chrono>
#include "XThreadPool.h"
#include "Thread.h"
#include "Task.h"

using namespace std;

static bool is_exit_all = false;
static vector<CThread *> all_threads;
static mutex all_threads_mutex;

void XThreadPool::ExitAllThread()
{
    is_exit_all = true;
    all_threads_mutex.lock();
    for (auto &t : all_threads) {
        t->Exit();
    }
    all_threads_mutex.unlock();
    this_thread::sleep_for(chrono::milliseconds(200));
}

void XThreadPool::Wait()
{
    while (is_exit_all){
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    
}

class CXThreadPool : public XThreadPool
{
public:
    virtual void Init(int nThreadCount) override;

    //线程分发
    virtual void Dispatch(CTask *task) override;

private:
    int m_nThreadCount = 0; //线程数量
    int m_nLastThread = -1; //上次分发的线程
    std::vector<CThread *> m_vecThreads; //线程集合
};

void CXThreadPool::Init(int nThreadCount)
{
    m_nThreadCount = nThreadCount;
    m_nLastThread = -1;
    for (int i = 0; i < nThreadCount; i++) {
        std::cout << "Create thread" << i << std::endl;
        CThread *t = new CThread();
        t->m_nId = i + 1;
        t->Start();
        m_vecThreads.push_back(t);
        all_threads_mutex.lock();
        all_threads.push_back(t);
        all_threads_mutex.unlock();
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }
}

void CXThreadPool::Dispatch(CTask *task)
{
    if (nullptr == task) {
        return;
    }

    int tid = (m_nLastThread + 1) % m_nThreadCount;
    m_nLastThread = tid;

    CThread *t = m_vecThreads[tid];

    t->AddTask(task);

    //激活线程
    t->Activate();
}

XThreadPool *XThreadPoolFactory::Create()
{
    return new CXThreadPool();
}
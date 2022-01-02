#include <iostream>
#include <thread>
#include <chrono>
#include "XThreadPool.h"
#include "Thread.h"
#include "Task.h"

void XThreadPool::Init(int nThreadCount)
{
    m_nThreadCount = nThreadCount;
    m_nLastThread = -1;
    for (int i = 0; i < nThreadCount; i++) {
        std::cout << "Create thread" << i << std::endl;
        CThread *t = new CThread();
        t->m_nId = i + 1;
        t->Start();
        m_vecThreads.push_back(t);
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }
}

void XThreadPool::Dispatch(CTask *task)
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
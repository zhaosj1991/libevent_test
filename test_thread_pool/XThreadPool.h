#pragma once
#include <vector>

class CThread;
class CTask;

class XThreadPool
{
private:
    /* data */
public:
    ~XThreadPool() {}

    static XThreadPool* Get() 
    {
        static XThreadPool p;
        return &p;
    }

    void Init(int nThreadCount);

    //线程分发
    void Dispatch(CTask *task);

private:
    XThreadPool(/* args */) {}
    
private:
    int m_nThreadCount = 0; //线程数量
    int m_nLastThread = -1; //上次分发的线程
    std::vector<CThread *> m_vecThreads; //线程集合

};
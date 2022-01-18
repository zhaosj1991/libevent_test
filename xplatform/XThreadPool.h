#pragma once
#include <vector>

#ifdef _WIN32
#ifdef XCOM_EXPORTS
#define XCOM_API __declspec(dllexport)
#else
#define XCOM_API __declspec(dllimport)
#endif
#else
#define XCOM_API
#endif

class CThread;
class CTask;

class XCOM_API XThreadPool
{
private:
    /* data */
public:
    ~XThreadPool() {}

    // static XThreadPool* Get() 
    // {
    //     static XThreadPool p;
    //     return &p;
    // }

    virtual void Init(int nThreadCount) = 0;

    //线程分发
    virtual void Dispatch(CTask *task) = 0;

    static void ExitAllThread();

    //阻塞等待线程推出
    static void Wait();
};

class  XCOM_API XThreadPoolFactory {
public:
    //创建线程池对象
    static XThreadPool *Create();
    
};
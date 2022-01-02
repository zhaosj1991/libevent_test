#pragma once
#include <list>
#include <event2/event.h>
#include <mutex>

class CTask;

class CThread
{
private:
    /* data */
public:
    CThread(/* args */) {}
    ~CThread() {}

    void Start(); //启动函数
    void Main(); //线程入口函数

    bool Setup(); //安装线程，初始化event_base和管道监听事件

    void Notify(evutil_socket_t clientSock, short what);

    //线程激活
    void Activate();

    //添加处理人物
    void AddTask(CTask *task);

private:
    int m_nNotifySendFd = 0;
    struct event_base *m_base = 0;
    //任务列表
    std::list<CTask*> m_tasks;
    std::mutex m_tasksMutex;
    
public:
    int m_nId = 0;
};

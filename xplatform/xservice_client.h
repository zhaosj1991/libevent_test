#pragma once

#include "xmsg_event.h"
#include "xthread_pool.h"

class XServiceClient: public XMsgEvent
{
private:
    /* data */
public:
    XServiceClient();
    ~XServiceClient();
    //将任务加入到线程池中，进行连接
    virtual void StartConnect();

private:
    XThreadPool *m_thread_pool = nullptr;
};

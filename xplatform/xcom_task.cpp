#include "xcom_task.h"
#include <event2/bufferevent.h>
#include <event2/event.h>
#include <iostream>
#include <string.h>
#include "xmsg_comm.pb.h"
#include "xtools.h"

using namespace std;
using namespace xmsg;

static void SReadCB(struct bufferevent *bev, void *ctx)
{
    auto task = (XComTask*)ctx;
    task->ReadCB();
}
static void SWriteCB(struct bufferevent *bev, void *ctx)
{
    auto task = (XComTask*)ctx;
    task->WriteCB();
}

static void SEventCB(struct bufferevent *bev, short what,void *ctx)
{
    auto task = (XComTask*)ctx;
    task->EventCB(what);
    
}

int XComTask::Read(void *data, int nSize)
{
    if (!bev_) {
        LOGERROR("bev not set");
        return 0;
    }

    int ret = bufferevent_read(bev_, data, nSize);
    return ret;
}

void XComTask::Close()
{
    if(bev_)
        bufferevent_free(bev_);
    bev_ = NULL;
    if(msg_.m_data)
        delete msg_.m_data;
    memset(&msg_, 0, sizeof(msg_));
    delete this;
}
bool  XComTask::Write(const void *data, int size)
{
    if (!bev_  || !data || size <= 0)return false;
    int re = bufferevent_write(bev_, data, size);
    if (re != 0)return false;
    return true;
}
bool XComTask::Write(const XMsg *msg)
{
    if (!bev_ || !msg || !msg->m_data || msg->m_size <= 0)return false;
    //1 写入消息头
    int re = bufferevent_write(bev_, msg, sizeof(XMsgHead));
    if (re != 0)return false;
    //2 写入消息内容
    re = bufferevent_write(bev_, msg->m_data, msg->m_size);
    if (re != 0)return false;
    return true;
}
//激活写入回调
void XComTask::BeginWrite()
{
    if (!bev_)return;
    bufferevent_trigger(bev_, EV_WRITE, 0);
}

void XComTask::EventCB(short what)
{
    cout << "SEventCB:" << what << endl;
    if (what & BEV_EVENT_CONNECTED)
    {
        cout << "BEV_EVENT_CONNECTED" << endl;
        //通知连接成功

        ConnectedCB();
    }

    ///退出要处理缓冲内容
    if (what & BEV_EVENT_ERROR || what & BEV_EVENT_TIMEOUT)
    {
        cout << "BEV_EVENT_ERROR or BEV_EVENT_TIMEOUT" << endl;
        Close();
    }
    if (what & BEV_EVENT_EOF)
    {
        cout << "BEV_EVENT_EOF" << endl;
        Close();
    }
}
bool XComTask::Init()
{
    //区分服务端还是客户端
    int comsock = this->sock();
    if (comsock <= 0)
        comsock = -1;
    ///用bufferevent 建立连接 
    /// 创建bufferevent上下文 -1自动创建socket
    bev_ = bufferevent_socket_new(base(), comsock, BEV_OPT_CLOSE_ON_FREE);
    if (!bev_)
    {
        cerr << "bufferevent_socket_new failed!" << endl;
        return false;
    }

    //设置回调函数
    bufferevent_setcb(bev_, SReadCB, SWriteCB, SEventCB, this);
    bufferevent_enable(bev_, EV_READ|EV_WRITE);

    timeval tv = { 10,0 };
    bufferevent_set_timeouts(bev_, &tv, &tv);

    //连接服务器
    if (server_ip_.empty())
    {
        return true;
    }
    sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(server_port_);
    evutil_inet_pton(AF_INET, server_ip_.c_str(), &sin.sin_addr.s_addr);
    int re = bufferevent_socket_connect(bev_, (sockaddr*)&sin, sizeof(sin));
    if (re != 0)
        return false;
    return true;
}

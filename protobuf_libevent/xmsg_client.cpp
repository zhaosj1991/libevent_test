#include "xmsg_client.h"

#include <thread>
#include <iostream>
#include <event2/event.h>
#include <event2/bufferevent.h>
#include <string.h>

#include "xmsg_comm.pb.h"
#include "xmsg_event.h"

using namespace std;
using namespace xmsg;

static void ReadCB(struct bufferevent *bev, void *ctx)
{
    cout << "client: Read CB" << endl << flush;

    auto ev = (XMsgEvent *)ctx;
    if (!ev->RecvMsg()) {
        delete ev;
        bufferevent_free(bev);
        return;
    }

    auto msg = ev->GetMsg();
    if (!msg) 
        return;
    
    XLoginRes res;
    res.ParseFromArray(msg->m_data, msg->m_size);
    cout << res.res() << "recv server token " << res.token() << endl;

    this_thread::sleep_for(chrono::seconds(1));
    XLoginReq req;
    static int nUserId = 0;
    string user("root");
    req.set_username((user + to_string(nUserId++)).c_str());
    req.set_password("123456");
    ev->SendMsg(MSG_LOGIN_REQ, &req);

    ev->Clear(); //清理，接收下一次消息
}

static void EventCB(struct bufferevent *bev, short what, void *ctx)
{
    std::cout << __FUNCTION__ << std::endl;
    auto ev = (XMsgEvent*)ctx;
    if ((what & BEV_EVENT_TIMEOUT) || (what & BEV_EVENT_ERROR) || (what & BEV_EVENT_EOF)) {
        std::cout << "BEV_EVENT_TIMEOUT BEV_EVENT_ERROR BEV_EVENT_EOF!" << std::endl;
        //读取缓冲中内容

        delete ev;
        
        //清理空间，关闭监听
        bufferevent_free(bev);
        return;
    }

    if (what & BEV_EVENT_CONNECTED) {
        cout << "BEV_EVENT_CONNECTED" << endl;
        // bufferevent_write(bev, "OK", 3);

        XLoginReq req;
        req.set_username("root");
        req.set_password("123456");
        ev->SendMsg(MSG_LOGIN_REQ, &req);
        
    }
}

void XMsgClient::Start()
{
    thread th(&XMsgClient::Main, this);
    th.detach();
}

void XMsgClient::Main()
{
    if (m_server_port <= 0) {
        cerr << "err port:  " << m_server_port << endl;
        return;
    }

    this_thread::sleep_for(chrono::microseconds(200));
    cout << "XMsgClient::Main begin" << endl;

    struct event_base *base = event_base_new();
    //连接服务器
    struct bufferevent *bev = bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE);

    sockaddr_in sin;
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(m_server_port);
    evutil_inet_pton(AF_INET, m_server_ip.c_str(), (char * )&sin.sin_addr);
    cout << "sin.sin_addr.s_addr: " << sin.sin_addr.s_addr << endl;
    // sin.sin_addr.s_addr = 0;

    //设置回调函数
    //添加监控事件设置内容权限参数
    bufferevent_enable(bev, EV_READ | EV_WRITE);
    timeval t1 = {30, 0};
    bufferevent_set_timeouts(bev, &t1, 0);

    auto ev = new XMsgEvent();
    ev->SetBev(bev);
    
    bufferevent_setcb(bev, ReadCB, 0, EventCB, ev);

    int ret = bufferevent_socket_connect(bev, (const sockaddr *)&sin, sizeof(sin));
    if (ret != 0) {
        cerr << "bufferevent_socket_connect failed" << endl;
        return ;
    }

    event_base_dispatch(base);
    event_base_free(base);

    cout << "XMsgClient::Main end" << endl;
}
#include "xmsg_client.h"

#include <thread>
#include <iostream>
#include <event2/event.h>
#include <event2/bufferevent.h>
#include <string.h>

using namespace std;

static void ReadCB(struct bufferevent *bev, void *ctx)
{
    cout << "client: Read CB" << endl << flush;
    char buf[1024] = {0};
    int len = bufferevent_read(bev, buf, sizeof(buf) - 1);
    std::cout << "client:" << buf << std::endl;
    //插入buffer链表
    bufferevent_write(bev, "OK", 3);
    this_thread::sleep_for(chrono::seconds(1));
}

static void EventCB(struct bufferevent *bev, short what, void *ctx)
{
    std::cout << __FUNCTION__ << std::endl;
    if ((what & BEV_EVENT_TIMEOUT) || (what & BEV_EVENT_ERROR) || (what & BEV_EVENT_EOF)) {
        std::cout << "BEV_EVENT_TIMEOUT BEV_EVENT_ERROR BEV_EVENT_EOF!" << std::endl;
        //读取缓冲中内容
        
        //清理空间，关闭监听
        bufferevent_free(bev);
        return;
    }

    if (what & BEV_EVENT_CONNECTED) {
        cout << "BEV_EVENT_CONNECTED" << endl;
        bufferevent_write(bev, "OK", 3);
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
    bufferevent_enable(bev, EV_READ | EV_WRITE);
    timeval t1 = {30, 0};
    bufferevent_set_timeouts(bev, &t1, 0);
    
    bufferevent_setcb(bev, ReadCB, 0, EventCB, base);

    int ret = bufferevent_socket_connect(bev, (const sockaddr *)&sin, sizeof(sin));
    if (ret != 0) {
        cerr << "bufferevent_socket_connect failed" << endl;
        return ;
    }

    event_base_dispatch(base);
    event_base_free(base);

    cout << "XMsgClient::Main end" << endl;
}
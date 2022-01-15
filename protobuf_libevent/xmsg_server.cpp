#include <iostream>
#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/listener.h>

#include <string.h>

#include "xmsg_server.h"
#include "xmsg_event.h"
#include "xmsg_comm.pb.h"

using namespace std;
using namespace xmsg;

void ReadCB(struct bufferevent *bev, void *ctx)
{
    cout << "server: Read CB" << endl << flush;
    auto ev = (XMsgEvent *)ctx;
    if (!ev->RecvMsg()) {
        delete ev;
        bufferevent_free(bev);
        return;
    }

    auto msg = ev->GetMsg();
    if (!msg) 
        return; 
    //反序列化
    XLoginReq req;
    req.ParseFromArray(msg->m_data, msg->m_size);
    cout << "Recv username = " << req.username() << ", passwd = " << req.password() << endl;

    //返回消息
    XLoginRes res;
    res.set_res(XLoginRes::OK);
    string token = req.username();
    token += "sign";
    res.set_token(token);
    ev->SendMsg(MSG_LOGIN_RES, &res);
    ev->Clear();

    // char buf[1024] = {0};
    // int len = bufferevent_read(bev, buf, sizeof(buf) - 1);
    // std::cout << "len: " << len << std::endl;
    // std::cout << "server: " << buf << std::endl;
    // //插入buffer链表
    // bufferevent_write(bev, "OK", 3);
}

void EventCB(struct bufferevent *bev, short what, void *ctx)
{
    std::cout << __FUNCTION__ << std::endl;

    auto ev = (XMsgEvent *)ctx;
    if ((what & BEV_EVENT_TIMEOUT) || (what & BEV_EVENT_ERROR) || (what & BEV_EVENT_EOF)) {
        std::cout << "BEV_EVENT_TIMEOUT BEV_EVENT_ERROR BEV_EVENT_EOF!" << std::endl;
        //读取缓冲中内容
        
        delete ev;
        //清理空间，关闭监听
        bufferevent_free(bev);
    } 
}

static void listener_cb(struct evconnlistener *listener, evutil_socket_t client_sock, 
                        struct sockaddr *client_addr, int socklen, void *arg)
{
    std::cout << "listener_cb" << std::endl;

    char ip[16] = {0};
    evutil_inet_ntop(AF_INET, &((struct sockaddr_in *)client_addr)->sin_addr, ip, sizeof(ip));
    std::cout << "client ip is " << ip << std::endl;

    //创建event对象(read和write)
    event_base *base = (event_base *)arg;
    bufferevent *bev = bufferevent_socket_new(base, client_sock, BEV_OPT_CLOSE_ON_FREE);
    if (!bev) {
        std::cerr << "bufferevent_socket_new failed!" << std::endl;
        return;
    }
    
    //添加监控事件，设置内部权限参数
    bufferevent_enable(bev, EV_READ | EV_WRITE);
    timeval t1 = {30, 0};
    bufferevent_set_timeouts(bev, &t1, 0);

    auto ev = new XMsgEvent();
    ev->SetBev(bev);
    
    bufferevent_setcb(bev, ReadCB, 0, EventCB, ev);
    //设置回调函数
    
}

void XMsgServer::Init(int server_port)
{
    struct event_base *base = event_base_new();
    if (!base) {
        cout << "event_base_new failed!" << endl;
        return;
    }

    sockaddr_in sin;
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = 0;
    sin.sin_port = htons(server_port);

    struct evconnlistener *listener = evconnlistener_new_bind(base, listener_cb, base, LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE, 
                            10, (const sockaddr *)&sin, sizeof(sin));
    if (!listener) {
        cerr << "evconnlistener_new_bind failed" << endl;
        return;
    }

    event_base_dispatch(base);
    evconnlistener_free(listener);
    event_base_free(base);
}

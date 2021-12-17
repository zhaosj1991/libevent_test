#include <event2/event.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

#ifndef _WIN32
#include <signal.h>
#include <errno.h>
#endif

void ReadCB(struct bufferevent *bev, void *ctx)
{
    char buf[1024] = {0};
    int len = bufferevent_read(bev, buf, sizeof(buf) - 1);
    std::cout << buf << std::endl;
    //插入buffer链表
    bufferevent_write(bev, "OK", 3);
}

void WriteCB(struct bufferevent *bev, void *ctx)
{
    std::cout << __FUNCTION__ << std::endl;
}

void EventCB(struct bufferevent *bev, short what, void *ctx)
{
    std::cout << __FUNCTION__ << std::endl;
    if (what & BEV_EVENT_TIMEOUT && what && BEV_EVENT_READING) {
        std::cout << "BEV_EVENT_READING time out!" << std::endl;
        //读取缓冲中内容
        
        //清理空间，关闭监听
        bufferevent_free(bev);
    } 
    else if (what & BEV_EVENT_TIMEOUT && what && BEV_EVENT_WRITING) {
        std::cout << "BEV_EVENT_WRITE time out!" << std::endl;
        //读取缓冲中内容
        
        //清理空间，关闭监听
        bufferevent_free(bev);
    }
    //异常错误
    else if (what & BEV_ERROR) {
        //清理空间，关闭监听
        bufferevent_free(bev);
    }
    //连接错误
    else if(what & BEV_EVENT_EOF) {
        //清理空间，关闭监听
        bufferevent_free(bev);
    }
}

void ListenCB(struct evconnlistener *evc, evutil_socket_t client_sock, struct sockaddr *client_addr, int socklen, void *arg)
{
    std::cout << "ListenCB" << std::endl;

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
    timeval t1 = {5, 0};
    bufferevent_set_timeouts(bev, &t1, 0);
    
    //设置回调函数
    bufferevent_setcb(bev, ReadCB, WriteCB, EventCB, base);
    
}

int main(int argc, char const *argv[])
{
    int server_port = 12345;
    if (argc > 1) {
        server_port = atoi(argv[1]);
    }

#ifdef _WIN32

#else
    //使用断开连接socket，会发出此信号，造成程序退出
    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) {
        std::cerr << "signal error" << std::endl;
        return 0;
    }
#endif

    std::cout << "test libevent!" << std::endl;

    event_base *base = event_base_new();
    if (!base) {
        std::cout << "event_base_new failed!" << std::endl;
        return 0;
    }    

    //绑定端口
    sockaddr_in sin;
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(server_port);

    struct evconnlistener *evc = evconnlistener_new_bind(base, ListenCB, base, LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE, 10,
        (sockaddr *)&sin, sizeof(sin));

    //事件主循环，如果没有注册事件则退出
    event_base_dispatch(base);
    evconnlistener_free(evc);
    event_base_free(base);
    
    return 0;
}

#include <event2/event.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

#ifndef _WIN32
#include <signal.h>
#include <errno.h>
#endif

void ListenCB(evutil_socket_t sock, short what, void *arg) 
{
    std::cout << "ListenCB" << std::endl;

    if (!(what & EV_READ)) {
        std::cout << "not read" << std::endl;
        return;
    }

    sockaddr_in sin;
    bzero(&sin, sizeof(sin));
    socklen_t size = sizeof(sin);
    evutil_socket_t client_sock = accept(sock, (sockaddr *)&sin, &size);
    if (client_sock <= 0) {
        return;
    }

    char ip[16] = {0};
    evutil_inet_ntop(AF_INET, &sin.sin_addr, ip, sizeof(ip));
    std::cout << "client ip is " << ip << std::endl;
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

    //2创建socket 绑定端口
    evutil_socket_t sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "socket error" << strerror(errno) << std::endl;
        return 0;
    }
    
    //设置地址复用和非阻塞
    evutil_make_socket_nonblocking(sock);
    evutil_make_listen_socket_reuseable(sock);
    
    sockaddr_in sin;
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(server_port);
    int re = ::bind(sock, (sockaddr *)&sin, sizeof(sin));
    if (re == -1) {
        std::cout << "bind error" << strerror(errno) << std::endl;
        return 0;
    }

    listen(sock, 10);

    //3 注册socket的监听事件回调函数 EV_PERIST持久化
    //event_self_cbarg()传递当前创建的event对象
    event *ev = event_new(base, sock, EV_READ | EV_PERSIST, ListenCB, event_self_cbarg());

    //开始监听事件  0->超时时间
    event_add(ev, 0);
    
    //事件主循环，如果没有注册事件则退出
    event_base_dispatch(base);

    evutil_closesocket(sock);
    event_del(ev);
    event_free(ev);
    event_base_free(base);
    
    return 0;
}

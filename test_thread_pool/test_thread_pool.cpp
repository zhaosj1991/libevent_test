#include <event2/event.h>
#include <event2/listener.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Task.h"
#include "XThreadPool.h"
#include "FtpServerCmd.h"

#ifndef _WIN32
#include <signal.h>
#include <errno.h>
#endif

void ListenCB(struct evconnlistener *evc, evutil_socket_t client_sock, struct sockaddr *client_addr, int socklen, void *arg)
{
    std::cout << "ListenCB" << std::endl;

    CTask *task = new CFtpServerCmd();
    task->m_sock = client_sock;

    XThreadPool::Get()->Dispatch(task);
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

    //1 初始化线程池
    XThreadPool::Get()->Init(10);

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

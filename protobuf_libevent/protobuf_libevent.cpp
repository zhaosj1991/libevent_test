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

#include "xmsg_server.h"
#include "xmsg_client.h"

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

    XMsgClient client;
    client.SetServerPort(server_port);
    client.Start();

    XMsgServer server;
    server.Init(server_port);
    
    return 0;
}

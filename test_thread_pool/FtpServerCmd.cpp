#include "FtpServerCmd.h"
#include <iostream>
#include <event2/event.h>
#include <event2/bufferevent.h>

static void ReadCB(bufferevent *bev, void *arg)
{
    char data[1024] = {0};
    for (;;) {
        int len = bufferevent_read(bev, data, sizeof(data) - 1);
        if (len <= 0) break;
        data[len] = '\0';
        std::cout << data << std::flush;
    }
}

CFtpServerCmd::CFtpServerCmd(/* args */)
{
}

CFtpServerCmd::~CFtpServerCmd()
{
}

bool CFtpServerCmd::Init()
{
    std::cout << "CFtpServerCmd::Init()" << std::endl;

    //监听socketbufferevent
    struct bufferevent *bev = bufferevent_socket_new(m_base, m_sock, BEV_OPT_CLOSE_ON_FREE);
    bufferevent_setcb(bev, ReadCB, 0, 0, this);
    bufferevent_enable(bev, EV_READ | EV_WRITE);


    return true;
}
#include <iostream>
#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/listener.h>
#include <cstring>
#include <arpa/inet.h>

using namespace std;

#define PORT 12345

char buf[1024] = {0};

void readcb(struct bufferevent *bev, void *ctx)
{
    memset(buf, 0, 1024);
    cout << "server readcb: ";
    int len = bufferevent_read(bev, buf, 1024);
    cout << "before" << buf << endl;
    memcpy(buf + len, " ack", sizeof(" ack"));
    cout << "after" << buf << endl;
    bufferevent_write(bev, buf, 1024);
}

// void writecb(struct bufferevent *bev, void *ctx)
// {
//     cout << "writecb " << endl;
// }

void listener_cb(struct evconnlistener *listener, evutil_socket_t client_fd, struct sockaddr *sk, int socklen, void *ctx)
{
    struct event_base *base = (struct event_base *)ctx;
    struct bufferevent *bev = bufferevent_socket_new(base, client_fd, BEV_OPT_CLOSE_ON_FREE);
    bufferevent_setcb(bev, readcb, nullptr, nullptr, base);
    bufferevent_enable(bev, EV_WRITE | EV_READ);
}

int main(int argc, char const *argv[])
{
    struct event_base *base = event_base_new();
    sockaddr_in sin;
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    int fd = socket(AF_INET, SOCK_STREAM, 0);
   
    struct evconnlistener *listener = evconnlistener_new_bind(base, listener_cb, base, 
        LEV_OPT_REUSEABLE_PORT | LEV_OPT_CLOSE_ON_FREE, 5, (sockaddr *)&sin, sizeof(sin));

    event_base_dispatch(base);
    
    return 0;
}

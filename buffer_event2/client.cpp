#include <iostream>
#include <event2/event.h>
#include <event2/bufferevent.h>
#include <cstring>
#include <arpa/inet.h>
#include <thread>
#include <string>
#include <cstdio>

using namespace std;

#define PORT 12345
static int i = 0;

void write_cb(struct bufferevent *bev, void *ctx)
{
    cout << "write_cb" << endl;
    i++;
    string send = "1111" + to_string(i);
    // cout << "please input: " << endl;
    // cin >> send;
    bufferevent_write(bev, send.data(), send.size());
    bufferevent_disable(bev, EV_WRITE);
}

void read_cb(struct bufferevent *bev, void *ctx)
{
    char buf[1024] = {0};
    bufferevent_read(bev, buf, 1024);
    cout << "read_cb: " << buf << endl;

    i++;
    string send;
    cout << "please input: " << endl;
    cin >> send;
    // string send = "1111" + to_string(i);
    bufferevent_write(bev, send.data(), send.size());
    // bufferevent_write(bev, buf, 1024);
    // this_thread::sleep_for(chrono::milliseconds(1000));
}

void event_cb(struct bufferevent *bev, short what, void *ctx)
{
    // cout << "event_cb: " <<  what << endl;
    printf("event_cb: 0x%x\n", what);
    struct event_base *base = (struct event_base *)ctx;
    int ret = bufferevent_enable(bev, EV_READ | EV_WRITE);
    cout << "bufferevent_enable ret : " << ret << endl;
    bufferevent_write(bev, "let being", sizeof("let being"));
}

int main(int argc, char const *argv[])
{
    struct event_base *base = event_base_new();
    sockaddr_in sin;
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    bufferevent *bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
    bufferevent_setcb(bev, read_cb, nullptr, event_cb, base);

    if (0 != bufferevent_socket_connect(bev, (sockaddr *)&sin, sizeof(sin))) {
        cout << "bufferevent_socket_connect failed" << endl;
    }

    event_base_dispatch(base);
    
    return 0;
}

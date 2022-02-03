#include <iostream>
#include "xtest_client.h"

using namespace std;

int main(int argc, char const *argv[])
{
    XTestClient *client = new XTestClient();
    client->set_server_ip("127.0.0.1");
    client->set_port(12345);
    client->StartConnect();
    XThreadPool::Wait();
    
    return 0;
}

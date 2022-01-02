#include <string>

class XMsgClient
{
private:
    /* data */
public:
//启动测试线程，发送数据给服务端（延时启动）
    void Start();
    void Main();
    void SetServerPort(int port) {
        m_server_port = port;
    }

    void SetServerIP(std::string ip) {
        m_server_ip = ip;
    }

private:
    int m_server_port = 0;
    std::string m_server_ip = "127.0.0.1";
    // std::string m_server_ip = "0.0.0.0";
};


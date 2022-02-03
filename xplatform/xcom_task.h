#ifndef XCOM_TASK_H
#define XCOM_TASK_H
#include "xtask.h"
#include "xmsg.h"
#include <string>
class XCOM_API XComTask : public XTask
{
public:
    ///初始化bufferevent，客户端建立连接
    virtual bool Init();
    virtual void Close();

    int Read(void *data, int nSize);

    void set_server_ip(std::string ip) { this->server_ip_ = ip; }
    void set_port(int port) { this->server_port_ = port; }

    ///事件回调函数
    virtual void EventCB(short what);

    //激活写入回调
    virtual void BeginWrite();

    //发送消息
    virtual bool Write(const XMsg *msg);
    virtual bool Write(const void *data, int size);

    //连接成功的消息回调，由业务类重载
    virtual void ConnectedCB() {};

    //接收到消息的回调，由业务类重载
    virtual void ReadCB() = 0;

    ///写入数据回调函数
    virtual void WriteCB() {};

    void set_is_recv_msg(bool isrecv) { this->is_recv_msg_ = isrecv; }
protected:

    //读取缓存
    char read_buf_[4096] = { 0 };
private:
    /// 服务器IP
    std::string server_ip_ = "";

    ///服务器端口
    int server_port_ = 0;

    struct bufferevent *bev_ = 0;

    //数据包缓存
    XMsg msg_;

    //是否接收消息，接收的消息会调用 void ReadCB(const XMsg *msg)
    //不接收消息调用 void ReadCB(void *data, int size)
    bool is_recv_msg_ = true;
};

#endif
#pragma once

#include "xmsg_type.pb.h"
#include "xmsg.h"

class XMsgEvent
{
public:
    //接收数据包
    //1. 正确接收到消息 
    //2. 消息接受不完整，等待下一次接收
    //3. 消息接收出错（退出清理空间）
    // @return 1 2 返回true； 3返回false；
    bool RecvMsg();

    //清理缓存，用于接收下一次消息
    void Clear();

    XMsg *GetMsg();

    //发送消息，包含头部（自动创建）
    //@type 消息类型
    //@message 消息内容
    void SendMsg(xmsg::MsgType type, const google::protobuf::Message *message);

    void SetBev(struct bufferevent *bev) {
        m_bev = bev;
    }

private:
    struct bufferevent *m_bev = nullptr;
    XMsg m_head; //消息头
    XMsg m_msg; //消息内容
};

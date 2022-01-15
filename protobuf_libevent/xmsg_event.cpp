#include <string>
#include <iostream>

#include "xmsg_event.h"
#include "event2/bufferevent.h"
#include "xmsg_comm.pb.h"

using namespace xmsg;
using namespace google;
using namespace protobuf;
using namespace std;

//接收数据包
//1. 正确接收到消息 
//2. 消息接受不完整，等待下一次接收
//3. 消息接收出错（退出清理空间）
// @return 1 2 返回true； 3返回false；
bool XMsgEvent::RecvMsg()
{
    if (!m_bev) {
        cerr << "XMsgEvent::RecvMsg failed: bev is null" << endl;
        return false;
    }

    //解包

    //接收消息头
    if (!m_head.m_size) {
        //1 消息头大小
        int nLen = bufferevent_read(m_bev, &m_head.m_size, sizeof(m_head.m_size));
        if (nLen <= 0 || m_head.m_size <= 0) {
            return false;
        }

        //分配消息头空间，读取消息头（鉴权，消息大小）
        if (!m_head.Alloc(m_head.m_size)) {
            cerr << "head.Alloc failed" << endl;
            return false;
        }
    }

    //2 开始接收消息头（鉴权，消息大小）
    if (!m_head.Recved()) {
        //第二次进来，从上次的位置开始读
        int nLen = bufferevent_read(m_bev, m_head.m_data + m_head.m_recv_size, 
            m_head.m_size - m_head.m_recv_size);
        
        if (nLen <= 0) {
            return true;    
        }

        m_head.m_recv_size += nLen;

        if (!m_head.Recved())
            return true;

        //完整的头部数据接收完成
        //反序列化
        XMsgHead pbHead;
        if (!pbHead.ParseFromArray(m_head.m_data, m_head.m_recv_size)) {
            cerr << "pbHead.ParseFromArray failed!" << endl;
            return false;
        }

        //鉴权

        //消息内容大小
        //分配消息内容空间
        if (!m_msg.Alloc(pbHead.msg_size())) {
            cerr << "m_msg.Alloc failed" << endl;
            return false;
        }
    }

    //3 开始接收消息内容
    if (!m_msg.Recved()) {
        //第二次进来，从上次的位置开始读
        int nLen = bufferevent_read(m_bev, m_msg.m_data + m_msg.m_recv_size, 
            m_msg.m_size - m_msg.m_recv_size);
        
        if (nLen <= 0) {
            return true;    
        }

        m_msg.m_recv_size += nLen;

        if (!m_msg.Recved())
            return true;

        //消息接收完成 
        cout << "m_msg.Recved() success!" << endl;
    }

    return true;
}

void XMsgEvent::SendMsg(xmsg::MsgType type, const google::protobuf::Message *message)
{
    if (!m_bev || !message) {
        return;
    }

    XMsgHead head;
    head.set_msg_type(type);
    
    //消息内容序列化
    string msg_str = message->SerializeAsString();
    int msg_size = msg_str.size();
    head.set_msg_size(msg_size);

    //消息头序列化
    string head_str = head.SerializeAsString();
    int head_size = head_str.size();

    //1发送消息头大小 4字节 暂时不考虑字节序问题
    bufferevent_write(m_bev, &head_size, sizeof(head_size));

    //2 发送消息头（pb序列化） XMsgHead（设置消息内容的大小）
    bufferevent_write(m_bev, head_str.data(), head_str.size());

    //3 发送消息内容 （pb序列化） 业务proto
    bufferevent_write(m_bev, msg_str.data(), msg_str.size());
}

XMsg *XMsgEvent::GetMsg()
{
    if (m_msg.Recved()) {
        return &m_msg;
    }

    return nullptr;
}

void XMsgEvent::Clear()
{
    m_head.Clear();
    m_msg.Clear();
}
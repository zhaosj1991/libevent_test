#pragma once
#include <map>

#include "xmsg_type.pb.h"
#include "xmsg_event.h"

class XServerEvent: public XMsgEvent
{
private:
    /* data */
public:

    //初始化会调函数
    static void Init();

    //接收登录反馈消息
    void LoginReq(const char *pData, int nSize);

    typedef void (XServerEvent::*MsgCBFunc)(const char *pData, int nSize);

    /**
     * @description: 注册消息回调函数
     * @param {MsgType} type 消息类型
     * @param {MsgCBFunc} func 消息回调
     * @return {*}
     */    
    static void RegCB(xmsg::MsgType type, MsgCBFunc func)
    {
        m_calls[type] = func;
    }

    /**
     * @description: 通过类型和成员函数指针调用函数
     * @param {MsgType} type 消息类型
     * @param {char} *data  消息数据
     * @param {int} size 消息大小
     * @return {*}
     */    
    void CallFunc(xmsg::MsgType type, const char *data, int size)
    {
        if (m_calls.find(type) != m_calls.end()) {
            //通过成员函数指针调用
            // (this->*m_calls[type])(data, size);
            (this->*m_calls[type])(data, size);
        }
    }

private:
    static std::map<xmsg::MsgType, MsgCBFunc> m_calls;

    
};

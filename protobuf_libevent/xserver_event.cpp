#include <map>
#include <iostream>
#include <thread>
#include "xserver_event.h"
#include "xmsg_comm.pb.h"

using namespace std;
using namespace xmsg;

std::map<xmsg::MsgType, XServerEvent::MsgCBFunc> XServerEvent::m_calls;

//初始化会调函数
void XServerEvent::Init()
{
    RegCB(MSG_LOGIN_REQ, &XServerEvent::LoginReq);
}

//接收登录反馈消息
void XServerEvent::LoginReq(const char *pData, int nSize)
{
    cout << "LoginReq " << nSize << endl;
    //反序列化
    XLoginReq req;
    req.ParseFromArray(pData, nSize);
    cout << "Recv username = " << req.username() << ", passwd = " << req.password() << endl;

    //返回消息
    XLoginRes res;
    res.set_res(XLoginRes::OK);
    string token = req.username();
    token += "sign";
    res.set_token(token);
    SendMsg(MSG_LOGIN_RES, &res);
    Clear();
}
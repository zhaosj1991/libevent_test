#include <map>
#include <iostream>
#include <thread>
#include "xclient_event.h"
#include "xmsg_comm.pb.h"

using namespace std;
using namespace xmsg;

std::map<xmsg::MsgType, XClientEvent::MsgCBFunc> XClientEvent::m_calls;

//初始化会调函数
void XClientEvent::Init()
{
    RegCB(MSG_LOGIN_RES, &XClientEvent::LoginRes);
}

//接收登录反馈消息
void XClientEvent::LoginRes(const char *pData, int nSize)
{
    cout << "LoginRes " << nSize << endl;
    XLoginRes res;
    res.ParseFromArray(pData, nSize);
    cout << res.res() << "recv server token " << res.token() << endl;

    XLoginReq req;
    static int nUserId = 0;
    string user("root");
    req.set_username((user + to_string(nUserId++)).c_str());
    req.set_password("123456");
    SendMsg(MSG_LOGIN_REQ, &req);
    Clear(); //清理，接收下一次消息
    this_thread::sleep_for(chrono::seconds(1));
}
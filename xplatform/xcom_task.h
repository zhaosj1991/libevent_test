#ifndef XCOM_TASK_H
#define XCOM_TASK_H
#include "xtask.h"
#include "xmsg.h"
#include <string>
class XCOM_API XComTask : public XTask
{
public:
    ///��ʼ��bufferevent���ͻ��˽�������
    virtual bool Init();
    virtual void Close();

    int Read(void *data, int nSize);

    void set_server_ip(std::string ip) { this->server_ip_ = ip; }
    void set_port(int port) { this->server_port_ = port; }

    ///�¼��ص�����
    virtual void EventCB(short what);

    //����д��ص�
    virtual void BeginWrite();

    //������Ϣ
    virtual bool Write(const XMsg *msg);
    virtual bool Write(const void *data, int size);

    //���ӳɹ�����Ϣ�ص�����ҵ��������
    virtual void ConnectedCB() {};

    //���յ���Ϣ�Ļص�����ҵ��������
    virtual void ReadCB() = 0;

    ///д�����ݻص�����
    virtual void WriteCB() {};

    void set_is_recv_msg(bool isrecv) { this->is_recv_msg_ = isrecv; }
protected:

    //��ȡ����
    char read_buf_[4096] = { 0 };
private:
    /// ������IP
    std::string server_ip_ = "";

    ///�������˿�
    int server_port_ = 0;

    struct bufferevent *bev_ = 0;

    //���ݰ�����
    XMsg msg_;

    //�Ƿ������Ϣ�����յ���Ϣ����� void ReadCB(const XMsg *msg)
    //��������Ϣ���� void ReadCB(void *data, int size)
    bool is_recv_msg_ = true;
};

#endif
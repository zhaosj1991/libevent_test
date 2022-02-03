#ifndef XTHREAD_H
#define XTHREAD_H

#include <list>
#include <mutex>
#ifdef _WIN32
#ifdef XCOM_EXPORTS
#define XCOM_API __declspec(dllexport)
#else
#define XCOM_API __declspec(dllimport)
#endif
#else
#define XCOM_API
#endif
class XTask;
class XCOM_API XThread
{
public:
    static XThread* Create();
    
	//�����߳�
    virtual  void Start() = 0;

	//��װ�̣߳���ʼ��event_base�͹ܵ������¼����ڼ���
    virtual  bool Setup() = 0;

	//�յ����̷߳����ļ�����Ϣ���̳߳صķַ���
    virtual  void Notify(int fd, short which) = 0;

	//�̼߳���
    virtual  void Activate() = 0;

	//��Ӵ��������һ���߳�ͬʱ���Դ��������񣬹���һ��event_base
	virtual void AddTask(XTask *t) = 0;
	
	~XThread();

	//�̱߳��
	int id = 0;

    //�˳��߳�
    void Exit()
    {
        is_exit_ = true;
    }
protected:
    XThread();
    bool is_exit_ = false;

};

#endif

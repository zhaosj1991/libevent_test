#ifndef XTHREAD_POOL_H
#define XTHREAD_POOL_H

#ifdef _WIN32
#ifdef XCOM_EXPORTS
#define XCOM_API __declspec(dllexport)
#else
#define XCOM_API __declspec(dllimport)
#endif
#else
#define XCOM_API
#endif
#include <vector>
class XThread;
class XTask;
class XCOM_API XThreadPool
{
public:
    ///////////////////////////////////////////////////////////////////////////
    /// @brief ��ȡXThreadPool�ľ�̬���� ����̬������
    /// @return XThreadPool ��̬�����ָ��
    ///////////////////////////////////////////////////////////////////////////
	//static XThreadPool* Get()
	//{
	//	static XThreadPool p;
	//	return &p;
	//}
    ///////////////////////////////////////////////////////////////////////////
    /// @brief ��ʼ�������̲߳������̣߳�������event_base ,�����߳��п�ʼ������Ϣ
	virtual void Init(int thread_count) = 0;

    ///////////////////////////////////////////////////////////////////////////
    /// @brief �ַ������߳���ִ�У������task��Init���������ʼ��
    ///        �������ѯ�ַ����̳߳��еĸ����߳�
    /// @param task ����ӿڶ���XTask��Ҫ�û��Լ��̳в�����Init����
	virtual void Dispatch(XTask *task) = 0;
    
    //////////////////////////////////////////////////////
    ///�˳����е��߳�
    static void ExitAllThread();

    ///���� �ȴ�ExitAllThread
    static void Wait();

};

class XCOM_API XThreadPoolFactory
{
public:
    //�����̳߳ض���
    static XThreadPool *Create();
};

#endif
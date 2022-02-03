#include "xservice_client.h"

void XServiceClient::StartConnect()
{
    m_thread_pool->Init(1);
    m_thread_pool->Dispatch(this);
}

XServiceClient::XServiceClient()
{
    m_thread_pool = XThreadPoolFactory::Create();
}

XServiceClient::~XServiceClient()
{
    delete m_thread_pool;
    m_thread_pool = nullptr;
}
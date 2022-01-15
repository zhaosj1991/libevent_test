#pragma once

#include <string.h>

//头部消息的最大字节数
#define MAX_MSG_SIZE 8192

//所有的函数做内联

class XMsg
{
public:

    //数据大小
    int m_size = 0;

    //数据存放（protobuf的序列化后的数据
    char *m_data = nullptr;

    //已经接受的数据大小
    int m_recv_size = 0;

    bool Alloc(int s)
    {
        if (s <= 0 || s > MAX_MSG_SIZE) {
            return false;
        }
        
        if (m_data) {
            delete[] m_data;
            m_data = nullptr;
        }

        char *data = new char[s];
        if (!data)
            return false;

        m_size = s;
        m_recv_size = 0;
        m_data = data;

        return true;
        
    }

    //判断数据是否接收完成
    bool Recved()
    {
        if (m_size <= 0) {
            return false;
        }
        return (m_recv_size == m_size);
    }

    void Clear()
    {
        if (m_data)
        {
            delete[] m_data;
            m_data = nullptr;
        }

        memset(this, 0, sizeof(XMsg));
    }
    
};


#pragma once

class CTask
{
public:
    virtual bool Init() = 0;
   
public:
    struct event_base *m_base = 0;
    int m_sock = 0;
    int m_threadId = 0;
};

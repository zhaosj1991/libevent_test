#pragma once

#include "Task.h"

class CFtpServerCmd :public CTask
{
private:
    /* data */
public:
    CFtpServerCmd(/* args */);
    ~CFtpServerCmd();

    virtual bool Init();
};



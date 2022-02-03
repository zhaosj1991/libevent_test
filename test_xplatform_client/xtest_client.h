#pragma once

#include "../xplatform/xservice_client.h"

class XTestClient: public XServiceClient
{
private:
    /* data */
public:
    XTestClient(/* args */);
    ~XTestClient();

    virtual void ReadCB() override;
    virtual void ConnectedCB() override;
};


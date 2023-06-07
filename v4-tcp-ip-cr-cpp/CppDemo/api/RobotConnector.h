#pragma once
#include "DobotClient.h"

namespace Dobot
{
    class CRobotConnector : public CDobotClient
    {
    public:
        CRobotConnector();
        virtual ~CRobotConnector();
		
    protected:
        void OnConnected() override;
        void OnDisconnected() override;
    };
}

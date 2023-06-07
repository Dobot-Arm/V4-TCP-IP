#include "Dashboard.h"
#include <sstream>

namespace Dobot
{
    CDashboard::CDashboard(CDobotClient* pDobotClient):m_pDobotClient(pDobotClient){}
    CDashboard::~CDashboard() {}

    std::string CDashboard::ClearError()
    {
        if (!m_pDobotClient->IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "ClearError()";
        if (!m_pDobotClient->SendData(str))
        {
            return str + ":send error";
        }

        return m_pDobotClient->WaitReply(5000);
    }

    std::string CDashboard::PowerOn()
    {
        if (!m_pDobotClient->IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "PowerOn()";
        if (!m_pDobotClient->SendData(str))
        {
            return str + ":send error";
        }

        return m_pDobotClient->WaitReply(15000);
    }

    std::string CDashboard::EmergencyStop(bool bIsStop)
    {
        if (!m_pDobotClient->IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "EmergencyStop(" << (bIsStop ? 1 : 0) << ")";
        std::string str = oss.str();
        if (!m_pDobotClient->SendData(str))
        {
            return str + ":send error";
        }

        return m_pDobotClient->WaitReply(15000);
    }

    std::string CDashboard::EnableRobot()
    {
        if (!m_pDobotClient->IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "EnableRobot()";
        if (!m_pDobotClient->SendData(str))
        {
            return str + ":send error";
        }

        return m_pDobotClient->WaitReply(20000);
    }

    std::string CDashboard::DisableRobot()
    {
        if (!m_pDobotClient->IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "DisableRobot()";
        if (!m_pDobotClient->SendData(str))
        {
            return str + ":send error";
        }

        return m_pDobotClient->WaitReply(20000);
    }

    std::string CDashboard::StopRobot()
    {
        if (!m_pDobotClient->IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "StopRobot()";
        if (!m_pDobotClient->SendData(str))
        {
            return str + ":send error";
        }

        return m_pDobotClient->WaitReply(20000);
    }

    std::string CDashboard::SpeedFactor(int ratio)
    {
        if (!m_pDobotClient->IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "SpeedFactor(" << ratio << ")";
        std::string str = oss.str();
        if (!m_pDobotClient->SendData(str))
        {
            return str + ":send error";
        }

        return m_pDobotClient->WaitReply(5000);
    }

    std::string CDashboard::DigitalOutputs(int index, bool status, int mstime)
    {
        if (!m_pDobotClient->IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "DO(" << index << "," << (status ? 1 : 0) <<","<<mstime<< ")";
        std::string str = oss.str();
        if (!m_pDobotClient->SendData(str))
        {
            return str + ":send error";
        }

        return m_pDobotClient->WaitReply(5000);
    }

    std::string CDashboard::ToolDO(int index, bool status)
    {
        if (!m_pDobotClient->IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "ToolDO(" << index << "," << (status ? 1 : 0) << ")";
        std::string str = oss.str();
        if (!m_pDobotClient->SendData(str))
        {
            return str + ":send error";
        }

        return m_pDobotClient->WaitReply(5000);
    }

    std::string CDashboard::GetErrorID()
    {
        if (!m_pDobotClient->IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetErrorID()";
        if (!m_pDobotClient->SendData(str))
        {
            return str + ":send error";
        }

        return m_pDobotClient->WaitReply(5000);
    }
}

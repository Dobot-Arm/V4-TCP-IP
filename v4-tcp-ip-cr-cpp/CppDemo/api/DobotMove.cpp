#include "DobotMove.h"
#include <sstream>

namespace Dobot
{
    CDobotMove::CDobotMove(CDobotClient* pDobotClient):m_pDobotClient(pDobotClient) {}
    CDobotMove::~CDobotMove() {}

    std::string CDobotMove::MoveJog(std::string s)
    {
        if (!m_pDobotClient->IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str;
        if (s.empty())
        {
            str = "MoveJog()";
        }
        else
        {
            str = "MoveJog(" + s + ")";
        }
        if (!m_pDobotClient->SendData(str))
        {
            return str + ":send error";
        }

        return m_pDobotClient->WaitReply(5000);
    }

    std::string CDobotMove::StopMoveJog()
    {
        return MoveJog("");
    }

    std::string CDobotMove::MovJ(const CDescartesPoint& pt)
    {
        if (!m_pDobotClient->IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "MovJ(pose={" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz<< "})";
        std::string str = oss.str();
        if (!m_pDobotClient->SendData(str))
        {
            return str + ":send error";
        }

        return m_pDobotClient->WaitReply(5000);
    }

    std::string CDobotMove::MovL(const CDescartesPoint& pt)
    {
        if (!m_pDobotClient->IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "MovL(pose={" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << "})";
        std::string str = oss.str();
        if (!m_pDobotClient->SendData(str))
        {
            return str + ":send error";
        }

        return m_pDobotClient->WaitReply(5000);
    }

    std::string CDobotMove::JointMovJ(const CJointPoint& pt)
    {
        if (!m_pDobotClient->IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "MovJ(joint={" << pt.j1 << ',' << pt.j2 << ',' << pt.j3 << ',' << pt.j4 << ',' << pt.j5 << ',' << pt.j6 << "})";
        std::string str = oss.str();
        if (!m_pDobotClient->SendData(str))
        {
            return str + ":send error";
        }

        return m_pDobotClient->WaitReply(5000);
    }
}

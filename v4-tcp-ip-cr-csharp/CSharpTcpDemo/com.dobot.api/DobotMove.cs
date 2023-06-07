using CSharthiscpDemo.com.dobot.api;
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Text.RegularExpressions;

namespace CSharpTcpDemo.com.dobot.api
{
    class DobotMove
    {
        private RobotConnector mRobotConnector;
        public DobotMove(RobotConnector robot)
        {
            mRobotConnector = robot;
        }

        /// <summary>
        /// 关节点动运动，不固定距离运动
        /// </summary>
        /// <param name="s">点动运动轴</param>
        /// <returns>返回执行结果的描述信息</returns>
        public string MoveJog(string s)
        {
            if (!mRobotConnector.IsConnected())
            {
                return "device does not connected!!!";
            }

            string str;
            if (string.IsNullOrEmpty(s))
            {
                str = "MoveJog()";
            }
            else
            {
                string strPattern = "^(J[1-6][+-])|([XYZ][+-])|(R[xyz][+-])$";
                if (Regex.IsMatch(s, strPattern))
                {
                    str = "MoveJog(" + s + ")";
                }
                else
                {
                    return "send error:invalid parameter!!!";
                }
            }
            if (!mRobotConnector.SendData(str))
            {
                return str + ":send error";
            }

            return mRobotConnector.WaitReply(5000);
        }
        /// <summary>
        /// 停止关节点动运动
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        public string StopMoveJog()
        {
            return MoveJog(null);
        }

        /// <summary>
        /// 点到点运动，目标点位为笛卡尔点位
        /// </summary>
        /// <param name="pt">笛卡尔点位</param>
        /// <returns>返回执行结果的描述信息</returns>
        public string MovJ(DescartesPoint pt)
        {
            if (!mRobotConnector.IsConnected())
            {
                return "device does not connected!!!";
            }

            if (null == pt)
            {
                return "send error:invalid parameter!!!";
            }
            string str = String.Format("MovJ(pose={{{0},{1},{2},{3},{4},{5}}})", pt.x, pt.y, pt.z, pt.rx, pt.ry, pt.rz);
            if (!mRobotConnector.SendData(str))
            {
                return str + ":send error";
            }

            return mRobotConnector.WaitReply(5000);
        }

        /// <summary>
        /// 直线运动，目标点位为笛卡尔点位
        /// </summary>
        /// <param name="pt">笛卡尔点位</param>
        /// <returns>返回执行结果的描述信息</returns>
        public string MovL(DescartesPoint pt)
        {
            if (!mRobotConnector.IsConnected())
            {
                return "device does not connected!!!";
            }
            if (null == pt)
            {
                return "send error:invalid parameter!!!";
            }
            string str = String.Format("MovL(pose={{{0},{1},{2},{3},{4},{5}}})", pt.x, pt.y, pt.z, pt.rx, pt.ry, pt.rz);
            if (!mRobotConnector.SendData(str))
            {
                return str + ":send error";
            }

            return mRobotConnector.WaitReply(5000);
        }

        /// <summary>
        /// 点到点运动，目标点位为关节点位。
        /// </summary>
        /// <param name="pt"></param>
        /// <returns>返回执行结果的描述信息</returns>
        public string JointMovJ(JointPoint pt)
        {
            if (!mRobotConnector.IsConnected())
            {
                return "device does not connected!!!";
            }
            if (null == pt)
            {
                return "send error:invalid parameter!!!";
            }
            string str = String.Format("MovJ(joint={{{0},{1},{2},{3},{4},{5}}})", pt.j1, pt.j2, pt.j3, pt.j4, pt.j5, pt.j6);
            if (!mRobotConnector.SendData(str))
            {
                return str + ":send error";
            }

            return mRobotConnector.WaitReply(5000);
        }
    }
}

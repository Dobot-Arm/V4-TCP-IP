using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace CSharpTcpDemo.com.dobot.api
{
    class Dashboard
    {
        private RobotConnector mRobotConnector;
        public Dashboard(RobotConnector robot)
        {
            mRobotConnector = robot;
        }

        /// <summary>
        /// 复位，用于清除错误
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        public string ClearError()
        {
            if (!mRobotConnector.IsConnected())
            {
                return "device does not connected!!!";
            }

            string str = "ClearError()";
            if (!mRobotConnector.SendData(str))
            {
                return str + ":send error";
            }

            return mRobotConnector.WaitReply(5000);
        }

        /// <summary>
        /// 机器人上电
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        public string PowerOn()
        {
            if (!mRobotConnector.IsConnected())
            {
                return "device does not connected!!!";
            }

            string str = "PowerOn()";
            if (!mRobotConnector.SendData(str))
            {
                return str + ":send error";
            }

            return mRobotConnector.WaitReply(15000);
        }

        /// <summary>
        /// 急停
        /// </summary>
        /// <param name="bIsStop">true:按下急停 false：松开急停</param>
        /// <returns>返回执行结果的描述信息</returns>
        public string EmergencyStop(bool bIsStop)
        {
            if (!mRobotConnector.IsConnected())
            {
                return "device does not connected!!!";
            }

            string str = String.Format("EmergencyStop({0})", bIsStop ? 1 : 0);
            if (!mRobotConnector.SendData(str))
            {
                return str + ":send error";
            }

            return mRobotConnector.WaitReply(15000);
        }

        /// <summary>
        /// 使能机器人
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        public string EnableRobot()
        {
            if (!mRobotConnector.IsConnected())
            {
                return "device does not connected!!!";
            }

            string str = "EnableRobot()";
            if (!mRobotConnector.SendData(str))
            {
                return str + ":send error";
            }

            return mRobotConnector.WaitReply(20000);
        }

        /// <summary>
        /// 下使能机器人
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        public string DisableRobot()
        {
            if (!mRobotConnector.IsConnected())
            {
                return "device does not connected!!!";
            }

            string str = "DisableRobot()";
            if (!mRobotConnector.SendData(str))
            {
                return str + ":send error";
            }

            return mRobotConnector.WaitReply(20000);
        }

        /// <summary>
        /// 机器人停止
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        public string StopRobot()
        {
            if (!mRobotConnector.IsConnected())
            {
                return "device does not connected!!!";
            }

            string str = "StopRobot()";
            if (!mRobotConnector.SendData(str))
            {
                return str + ":send error";
            }

            return mRobotConnector.WaitReply(20000);
        }

        /// <summary>
        /// 设置全局速度比例。
        /// </summary>
        /// <param name="ratio">运动速度比例，取值范围：1~100</param>
        /// <returns>返回执行结果的描述信息</returns>
        public string SpeedFactor(int ratio)
        {
            if (!mRobotConnector.IsConnected())
            {
                return "device does not connected!!!";
            }

            string str = String.Format("SpeedFactor({0})", ratio);
            if (!mRobotConnector.SendData(str))
            {
                return str + ":send error";
            }

            return mRobotConnector.WaitReply(5000);
        }

        /// <summary>
        /// 设置数字输出端口状态（队列指令）
        /// </summary>
        /// <param name="index">数字输出索引，取值范围：1~16或100~1000</param>
        /// <param name="status">数字输出端口状态，true：高电平；false：低电平</param>
        /// <param name="mstime">持续时间，毫秒</param>
        /// <returns>返回执行结果的描述信息</returns>
        public string DigitalOutputs(int index, bool status, int mstime)
        {
            if (!mRobotConnector.IsConnected())
            {
                return "device does not connected!!!";
            }

            string str = String.Format("DO({0},{1},{2})", index, status ? 1 : 0, mstime);
            if (!mRobotConnector.SendData(str))
            {
                return str + ":send error";
            }

            return mRobotConnector.WaitReply(5000);
        }

        /// <summary>
        /// 设置末端数字输出端口状态（队列指令）
        /// </summary>
        /// <param name="index">数字输出索引</param>
        /// <param name="status">数字输出端口状态，true：高电平；false：低电平</param>
        /// <returns>返回执行结果的描述信息</returns>
        public string ToolDO(int index, bool status)
        {
            if (!mRobotConnector.IsConnected())
            {
                return "device does not connected!!!";
            }

            string str = String.Format("ToolDO({0},{1})", index, status ? 1 : 0);
            if (!mRobotConnector.SendData(str))
            {
                return str + ":send error";
            }

            return mRobotConnector.WaitReply(5000);
        }

        public string GetErrorID()
        {
            if (!mRobotConnector.IsConnected())
            {
                return "device does not connected!!!";
            }

            string str = "GetErrorID()";
            if (!mRobotConnector.SendData(str))
            {
                return str + ":send error";
            }

            return mRobotConnector.WaitReply(5000);
        }
    }
}

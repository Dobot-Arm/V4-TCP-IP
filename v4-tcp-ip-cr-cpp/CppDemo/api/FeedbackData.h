#pragma once
#include <cstdint>

namespace Dobot
{
    class CFeedbackData
    {
    public:
        unsigned short MessageSize = 0;//消息字节总长度

        short Reserved1[3];//保留位

        int64_t DigitalInputs = 0;//数字输入
        int64_t DigitalOutputs = 0;//数字输出
        int64_t RobotMode = 0;//机器人模式,9标识有错误
        int64_t TimeStamp = 0;//时间戳（单位ms）

        int64_t Reserved2 = 0;//保留位
        int64_t TestValue = 0;//内存结构测试标准值  0x0123 4567 89AB CDEF
        double Reserved3 = 0;//保留位

        double SpeedScaling = 0;//速度比例
        double LinearMomentumNorm = 0; //机器人当前动量
        double VMain = 0;//控制板电压
        double VRobot = 0;//机器人电压
        double IRobot = 0;//机器人电流

        double ProgramState = 0;//脚本运行状态
        double SafetyStatus = 0;//安全状态

        double ToolAccelerometerValues[3];//TCP加速度
        double ElbowPosition[3];//肘位置
        double ElbowVelocity[3];//肘速度

        double QTarget[6];//目标关节位置
        double QdTarget[6];//目标关节速度
        double QddTarget[6];//目标关节加速度
        double ITarget[6];//目标关节加速度
        double MTarget[6];//目标关节电流
        double QActual[6];//实际关节位置
        double QdActual[6];//实际关节速度
        double IActual[6];//实际关节电流
        double ActualTCPForce[6];//TCP传感器力值
        double ToolVectorActual[6];//TCP笛卡尔实际坐标值
        double TCPSpeedActual[6]; //TCP笛卡尔实际速度值
        double TCPForce[6];//TCP力值
        double ToolVectorTarget[6];//TCP笛卡尔目标坐标值
        double TCPSpeedTarget[6];//TCP笛卡尔目标速度值
        double MotorTempetatures[6];//关节温度
        double JointModes[6];//关节控制模式
        double VActual[6];//关节电压

        unsigned char Handtype[4];//手系
        unsigned char User = 0;//用户坐标
        unsigned char Tool = 0;//工具坐标
        unsigned char RunQueuedCmd = 0;//算法队列运行标志
        unsigned char PauseCmdFlag = 0;//算法队列暂停标志
        unsigned char VelocityRatio = 0;//关节速度比例(0~100)
        unsigned char AccelerationRatio = 0;//关节加速度比例(0~100)
        unsigned char JerkRatio = 0;//关节加加速度比例(0~100)
        unsigned char XYZVelocityRatio = 0;//笛卡尔位置速度比例(0~100)
        unsigned char RVelocityRatio = 0;//笛卡尔姿态速度比例(0~100)
        unsigned char XYZAccelerationRatio = 0;//笛卡尔位置加速度比例(0~100)
        unsigned char RAccelerationRatio = 0;//笛卡尔姿态加速度比例(0~100)
        unsigned char XYZJerkRatio = 0;//笛卡尔位置加加速度比例(0~100)
        unsigned char RJerkRatio = 0;//笛卡尔姿态加加速度比例(0~100)

        unsigned char BrakeStatus = 0; //机器人抱闸状态
        unsigned char EnableStatus = 0;//机器人使能状态
        unsigned char DragStatus = 0;//机器人拖拽状态
        unsigned char RunningStatus = 0;//机器人运行状态
        unsigned char ErrorStatus = 0;//机器人报警状态
        unsigned char JogStatus = 0;//机器人点动状态
        unsigned char RobotType = 0; //机器类型
        unsigned char DragButtonSignal = 0; //按钮板拖拽信号
        unsigned char EnableButtonSignal = 0;//按钮板使能信号
        unsigned char RecordButtonSignal = 0;//按钮板录制信号
        unsigned char ReappearButtonSignal = 0;//按钮板复现信号
        unsigned char JawButtonSignal = 0; //按钮板夹爪控制信号
        unsigned char SixForceOnline = 0;//六维力在线状态

        unsigned char CollisionState = 0;//碰撞状态
        unsigned char ArmApproachState = 0;//小臂接近暂停状态
        unsigned char J4ApproachState = 0;//J4接近暂停
        unsigned char J5ApproachState = 0;//J5接近暂停
        unsigned char J6ApproachState = 0;//J6接近暂停

        unsigned char Reserved6[77];//保留位

        double MActual[6];//实际扭矩
        double Load = 0;//负载重量kg
        double CenterX = 0;//X方向偏心距离mm
        double CenterY = 0;//Y方向偏心距离mm
        double CenterZ = 0;//Z方向偏心距离mm
        double UserValu[6];//用户坐标值
        double Tools[6];//工具坐标值
        double TraceIndex = 0;//轨迹复现运行索引
        double SixForceValue[6];//当前六维力数据原始值
        double TargetQuaternion[4]; //[qw,qx,qy,qz] 目标四元数
        double ActualQuaternion[4];//[qw,qx,qy,qz]  实际四元数

        unsigned char Reserved7[24];//保留位
    };
}

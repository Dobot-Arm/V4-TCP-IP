package com.dobot.api;



import java.io.IOException;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.Date;


public class Dashboard {
    private Socket socketClient = new Socket();

    private static String SEND_ERROR = ":send error";

    private String ip = "";


    public boolean connect(String ip,int port,Socket socketClient){
        boolean ok = false;
        try {
            this.socketClient = socketClient;
            this.ip = ip;
            Logger.instance.log("Dashboard connect success");
            ok = true;
        } catch (Exception e) {
            Logger.instance.log("Connect failed:" + e.getMessage());
        }
        return ok;
    }

    public void disconnect(){
        if(!socketClient.isClosed()){
            try {
                socketClient.shutdownOutput();
                socketClient.shutdownInput();
                socketClient.close();
                Logger.instance.log("Dashboard closed");
            } catch (Exception e) {
                Logger.instance.log("Dashboard Close Socket Exception:" + e.getMessage());
            }
        }else {
            Logger.instance.log("this ip is not connected");
        }
    }

    /// <summary>
    /// 设置数字输出端口状态（队列指令）
    /// </summary>
    /// <param name="index">数字输出索引，取值范围：1~16或100~1000</param>
    /// <param name="status">数字输出端口状态，true：高电平；false：低电平</param>
    /// <param name="mstime">持续时间，毫秒</param>
    /// <returns>返回执行结果的描述信息</returns>
    public String DigitalOutputs(int index, boolean status, int mstime)
    {
        if (socketClient.isClosed())
        {
            Logger.instance.log("device does not connected!!!");
            return "device does not connected!!!";
        }
        int statusInt = status ? 1 : 0;
        String str = "DO("+index+","+statusInt+","+mstime+")";
        if (!sendData(str,false))
        {
            return str + ":send error";
        }

        return waitReply(5000,false);
    }

    public String getErrorID()
    {

        String str = "GetErrorID()";

        if (!sendData(str,true))
        {
            return str + ":send error";
        }

        return waitReply(5000,true);

    }


    /// <summary>
    /// 设置末端数字输出端口状态（队列指令）
    /// </summary>
    /// <param name="index">数字输出索引</param>
    /// <param name="status">数字输出端口状态，true：高电平；false：低电平</param>
    /// <returns>返回执行结果的描述信息</returns>
    public String toolDO(int index, boolean status)
    {
        if (!socketClient.isConnected())
        {
            return "device does not connected!!!";
        }
        int intStatus = status ? 1 : 0;
        String str = "ToolDO("+index+","+intStatus+")";
        if (!sendData(str,false))
        {
            return str + ":send error";
        }

        return waitReply(5000,false);
    }


    public String clearError(){
        if(socketClient.isClosed()){
            Logger.instance.log("device does not connected!!!");
            return "device does not connected!!!";
        }
        String str = "ClearError()";
        if(!sendData(str,false)){
            return str + SEND_ERROR;
        }

        return waitReply(5000,false);
    }

    public String PowerOn(){
        if(socketClient.isClosed()){
            Logger.instance.log("device does not connected!!!");
            return "device does not connected!!!";
        }
        String str = "PowerOn()";
        if(!sendData(str,false)){
            return str + SEND_ERROR;
        }

        return waitReply(15000,false);
    }

    public String PowerOff() {
        return emergencyStop();
    }

    public String emergencyStop()
    {
        if (socketClient.isClosed())
        {
            Logger.instance.log("device does not connected!!!");
            return "device does not connected!!!";
        }
        String str = "EmergencyStop()";
        if(!sendData(str,false)){
            return str + SEND_ERROR;
        }
        return waitReply(15000,false);
    }

    public String enableRobot()
    {
        if (socketClient.isClosed())
        {
            Logger.instance.log("device does not connected!!!");
            return "device does not connected!!!";
        }

        String str = "EnableRobot()";
        if(!sendData(str,false)){
            return str + SEND_ERROR;
        }

        return waitReply(20000,false);
    }

    public String disableRobot()
    {
        if (socketClient.isClosed())
        {
            Logger.instance.log("device does not connected!!!");
            return "device does not connected!!!";
        }

        String str = "DisableRobot()";
        if(!sendData(str,false)){
            return str + SEND_ERROR;
        }

        return waitReply(20000,false);
    }

    public String stopRobot(){
        if (socketClient.isClosed())
        {
            Logger.instance.log("device does not connected!!!");
            return "device does not connected!!!";
        }

        String str = "StopRobot()";
        if(!sendData(str,false)){
            return str + SEND_ERROR;
        }

        return waitReply(20000,false);
    }

    public String speedFactor(int ratio)
    {
        if (socketClient.isClosed())
        {
            Logger.instance.log("device does not connected!!!");
            return "device does not connected!!!";
        }
        String str ="SpeedFactor(" + ratio +")";
        if(!sendData(str,false)){
            return str + SEND_ERROR;
        }
        return waitReply(5000,false);
    }

    public boolean sendData(String str,boolean notLog){
        try {
            if(!notLog)
            Logger.instance.log("Send to:" +this.ip+":"+socketClient.getPort()+":"+str);
            socketClient.getOutputStream().write((str).getBytes());
        } catch (IOException e) {
            Logger.instance.log("Exception:" + e.getMessage());
            return false;
        }
        return true;
    }

    public String waitReply(int timeout,boolean notLog){
        String reply = "";
        try {
            if(socketClient.getSoTimeout() != timeout){
                socketClient.setSoTimeout(timeout);
            }
            byte[] buffer = new byte[1024];				//缓冲
            int len = socketClient.getInputStream().read(buffer);//每次读取的长度（正常情况下是1024，最后一次可能不是1024，如果传输结束，返回-1）
            reply = new String(buffer,0,len,"UTF-8");
            ErrorInfoHelper.getInstance().parseResult(reply);
            if(!notLog)
            Logger.instance.log("Receive from:"+this.ip+":"+socketClient.getPort()+":"+reply);

        } catch (IOException e) {
            Logger.instance.log("Exception:"+e.getMessage());
            return reply;
        }
        return reply;
    }


}
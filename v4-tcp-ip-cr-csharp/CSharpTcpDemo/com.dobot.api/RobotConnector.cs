using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace CSharpTcpDemo.com.dobot.api
{
    class RobotConnector : DobotClient
    {
        protected override void OnConnected(Socket sock)
        {
            sock.SendTimeout = 5000;
            sock.ReceiveTimeout = 10000;
        }

        protected override void OnDisconnected()
        {
        }
    }
}

using System;
using System.Threading;
using System.IO.Ports;

namespace XPNet
{
    public class ArduinoController
    {
        static SerialPort currentPort;
        bool portFound;
        static bool _continue;
        private static IXPlaneApi m_api;

        #region Exposed Methods
        public void InitiateConnection()
        {
            try
            {
                string[] ports = SerialPort.GetPortNames();
                foreach (string port in ports)
                {
                    currentPort = new SerialPort(port, 9600);
                    if (DetectArduino())
                    {
                        portFound = true;
                        m_api.Log.Log("Arduino found!");
                        break;
                    }
                    else
                    {
                        portFound = false;
                    }
                }

                if (!portFound)
                    m_api.Log.Log("Could not find Arduino");
            }
            catch (Exception e)
            {
            }
        }

        public void BeginReading()
        {
            string name;
            string message;
            StringComparer stringComparer = StringComparer.OrdinalIgnoreCase;
            Thread readThread = new Thread(Read);

            if (currentPort == null || !portFound)
            {
                throw new NullReferenceException("Port has not been initialised");
            }

            currentPort.Open();
            _continue = true;
            readThread.Start();

            while (_continue)
            {
                message = Console.ReadLine();

                if (stringComparer.Equals("quit", message))
                {
                    _continue = false;
                }
                else
                {
                    currentPort.WriteLine(
                        String.Format("<{0}>: {1}", message));
                }
            }

            readThread.Join();
            currentPort.Close();
        }
        #endregion

        private static void Read()
        {
            while (_continue)
            {
                try
                {
                    string message = currentPort.ReadLine();
                    //Console.WriteLine(message);
                    sendCommand("sim/GPS/g430n1_cdi");
                    m_api.Log.Log("ard_send_messagesim/GPS/g430n1_cdi");
                    //PluginAdapter.SendXplaneCommand(message);
                }
                catch (TimeoutException)
                {

                }
            }
        }

        public static void sendCommand(string command)
        {
            var cmd = m_api.Commands.GetCommand(command);
            cmd.InvokeOnce();
        }

        public ArduinoController(IXPlaneApi api)
        {
            m_api = api;
        }

        #region Helper Methods
        private bool DetectArduino()
        {
            // TODO add some sort of connection handshake
            return true;
        }
        #endregion
    }
}
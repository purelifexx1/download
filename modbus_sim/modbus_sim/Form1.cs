using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.IO.Ports;
using System.Globalization;

namespace modbus_sim
{
    
    public partial class Form1 : Form
    {
        int number;
        byte[] buffer = new byte[300];
        Random rnd = new Random();

        int data_push_pointer;
        int data_handle_pointer;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                if (serialPort1.IsOpen)
                {
                    con.Text = "connect";
                    con.ForeColor = Color.Red;
                    serialPort1.Close();
                }
                else
                {
                    serialPort1.PortName = com.Text;
                    serialPort1.Open();
                    con.Text = "disconnect";
                    con.ForeColor = Color.Green;
                }
            }
            catch
            {

            }         
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            com.DataSource = SerialPort.GetPortNames();
        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            number = serialPort1.BytesToRead;
            if(number != 0)
            {
                serialPort1.Read(buffer, data_push_pointer, number);
                data_push_pointer += number;
                if(data_push_pointer >= 8)
                {
                    data_push_pointer = 0;
                    this.Invoke(new EventHandler(data_handler));
                }
            }

        }

        private void data_handler(object sender, EventArgs e)
        {
            switch (buffer[1])
            {             
                case 4:
                    byte[] data_send;
                    byte[] ti;
                    switch (buffer[4]*256+buffer[5])
                    {
                        case 15:
                            data_send = new byte[35];
                            data_send[0] = 1;
                            data_send[1] = 4;
                            data_send[2] = 30;
                            Array.Copy(random_data(15), 0, data_send, 3, 30);
                            ti = CRC_16(data_send);
                            data_send[33] = ti[0];
                            data_send[34] = ti[1];
                            serialPort1.Write(data_send, 0, 35);
                            //real time data
                            break;
                        case 20:
                            
                            //statistic data
                            break;
                        case 6:
                            //contorl data
                            break;
                    }
                    break;
                case 1:

                    break;
            }
        }
        private byte[] random_data(int number_of_data)
        {
            List<byte> rnd_array = new List<byte>();
            for(int i = 1; i <= number_of_data; i++)
            {
                ushort tempp = Convert.ToUInt16(rnd.Next(100, 22000));
                rnd_array.Add((byte)(tempp >> 8 & 0xff));
                rnd_array.Add((byte)(tempp & 0xff));
            }
            return rnd_array.ToArray();
        }
        private byte[] CRC_16(byte[] input)
        {
            byte[] checksum = new byte[2];
            ushort reg = 0xffff;
            for(int i = 0; i< input.Length - 2; i++)
            {
                reg ^= input[i];
                for(int j = 0; j<8; j++)
                {
                    if((reg & 0x01) == 1)
                    {
                        reg = (ushort)((reg >> 1) ^ 0xa001);
                    }
                    else
                    {
                        reg = (ushort)(reg >> 1);
                    }
                }
            }
            checksum[1] = (byte)((reg >> 8) & 0xff);
            checksum[0] = (byte)(reg & 0xff);
            return checksum;
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            

        }
    }
}

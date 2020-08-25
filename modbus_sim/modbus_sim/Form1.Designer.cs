namespace modbus_sim
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.com = new System.Windows.Forms.ComboBox();
            this.con = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.testing = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.receive = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.BaudRate = 115200;
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // com
            // 
            this.com.FormattingEnabled = true;
            this.com.Location = new System.Drawing.Point(12, 12);
            this.com.Name = "com";
            this.com.Size = new System.Drawing.Size(98, 21);
            this.com.TabIndex = 0;
            // 
            // con
            // 
            this.con.ForeColor = System.Drawing.Color.Red;
            this.con.Location = new System.Drawing.Point(126, 10);
            this.con.Name = "con";
            this.con.Size = new System.Drawing.Size(75, 23);
            this.con.TabIndex = 1;
            this.con.Text = "connect";
            this.con.UseVisualStyleBackColor = true;
            this.con.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(207, 10);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 2;
            this.button2.Text = "refresh";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(12, 39);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(351, 94);
            this.textBox1.TabIndex = 3;
            // 
            // testing
            // 
            this.testing.Location = new System.Drawing.Point(31, 156);
            this.testing.Multiline = true;
            this.testing.Name = "testing";
            this.testing.Size = new System.Drawing.Size(408, 130);
            this.testing.TabIndex = 4;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(507, 154);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 5;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // receive
            // 
            this.receive.Location = new System.Drawing.Point(507, 233);
            this.receive.Name = "receive";
            this.receive.Size = new System.Drawing.Size(176, 20);
            this.receive.TabIndex = 6;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(705, 355);
            this.Controls.Add(this.receive);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.testing);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.con);
            this.Controls.Add(this.com);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.ComboBox com;
        private System.Windows.Forms.Button con;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox testing;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox receive;
    }
}


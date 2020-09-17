<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.SaveFileDialog1 = New System.Windows.Forms.SaveFileDialog()
        Me.Button2 = New System.Windows.Forms.Button()
        Me.TextBox1 = New System.Windows.Forms.TextBox()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.ver = New System.Windows.Forms.TextBox()
        Me.release = New System.Windows.Forms.TextBox()
        Me.Vari = New System.Windows.Forms.TextBox()
        Me.project = New System.Windows.Forms.TextBox()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.private_can = New System.Windows.Forms.TextBox()
        Me.public_can = New System.Windows.Forms.TextBox()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.Button4 = New System.Windows.Forms.Button()
        Me.Button5 = New System.Windows.Forms.Button()
        Me.Button6 = New System.Windows.Forms.Button()
        Me.OpenFileDialog1 = New System.Windows.Forms.OpenFileDialog()
        Me.GroupBox2 = New System.Windows.Forms.GroupBox()
        Me.Label9 = New System.Windows.Forms.Label()
        Me.string_enable = New System.Windows.Forms.TextBox()
        Me.value_dtc = New System.Windows.Forms.TextBox()
        Me.signal_dtc = New System.Windows.Forms.ComboBox()
        Me.Label8 = New System.Windows.Forms.Label()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.GroupBox3 = New System.Windows.Forms.GroupBox()
        Me.SLA = New System.Windows.Forms.Button()
        Me.RDP = New System.Windows.Forms.Button()
        Me.HMA = New System.Windows.Forms.Button()
        Me.TJA = New System.Windows.Forms.Button()
        Me.ELK = New System.Windows.Forms.Button()
        Me.LKS = New System.Windows.Forms.Button()
        Me.LWD = New System.Windows.Forms.Button()
        Me.speed_group = New System.Windows.Forms.GroupBox()
        Me.Button9 = New System.Windows.Forms.Button()
        Me.speed_signal = New System.Windows.Forms.ComboBox()
        Me.all_signal = New System.Windows.Forms.ComboBox()
        Me.Button17 = New System.Windows.Forms.Button()
        Me.GroupBox4 = New System.Windows.Forms.GroupBox()
        Me.GroupBox6 = New System.Windows.Forms.GroupBox()
        Me.man_pre = New System.Windows.Forms.ComboBox()
        Me.Label10 = New System.Windows.Forms.Label()
        Me.sf_signal = New System.Windows.Forms.ComboBox()
        Me.Label11 = New System.Windows.Forms.Label()
        Me.console = New System.Windows.Forms.TextBox()
        Me.GroupBox5 = New System.Windows.Forms.GroupBox()
        Me.Button10 = New System.Windows.Forms.Button()
        Me.Button8 = New System.Windows.Forms.Button()
        Me.Button7 = New System.Windows.Forms.Button()
        Me.Button3 = New System.Windows.Forms.Button()
        Me.Button12 = New System.Windows.Forms.Button()
        Me.Button11 = New System.Windows.Forms.Button()
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.GroupBox3.SuspendLayout()
        Me.speed_group.SuspendLayout()
        Me.GroupBox4.SuspendLayout()
        Me.GroupBox6.SuspendLayout()
        Me.GroupBox5.SuspendLayout()
        Me.SuspendLayout()
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(6, 19)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(75, 23)
        Me.Button1.TabIndex = 0
        Me.Button1.Text = "Add"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'SaveFileDialog1
        '
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(15, 12)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(75, 23)
        Me.Button2.TabIndex = 1
        Me.Button2.Text = "Convert"
        Me.Button2.UseVisualStyleBackColor = True
        '
        'TextBox1
        '
        Me.TextBox1.Location = New System.Drawing.Point(96, 12)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.Size = New System.Drawing.Size(145, 20)
        Me.TextBox1.TabIndex = 2
        '
        'GroupBox1
        '
        Me.GroupBox1.BackColor = System.Drawing.Color.FromArgb(CType(CType(128, Byte), Integer), CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer))
        Me.GroupBox1.Controls.Add(Me.ver)
        Me.GroupBox1.Controls.Add(Me.release)
        Me.GroupBox1.Controls.Add(Me.Vari)
        Me.GroupBox1.Controls.Add(Me.project)
        Me.GroupBox1.Controls.Add(Me.Label4)
        Me.GroupBox1.Controls.Add(Me.Label3)
        Me.GroupBox1.Controls.Add(Me.Label2)
        Me.GroupBox1.Controls.Add(Me.Label1)
        Me.GroupBox1.ForeColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.GroupBox1.Location = New System.Drawing.Point(12, 19)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(204, 115)
        Me.GroupBox1.TabIndex = 3
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Title"
        '
        'ver
        '
        Me.ver.Location = New System.Drawing.Point(86, 87)
        Me.ver.Name = "ver"
        Me.ver.Size = New System.Drawing.Size(100, 20)
        Me.ver.TabIndex = 8
        Me.ver.Text = "RC02"
        '
        'release
        '
        Me.release.Location = New System.Drawing.Point(86, 63)
        Me.release.Name = "release"
        Me.release.Size = New System.Drawing.Size(100, 20)
        Me.release.TabIndex = 7
        Me.release.Text = "R4.0"
        '
        'Vari
        '
        Me.Vari.Location = New System.Drawing.Point(86, 39)
        Me.Vari.Name = "Vari"
        Me.Vari.Size = New System.Drawing.Size(100, 20)
        Me.Vari.TabIndex = 6
        Me.Vari.Text = "T1D"
        '
        'project
        '
        Me.project.Location = New System.Drawing.Point(86, 14)
        Me.project.Name = "project"
        Me.project.Size = New System.Drawing.Size(100, 20)
        Me.project.TabIndex = 5
        Me.project.Text = "CHERY"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(13, 90)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(42, 13)
        Me.Label4.TabIndex = 4
        Me.Label4.Text = "Version"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(13, 66)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(46, 13)
        Me.Label3.TabIndex = 4
        Me.Label3.Text = "Release"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(13, 42)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(40, 13)
        Me.Label2.TabIndex = 4
        Me.Label2.Text = "Variant"
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(13, 17)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(40, 13)
        Me.Label1.TabIndex = 4
        Me.Label1.Text = "Project"
        '
        'private_can
        '
        Me.private_can.Location = New System.Drawing.Point(77, 16)
        Me.private_can.Name = "private_can"
        Me.private_can.Size = New System.Drawing.Size(217, 20)
        Me.private_can.TabIndex = 5
        '
        'public_can
        '
        Me.public_can.Location = New System.Drawing.Point(77, 41)
        Me.public_can.Name = "public_can"
        Me.public_can.Size = New System.Drawing.Size(217, 20)
        Me.public_can.TabIndex = 6
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(6, 18)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(60, 13)
        Me.Label5.TabIndex = 4
        Me.Label5.Text = "private can"
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Location = New System.Drawing.Point(6, 44)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(56, 13)
        Me.Label6.TabIndex = 4
        Me.Label6.Text = "public can"
        '
        'Button4
        '
        Me.Button4.Location = New System.Drawing.Point(300, 14)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(75, 23)
        Me.Button4.TabIndex = 7
        Me.Button4.Text = "browse"
        Me.Button4.UseVisualStyleBackColor = True
        '
        'Button5
        '
        Me.Button5.Location = New System.Drawing.Point(300, 39)
        Me.Button5.Name = "Button5"
        Me.Button5.Size = New System.Drawing.Size(75, 23)
        Me.Button5.TabIndex = 8
        Me.Button5.Text = "browse"
        Me.Button5.UseVisualStyleBackColor = True
        '
        'Button6
        '
        Me.Button6.Location = New System.Drawing.Point(87, 19)
        Me.Button6.Name = "Button6"
        Me.Button6.Size = New System.Drawing.Size(75, 23)
        Me.Button6.TabIndex = 9
        Me.Button6.Text = "delete"
        Me.Button6.UseVisualStyleBackColor = True
        '
        'OpenFileDialog1
        '
        Me.OpenFileDialog1.FileName = "OpenFileDialog1"
        '
        'GroupBox2
        '
        Me.GroupBox2.BackColor = System.Drawing.Color.FromArgb(CType(CType(128, Byte), Integer), CType(CType(255, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.GroupBox2.Controls.Add(Me.Label9)
        Me.GroupBox2.Controls.Add(Me.string_enable)
        Me.GroupBox2.Controls.Add(Me.value_dtc)
        Me.GroupBox2.Controls.Add(Me.signal_dtc)
        Me.GroupBox2.Controls.Add(Me.Label8)
        Me.GroupBox2.Controls.Add(Me.Label7)
        Me.GroupBox2.Location = New System.Drawing.Point(12, 140)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(247, 98)
        Me.GroupBox2.TabIndex = 12
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "Enable trigger DTC mode"
        '
        'Label9
        '
        Me.Label9.AutoSize = True
        Me.Label9.Location = New System.Drawing.Point(3, 70)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(68, 13)
        Me.Label9.TabIndex = 21
        Me.Label9.Text = "Enable string"
        '
        'string_enable
        '
        Me.string_enable.Location = New System.Drawing.Point(73, 67)
        Me.string_enable.Name = "string_enable"
        Me.string_enable.Size = New System.Drawing.Size(168, 20)
        Me.string_enable.TabIndex = 4
        '
        'value_dtc
        '
        Me.value_dtc.Location = New System.Drawing.Point(73, 41)
        Me.value_dtc.Name = "value_dtc"
        Me.value_dtc.Size = New System.Drawing.Size(168, 20)
        Me.value_dtc.TabIndex = 3
        '
        'signal_dtc
        '
        Me.signal_dtc.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.signal_dtc.FormattingEnabled = True
        Me.signal_dtc.Location = New System.Drawing.Point(73, 16)
        Me.signal_dtc.Name = "signal_dtc"
        Me.signal_dtc.Size = New System.Drawing.Size(168, 21)
        Me.signal_dtc.TabIndex = 2
        '
        'Label8
        '
        Me.Label8.AutoSize = True
        Me.Label8.Location = New System.Drawing.Point(6, 44)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(53, 13)
        Me.Label8.TabIndex = 0
        Me.Label8.Text = "raw value"
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Location = New System.Drawing.Point(6, 19)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(34, 13)
        Me.Label7.TabIndex = 0
        Me.Label7.Text = "signal"
        '
        'GroupBox3
        '
        Me.GroupBox3.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.GroupBox3.Controls.Add(Me.SLA)
        Me.GroupBox3.Controls.Add(Me.RDP)
        Me.GroupBox3.Controls.Add(Me.HMA)
        Me.GroupBox3.Controls.Add(Me.TJA)
        Me.GroupBox3.Controls.Add(Me.ELK)
        Me.GroupBox3.Controls.Add(Me.LKS)
        Me.GroupBox3.Controls.Add(Me.LWD)
        Me.GroupBox3.Location = New System.Drawing.Point(268, 196)
        Me.GroupBox3.Name = "GroupBox3"
        Me.GroupBox3.Size = New System.Drawing.Size(339, 81)
        Me.GroupBox3.TabIndex = 17
        Me.GroupBox3.TabStop = False
        Me.GroupBox3.Text = "Supported function"
        '
        'SLA
        '
        Me.SLA.Location = New System.Drawing.Point(171, 48)
        Me.SLA.Name = "SLA"
        Me.SLA.Size = New System.Drawing.Size(75, 23)
        Me.SLA.TabIndex = 6
        Me.SLA.Text = "SLA"
        Me.SLA.UseVisualStyleBackColor = True
        '
        'RDP
        '
        Me.RDP.Location = New System.Drawing.Point(252, 19)
        Me.RDP.Name = "RDP"
        Me.RDP.Size = New System.Drawing.Size(75, 23)
        Me.RDP.TabIndex = 5
        Me.RDP.Text = "RDP"
        Me.RDP.UseVisualStyleBackColor = True
        '
        'HMA
        '
        Me.HMA.Location = New System.Drawing.Point(90, 48)
        Me.HMA.Name = "HMA"
        Me.HMA.Size = New System.Drawing.Size(75, 23)
        Me.HMA.TabIndex = 4
        Me.HMA.Text = "HMA"
        Me.HMA.UseVisualStyleBackColor = True
        '
        'TJA
        '
        Me.TJA.Location = New System.Drawing.Point(171, 19)
        Me.TJA.Name = "TJA"
        Me.TJA.Size = New System.Drawing.Size(75, 23)
        Me.TJA.TabIndex = 3
        Me.TJA.Text = "TJA"
        Me.TJA.UseVisualStyleBackColor = True
        '
        'ELK
        '
        Me.ELK.Location = New System.Drawing.Point(9, 48)
        Me.ELK.Name = "ELK"
        Me.ELK.Size = New System.Drawing.Size(75, 23)
        Me.ELK.TabIndex = 2
        Me.ELK.Text = "ELK"
        Me.ELK.UseVisualStyleBackColor = True
        '
        'LKS
        '
        Me.LKS.Location = New System.Drawing.Point(90, 19)
        Me.LKS.Name = "LKS"
        Me.LKS.Size = New System.Drawing.Size(75, 23)
        Me.LKS.TabIndex = 1
        Me.LKS.Text = "LKS"
        Me.LKS.UseVisualStyleBackColor = True
        '
        'LWD
        '
        Me.LWD.Location = New System.Drawing.Point(9, 19)
        Me.LWD.Name = "LWD"
        Me.LWD.Size = New System.Drawing.Size(75, 23)
        Me.LWD.TabIndex = 0
        Me.LWD.Text = "LWD"
        Me.LWD.UseVisualStyleBackColor = True
        '
        'speed_group
        '
        Me.speed_group.BackColor = System.Drawing.Color.Aqua
        Me.speed_group.Controls.Add(Me.Button9)
        Me.speed_group.Controls.Add(Me.speed_signal)
        Me.speed_group.Controls.Add(Me.all_signal)
        Me.speed_group.Controls.Add(Me.Button1)
        Me.speed_group.Controls.Add(Me.Button6)
        Me.speed_group.Location = New System.Drawing.Point(612, 19)
        Me.speed_group.Name = "speed_group"
        Me.speed_group.Size = New System.Drawing.Size(340, 258)
        Me.speed_group.TabIndex = 18
        Me.speed_group.TabStop = False
        Me.speed_group.Text = "necessary speed"
        '
        'Button9
        '
        Me.Button9.Location = New System.Drawing.Point(295, 19)
        Me.Button9.Name = "Button9"
        Me.Button9.Size = New System.Drawing.Size(39, 49)
        Me.Button9.TabIndex = 12
        Me.Button9.Text = "Add"
        Me.Button9.UseVisualStyleBackColor = True
        '
        'speed_signal
        '
        Me.speed_signal.FormattingEnabled = True
        Me.speed_signal.Location = New System.Drawing.Point(168, 47)
        Me.speed_signal.Name = "speed_signal"
        Me.speed_signal.Size = New System.Drawing.Size(121, 21)
        Me.speed_signal.TabIndex = 11
        '
        'all_signal
        '
        Me.all_signal.FormattingEnabled = True
        Me.all_signal.Location = New System.Drawing.Point(168, 21)
        Me.all_signal.Name = "all_signal"
        Me.all_signal.Size = New System.Drawing.Size(121, 21)
        Me.all_signal.TabIndex = 11
        '
        'Button17
        '
        Me.Button17.Location = New System.Drawing.Point(0, 66)
        Me.Button17.Name = "Button17"
        Me.Button17.Size = New System.Drawing.Size(75, 23)
        Me.Button17.TabIndex = 19
        Me.Button17.Text = "import"
        Me.Button17.UseVisualStyleBackColor = True
        '
        'GroupBox4
        '
        Me.GroupBox4.BackColor = System.Drawing.Color.SeaShell
        Me.GroupBox4.Controls.Add(Me.Button17)
        Me.GroupBox4.Controls.Add(Me.Button5)
        Me.GroupBox4.Controls.Add(Me.Button4)
        Me.GroupBox4.Controls.Add(Me.public_can)
        Me.GroupBox4.Controls.Add(Me.private_can)
        Me.GroupBox4.Controls.Add(Me.Label6)
        Me.GroupBox4.Controls.Add(Me.Label5)
        Me.GroupBox4.Location = New System.Drawing.Point(222, 19)
        Me.GroupBox4.Name = "GroupBox4"
        Me.GroupBox4.Size = New System.Drawing.Size(384, 103)
        Me.GroupBox4.TabIndex = 20
        Me.GroupBox4.TabStop = False
        Me.GroupBox4.Text = "File import"
        '
        'GroupBox6
        '
        Me.GroupBox6.Controls.Add(Me.TextBox1)
        Me.GroupBox6.Controls.Add(Me.Button2)
        Me.GroupBox6.Location = New System.Drawing.Point(12, 244)
        Me.GroupBox6.Name = "GroupBox6"
        Me.GroupBox6.Size = New System.Drawing.Size(247, 40)
        Me.GroupBox6.TabIndex = 24
        Me.GroupBox6.TabStop = False
        Me.GroupBox6.Text = "XML Export"
        '
        'man_pre
        '
        Me.man_pre.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.man_pre.FormattingEnabled = True
        Me.man_pre.Location = New System.Drawing.Point(265, 128)
        Me.man_pre.Name = "man_pre"
        Me.man_pre.Size = New System.Drawing.Size(207, 21)
        Me.man_pre.TabIndex = 25
        '
        'Label10
        '
        Me.Label10.AutoSize = True
        Me.Label10.Location = New System.Drawing.Point(478, 131)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(96, 13)
        Me.Label10.TabIndex = 26
        Me.Label10.Text = "Precondition signal"
        '
        'sf_signal
        '
        Me.sf_signal.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.sf_signal.FormattingEnabled = True
        Me.sf_signal.Location = New System.Drawing.Point(265, 161)
        Me.sf_signal.Name = "sf_signal"
        Me.sf_signal.Size = New System.Drawing.Size(207, 21)
        Me.sf_signal.TabIndex = 27
        '
        'Label11
        '
        Me.Label11.AutoSize = True
        Me.Label11.Location = New System.Drawing.Point(478, 164)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(129, 13)
        Me.Label11.TabIndex = 28
        Me.Label11.Text = "Added supported function"
        '
        'console
        '
        Me.console.BackColor = System.Drawing.Color.LightGray
        Me.console.Location = New System.Drawing.Point(6, 19)
        Me.console.Multiline = True
        Me.console.Name = "console"
        Me.console.ReadOnly = True
        Me.console.ScrollBars = System.Windows.Forms.ScrollBars.Both
        Me.console.Size = New System.Drawing.Size(760, 165)
        Me.console.TabIndex = 31
        '
        'GroupBox5
        '
        Me.GroupBox5.BackColor = System.Drawing.Color.LightGray
        Me.GroupBox5.Controls.Add(Me.Button10)
        Me.GroupBox5.Controls.Add(Me.Button8)
        Me.GroupBox5.Controls.Add(Me.Button7)
        Me.GroupBox5.Controls.Add(Me.Button3)
        Me.GroupBox5.Controls.Add(Me.Button12)
        Me.GroupBox5.Controls.Add(Me.console)
        Me.GroupBox5.Location = New System.Drawing.Point(12, 290)
        Me.GroupBox5.Name = "GroupBox5"
        Me.GroupBox5.Size = New System.Drawing.Size(772, 216)
        Me.GroupBox5.TabIndex = 33
        Me.GroupBox5.TabStop = False
        Me.GroupBox5.Text = "Terminal"
        '
        'Button10
        '
        Me.Button10.Location = New System.Drawing.Point(326, 190)
        Me.Button10.Name = "Button10"
        Me.Button10.Size = New System.Drawing.Size(107, 23)
        Me.Button10.TabIndex = 37
        Me.Button10.Text = "Save configuration"
        Me.Button10.UseVisualStyleBackColor = True
        '
        'Button8
        '
        Me.Button8.Location = New System.Drawing.Point(40, 190)
        Me.Button8.Name = "Button8"
        Me.Button8.Size = New System.Drawing.Size(113, 23)
        Me.Button8.TabIndex = 34
        Me.Button8.Text = "Test button(ignore)"
        Me.Button8.UseVisualStyleBackColor = True
        '
        'Button7
        '
        Me.Button7.Location = New System.Drawing.Point(439, 190)
        Me.Button7.Name = "Button7"
        Me.Button7.Size = New System.Drawing.Size(123, 23)
        Me.Button7.TabIndex = 36
        Me.Button7.Text = "Load current database"
        Me.Button7.UseVisualStyleBackColor = True
        '
        'Button3
        '
        Me.Button3.Location = New System.Drawing.Point(564, 190)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(99, 23)
        Me.Button3.TabIndex = 35
        Me.Button3.Text = "Clear current data"
        Me.Button3.UseVisualStyleBackColor = True
        '
        'Button12
        '
        Me.Button12.Location = New System.Drawing.Point(669, 190)
        Me.Button12.Name = "Button12"
        Me.Button12.Size = New System.Drawing.Size(97, 23)
        Me.Button12.TabIndex = 34
        Me.Button12.Text = "Clear terminal"
        Me.Button12.UseVisualStyleBackColor = True
        '
        'Button11
        '
        Me.Button11.Location = New System.Drawing.Point(849, 372)
        Me.Button11.Name = "Button11"
        Me.Button11.Size = New System.Drawing.Size(75, 23)
        Me.Button11.TabIndex = 34
        Me.Button11.Text = "Button11"
        Me.Button11.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(964, 515)
        Me.Controls.Add(Me.Button11)
        Me.Controls.Add(Me.GroupBox5)
        Me.Controls.Add(Me.Label11)
        Me.Controls.Add(Me.sf_signal)
        Me.Controls.Add(Me.Label10)
        Me.Controls.Add(Me.man_pre)
        Me.Controls.Add(Me.GroupBox6)
        Me.Controls.Add(Me.GroupBox4)
        Me.Controls.Add(Me.speed_group)
        Me.Controls.Add(Me.GroupBox3)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Name = "Form1"
        Me.Text = "FT testcase tool"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.GroupBox3.ResumeLayout(False)
        Me.speed_group.ResumeLayout(False)
        Me.GroupBox4.ResumeLayout(False)
        Me.GroupBox4.PerformLayout()
        Me.GroupBox6.ResumeLayout(False)
        Me.GroupBox6.PerformLayout()
        Me.GroupBox5.ResumeLayout(False)
        Me.GroupBox5.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Button1 As Button
    Friend WithEvents SaveFileDialog1 As SaveFileDialog
    Friend WithEvents Button2 As Button
    Friend WithEvents TextBox1 As TextBox
    Friend WithEvents GroupBox1 As GroupBox
    Friend WithEvents ver As TextBox
    Friend WithEvents release As TextBox
    Friend WithEvents Vari As TextBox
    Friend WithEvents project As TextBox
    Friend WithEvents Label4 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label1 As Label
    Friend WithEvents private_can As TextBox
    Friend WithEvents public_can As TextBox
    Friend WithEvents Label5 As Label
    Friend WithEvents Label6 As Label
    Friend WithEvents Button4 As Button
    Friend WithEvents Button5 As Button
    Friend WithEvents Button6 As Button
    Friend WithEvents OpenFileDialog1 As OpenFileDialog
    Friend WithEvents GroupBox2 As GroupBox
    Friend WithEvents Label8 As Label
    Friend WithEvents Label7 As Label
    Friend WithEvents value_dtc As TextBox
    Friend WithEvents signal_dtc As ComboBox
    Friend WithEvents GroupBox3 As GroupBox
    Friend WithEvents SLA As Button
    Friend WithEvents RDP As Button
    Friend WithEvents HMA As Button
    Friend WithEvents TJA As Button
    Friend WithEvents ELK As Button
    Friend WithEvents LKS As Button
    Friend WithEvents LWD As Button
    Friend WithEvents speed_group As GroupBox
    Friend WithEvents Button17 As Button
    Friend WithEvents GroupBox4 As GroupBox
    Friend WithEvents Label9 As Label
    Friend WithEvents string_enable As TextBox
    Friend WithEvents GroupBox6 As GroupBox
    Friend WithEvents man_pre As ComboBox
    Friend WithEvents Label10 As Label
    Friend WithEvents sf_signal As ComboBox
    Friend WithEvents Label11 As Label
    Friend WithEvents console As TextBox
    Friend WithEvents GroupBox5 As GroupBox
    Friend WithEvents Button12 As Button
    Friend WithEvents Button3 As Button
    Friend WithEvents Button7 As Button
    Friend WithEvents Button8 As Button
    Friend WithEvents Button9 As Button
    Friend WithEvents speed_signal As ComboBox
    Friend WithEvents all_signal As ComboBox
    Friend WithEvents Button10 As Button
    Friend WithEvents Button11 As Button
End Class

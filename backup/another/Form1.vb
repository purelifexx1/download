﻿Imports System.Xml
Imports System.Xml.Linq
Imports System.Linq
Imports System.IO
Imports System.Text
Public Class Form1
    Public mandatory As List(Of mapped_rx_signal) = New List(Of mapped_rx_signal)
    Public necessary_sp As List(Of mapped_rx_signal) = New List(Of mapped_rx_signal)
    Public total_signal As List(Of mapped_rx_signal) = New List(Of mapped_rx_signal)
    Public special As List(Of mapped_rx_signal) = New List(Of mapped_rx_signal)
    Public name_list As List(Of String) = New List(Of String)
    Public supported_function As List(Of mapped_rx_signal) = New List(Of mapped_rx_signal)
    Public selection As Decimal = 0
    Public speed_th As Decimal = 0
    Public current_pos As Decimal = 22
    Public group_indices As List(Of Int16) = New List(Of Int16)({})
    Public listof_speed As List(Of Decimal) = New List(Of Decimal)
    Dim convert_pressed As Boolean = False
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        convert_pressed = False
        speed_th = speed_th + 1
        Dim new_speed As New TextBox
        Dim new_speed_label As New Label
        new_speed.Name = "speed_" & CStr(speed_th) & "th"
        new_speed_label.Name = "speed" & CStr(speed_th)
        new_speed_label.Text = "speed " & CStr(speed_th)

        new_speed.Location = New Point(87, current_pos + 26)
        new_speed.Size = New Size(75, 20)
        new_speed_label.Location = New Point(21, current_pos + 26)
        new_speed_label.Size = New Size(53, 13)
        new_speed.Visible = True
        new_speed_label.Visible = True
        current_pos = current_pos + 26

        Me.speed_group.Controls.Add(new_speed)
        group_indices.Add(Me.speed_group.Controls.Count - 1)
        Me.speed_group.Controls.Add(new_speed_label)
        Me.Refresh()
    End Sub
    Private Sub Button6_Click(sender As Object, e As EventArgs) Handles Button6.Click
        convert_pressed = False
        If speed_th <> 0 Then
            speed_th = speed_th - 1
            current_pos = current_pos - 26
            Dim numm As Decimal = Me.speed_group.Controls.Count
            Me.speed_group.Controls.RemoveAt(numm - 1)
            Me.speed_group.Controls.RemoveAt(numm - 2)
            group_indices.RemoveAt(group_indices.Count - 1)
        End If
    End Sub
#Region "file handle"
    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        If sender.Name = "Button2" Then
            selection = 0
            SaveFileDialog1.ShowDialog()
        End If
    End Sub

    Private Sub SaveFileDialog1_FileOk(sender As Object, e As System.ComponentModel.CancelEventArgs) Handles SaveFileDialog1.FileOk
        If selection = 0 Then
            TextBox1.Text = SaveFileDialog1.FileName
            xml_convert()
        ElseIf selection = 1 Then

        End If
    End Sub

    Private Sub OpenFileDialog1_FileOk(sender As Object, e As System.ComponentModel.CancelEventArgs) Handles OpenFileDialog1.FileOk
        If selection = 1 Then
            private_can.Text = OpenFileDialog1.FileName
        ElseIf selection = 0 Then
            public_can.Text = OpenFileDialog1.FileName
        ElseIf selection = 2 Then
            Dim import_file As New file_handle()
            import_file.import_file(OpenFileDialog1.FileName)
        End If
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click, Button5.Click
        OpenFileDialog1.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.Desktop)
        If sender.Name = "Button4" Then
            selection = 1
            OpenFileDialog1.ShowDialog()
        ElseIf sender.Name = "Button5" Then
            selection = 0
            OpenFileDialog1.ShowDialog()
        End If
    End Sub

#End Region
    Private Sub xml_convert()
        Dim xml_handle As New xml_main
        Dim testgroup_precondition As XElement
        Dim testgroup_function As XElement
        Try
            testgroup_precondition = xml_handle.xml_construct_precondition(mandatory, special)
        Catch ex As Exception
            console.Text += "- error in precondition group: " & ex.ToString & vbCrLf
            Return
        End Try

        listof_speed = New List(Of Decimal)
        For Each run As Int16 In group_indices
            Try
                listof_speed.Add(CDec(Me.speed_group.Controls.Item(run).Text))
            Catch ex As Exception
                console.Text += "- " & "some necessary speed empty or invalid, convert fail" & vbCrLf
                Return
            End Try
        Next
        Dim testgroup_speed As XElement = xml_handle.xml_construct_speed(mandatory, listof_speed)

        Try
            testgroup_function = xml_handle.xml_construct_function()
        Catch ex As Exception
            console.Text += "- error in function group: " & ex.ToString & vbCrLf
            Return
        End Try

        Dim final_testgroup As XElement = xml_handle.create_tag("testgroup", New XAttribute("title", "Tests"), New List(Of XElement)({xml_handle.external_ref, testgroup_precondition, testgroup_speed, testgroup_function}))
        Dim xml_file As XElement = xml_handle.create_tag("testmodule", New List(Of XAttribute)({New XAttribute("title", project.Text & "_" & Vari.Text & "_" & release.Text & "_" & ver.Text), New XAttribute("version", "1.0")}), final_testgroup)
        Try
            xml_file.Save(SaveFileDialog1.FileName)
            console.Text += "- " & "The file is saved successfully at " & TextBox1.Text & vbCrLf
            convert_pressed = True
            save_data()
        Catch ex As Exception
            console.Text += "- error saving file: " & ex.ToString & vbCrLf
        End Try
    End Sub
    Private Sub string_enable_KeyPress(sender As Object, e As KeyPressEventArgs) Handles string_enable.KeyPress, value_dtc.KeyPress
        If e.KeyChar = Convert.ToChar(13) Then
            If value_dtc.Text <> "" And signal_dtc.Text <> "" And string_enable.Text <> "" Then
                Dim temper_signal As mapped_rx_signal = special.Find(Function(x) x.Name = signal_dtc.Text)
                temper_signal.additional = True
                temper_signal.raw_value = CDec(value_dtc.Text)
                If string_enable.Text <> "" Then
                    temper_signal.enable_string = string_enable.Text
                End If
                mandatory.Add(temper_signal)
                man_pre.DataSource = mandatory.Select(Function(x) x.Name).ToList
                console.Text += "- " & "signal " & temper_signal.Name & " enable successfully" & vbCrLf
                convert_pressed = False
            Else
                console.Text += "- " & "some textbox is empty" & vbCrLf
                MessageBox.Show("raw value empty")
            End If
        End If
    End Sub
    Private Sub Button17_Click(sender As Object, e As EventArgs) Handles Button17.Click
        Try
            If private_can.Text <> "" And public_can.Text <> "" Then
                renew()
                Dim result As Boolean = True
                Dim csv_data As file_handle = New file_handle(private_can.Text, public_can.Text, "helo", "hei")
                If result = True Then
                    mandatory = csv_data.mandatory
                    special = csv_data.special
                    man_pre.DataSource = mandatory.Select(Function(x) x.Name).ToList
                    console.Text += "- " & "data import successfully" & vbCrLf
                    convert_pressed = False
                    signal_dtc.DataSource = special.Select(Function(x) x.Name).ToList
                    console.Text += "- " & "signal list updated" & vbCrLf
                    sf_signal.DataSource = supported_function.Select(Function(x) x.Name).ToList
                    all_signal.DataSource = mandatory.Concat(special).Select(Function(x) x.Name).ToList
                Else
                    console.Text += "- " & "Failed to import file" & vbCrLf
                End If
            Else
                console.Text += "- " & "input directory is imcomplete" & vbCrLf
            End If
        Catch ex As Exception
            console.Text += "- error: " & ex.ToString & vbCrLf
        End Try
    End Sub

    Private Sub SP_FC_Click(sender As Object, e As EventArgs) Handles LWD.Click, LKS.Click, TJA.Click, RDP.Click, ELK.Click, HMA.Click, SLA.Click
        Dim new_form As Form2 = New Form2() With {
            .Text = sender.Name
        }
        new_form.Show()
        convert_pressed = False
    End Sub

    Private Sub Button12_Click(sender As Object, e As EventArgs) Handles Button12.Click, Button3.Click, Button7.Click, Button10.Click

        If sender.Name = "Button3" Then
            console.Text = String.Empty
            renew()
        ElseIf sender.Name = "Button12" Then
            console.Text = String.Empty
        ElseIf sender.Name = "Button7" Then
            If project.Text <> "" And Vari.Text <> "" Then
                If System.IO.File.Exists(project.Text.ToUpper & "\" & "db_" & project.Text.ToUpper & "_" & Vari.Text.ToUpper & ".csv") Then
                    renew()
                    Dim import_file As New file_handle()
                    import_file.import_file(project.Text.ToUpper & "\" & "db_" & project.Text.ToUpper & "_" & Vari.Text.ToUpper & ".csv")
                Else
                    Dim result As DialogResult = MessageBox.Show("The current project and variant is not available, do you want to load another project and variant ?", "project and variant empty", MessageBoxButtons.YesNo)
                    If result = DialogResult.Yes Then
                        renew()
                        selection = 2
                        OpenFileDialog1.InitialDirectory = Environment.CurrentDirectory
                        OpenFileDialog1.ShowDialog()
                    End If
                End If
            Else
                MessageBox.Show("project name or variant is missing")
            End If
        ElseIf sender.Name = "Button10" Then
            listof_speed = New List(Of Decimal)
            For Each run As Int16 In group_indices
                Try
                    listof_speed.Add(CDec(Me.speed_group.Controls.Item(run).Text))
                Catch ex As Exception
                    console.Text += "- " & "some necessary speed empty or invalid, save data fail" & vbCrLf
                    Return
                End Try
            Next
            convert_pressed = True
            save_data()
            console.Text += "- " & "save data configuration successfully" & vbCrLf
        End If
    End Sub

    Private Sub Form1_FormClosing(sender As Object, e As FormClosingEventArgs) Handles MyBase.FormClosing
        'save_data()
    End Sub

    Private Sub Form1_Shown(sender As Object, e As EventArgs) Handles MyBase.Shown
        If Not System.IO.File.Exists("search.csv") Then
            Dim fs As FileStream = File.Create("search.csv")
            Dim data As Byte() = Encoding.GetEncoding("iso-8859-1").GetBytes("keyword to search for name***,keyword to search for unit***,physical value***" _
                                                                             & vbCrLf & "speed,km/h,85" & vbCrLf & "temperature,¡æ,23" & vbCrLf _
                                                                             & "acceleration,g,0" & vbCrLf & "wheelspeed,m/s,0" _
                                                                             & vbCrLf & "angle,deg,0" & vbCrLf & "angle,deg/sec,0" & vbCrLf _
                                                                             & "torque,nm,1" & vbCrLf & "yaw,deg/sec,0" & vbCrLf)
            fs.Write(data, 0, data.Length)
            fs.Close()
        End If

        'If System.IO.File.Exists("Database.csv") Then
        '    Dim import_file As New file_handle()
        '    import_file.import_file()
        'End If
    End Sub
    Private Sub renew()
        mandatory = New List(Of mapped_rx_signal)
        special = New List(Of mapped_rx_signal)
        necessary_sp = New List(Of mapped_rx_signal)
        supported_function = New List(Of mapped_rx_signal)
        total_signal = New List(Of mapped_rx_signal)
        For part As Decimal = 1 To group_indices.Count
            If speed_th = 1 Then
                Exit For
            Else
                speed_th = speed_th - 1
                current_pos = current_pos - 26
                Dim numm As Decimal = Me.speed_group.Controls.Count
                Me.speed_group.Controls.RemoveAt(numm - 1)
                Me.speed_group.Controls.RemoveAt(numm - 2)
                group_indices.RemoveAt(group_indices.Count - 1)
            End If
        Next
        value_dtc.Text = String.Empty
        string_enable.Text = String.Empty
        all_signal.DataSource = Nothing
        speed_signal.DataSource = Nothing
        signal_dtc.DataSource = Nothing
        man_pre.DataSource = Nothing
        sf_signal.DataSource = Nothing
        signal_dtc.Text = String.Empty
        man_pre.Text = String.Empty
        sf_signal.Text = String.Empty
    End Sub
    Private Sub save_data()
        If Directory.Exists(project.Text.ToUpper & "\") = True Then

        Else
            Directory.CreateDirectory(project.Text.ToUpper & "\")
        End If

        If System.IO.File.Exists(project.Text.ToUpper & "\" & "db_" & project.Text.ToUpper & "_" & Vari.Text.ToUpper & ".csv") And convert_pressed = True Then
            Dim obj
            For attemp As Decimal = 1 To 4
                Try
                    obj = New System.IO.StreamWriter(project.Text.ToUpper & "\" & "db_" & project.Text.ToUpper & "_" & Vari.Text.ToUpper & ".csv", False, Encoding.GetEncoding("iso-8859-1"))
                    Exit For
                Catch ex As Exception
                    MessageBox.Show("Close database.csv to save data")
                End Try
                If attemp = 4 Then
                    MessageBox.Show("Fail to save database")
                    Return
                End If
            Next
            Dim file_save As New file_handle()
            obj.Write(file_save.save_data)
            obj.Close()
            convert_pressed = False
        ElseIf (Not System.IO.File.Exists(project.Text.ToUpper & "\" & "db_" & project.Text.ToUpper & "_" & Vari.Text.ToUpper & ".csv")) And convert_pressed = True Then
            Dim fs As FileStream = File.Create(project.Text.ToUpper & "\" & "db_" & project.Text.ToUpper & "_" & Vari.Text.ToUpper & ".csv")
            Dim file_save As New file_handle()
            Dim data As Byte() = Encoding.GetEncoding("iso-8859-1").GetBytes(file_save.save_data())
            fs.Write(data, 0, data.Length)
            fs.Close()
            convert_pressed = False
        End If
    End Sub

    Private Sub GroupBox2_Leave(sender As Object, e As EventArgs) Handles GroupBox2.Leave
        If value_dtc.Text <> "" Or string_enable.Text <> "" Then
            Dim temper_signal As mapped_rx_signal = special.Find(Function(x) x.Name = signal_dtc.Text)
            Try
                temper_signal.raw_value = CDec(value_dtc.Text)
            Catch ex As Exception
                value_dtc.BackColor = Color.Red
                console.Text += "- Invalid raw value" & vbCrLf
                Return
            End Try

            If string_enable.Text <> "" Then
                If check_hex_string(string_enable.Text) = False Then
                    string_enable.BackColor = Color.Red
                    console.Text += "- Invalid string" & vbCrLf
                    Return
                End If
                temper_signal.enable_string = string_enable.Text
            Else
                temper_signal.enable_string = ""
            End If

            temper_signal.additional = True

            mandatory.Add(temper_signal)
            man_pre.DataSource = mandatory.Select(Function(x) x.Name).ToList
            console.Text += "- " & "signal " & temper_signal.Name & " is enabled successfully" & vbCrLf
            value_dtc.BackColor = System.Drawing.SystemColors.Window
            string_enable.BackColor = System.Drawing.SystemColors.Window
            convert_pressed = False
        Else
            console.Text += "- " & "some textbox is empty. Failed to add signal " & signal_dtc.Text & vbCrLf
        End If
    End Sub

    Public Function check_hex_string(input As String) As Boolean
        If (input.Length Mod 2) = 0 And input.ToUpper.StartsWith("2E") And input.Length > 6 Then
            Try
                Dim target As Byte() = Enumerable.Range(0, input.Length).Where(Function(x) (x Mod 2) = 0).Select(Function(x) Convert.ToByte(input.Substring(x, 2), 16)).ToArray
                Return True
            Catch ex As Exception
                Return False
            End Try
        Else
            Return False
        End If
    End Function
    Public Function check_value(input As String) As Boolean
        Try
            Dim ee = CDec(input)
            Return True
        Catch ex As Exception
            Return False
        End Try
    End Function

    Private Sub Button8_Click(sender As Object, e As EventArgs) Handles Button8.Click
        Dim teee = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments)
    End Sub

    Private Sub Button9_Click(sender As Object, e As EventArgs) Handles Button9.Click
        Dim temper_element = mandatory.Find(Function(x) x.Name = all_signal.Text)
        If temper_element Is Nothing Then
            necessary_sp.Add(special.Find(Function(x) x.Name = all_signal.Text))
        Else
            necessary_sp.Add(temper_element)
        End If
        speed_signal.DataSource = necessary_sp.Select(Function(x) x.Name).ToList
    End Sub

    Private Sub Button11_Click(sender As Object, e As EventArgs) Handles Button11.Click

    End Sub
End Class

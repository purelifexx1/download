Imports Microsoft.Office
Imports Microsoft.Office.Interop
Imports System.IO
Imports System.Text

Public Class file_handle
    Public mandatory As List(Of mapped_rx_signal) = New List(Of mapped_rx_signal)
    Public special As List(Of mapped_rx_signal) = New List(Of mapped_rx_signal)
    Public reference As List(Of rx_message) = New List(Of rx_message)
    Public name_list As List(Of String) = New List(Of String)
    Private Class keyword
        Public keyword_name As String
        Public keyword_unit As String
        Public keyword_physical_value As String
        Public Sub New(input As String())
            MyBase.New()
            keyword_name = input(0)
            keyword_unit = input(1)
            keyword_physical_value = input(2)
        End Sub
    End Class
    Enum selection_import
        project_title
        precondition
        other_signal
        rx_reference
        speed_list
        sp_function
        none_above
    End Enum

    Public Sub New()
        MyBase.New()
    End Sub
    Public Sub New(rx_message As String, mapped_rx_message As String, ByRef result As Boolean)
        MyBase.New()
        mandatory = New List(Of mapped_rx_signal)
        special = New List(Of mapped_rx_signal)
        reference = New List(Of rx_message)
        name_list = New List(Of String)

        Dim sketch As List(Of keyword) = New List(Of keyword)
        Dim fl
        For attemp As Decimal = 1 To 4
            Try
                fl = New System.IO.StreamReader("search.csv", Encoding.GetEncoding("iso-8859-1"))
                Exit For
            Catch ex As Exception
                MessageBox.Show("Close search.csv before importing files")
            End Try
            If attemp = 4 Then
                Form1.console.Text += "- Failed to import search.csv"
                Return
            End If
        Next

        Dim data1 = fl.ReadToEnd.Split(vbCrLf)

        Dim dumm As Boolean = False
        For Each part As String In data1
            Dim added_row(2) As String
            If dumm = False Then
                'Dim keyword_index = part.Replace(vbLf, "").ToUpper.Split(",")

                dumm = True
            Else
                If part <> vbLf Then

                    Array.Copy(part.Replace(vbLf, "").ToUpper.Split(","), added_row, part.Replace(vbLf, "").ToUpper.Split(",").Length)
                    sketch.Add(New keyword(added_row))
                End If
            End If
        Next
        fl.Close()

        Dim file_object
        For attemp As Decimal = 1 To 4
            Try
                file_object = New System.IO.StreamReader(mapped_rx_message, Encoding.GetEncoding("iso-8859-1"))
                Exit For
            Catch ex As Exception
                MessageBox.Show("Close mapped rx message file before importing files")
            End Try
            If attemp = 4 Then
                Form1.console.Text += "- Failed to import mapped rx message file" & vbCrLf
                Return
            End If
        Next

        Dim lines As String() = file_object.ReadToEnd.Split(vbCrLf)
        Dim dummy As Boolean = True
        For Each line As String In lines
            If line = "" Then
                Exit For
            ElseIf dummy = False And line <> vbLf Then
                Dim components As String() = line.Replace(vbLf, "").Split(",")
                If components.Count < 13 Then
                    MessageBox.Show("Invalid mapped_rx_file format")
                    result = False
                    Return
                End If

                Dim htt As keyword = sketch.Find(Function(x) components(0).ToUpper.Contains(x.keyword_name) And components(12).ToUpper.Contains(x.keyword_unit))
                Dim kt As New mapped_rx_signal(components, 0)

                If htt Is Nothing Then
                    special.Add(kt)
                Else
                    If htt.keyword_physical_value = "" Then
                        htt.keyword_physical_value = "0"
                    End If
                    kt.raw_value = (CDec(htt.keyword_physical_value) - kt.offset) / kt.factor
                    mandatory.Add(kt)
                End If
            ElseIf dummy = True Then
                If (Not line.Contains("Name")) Or (Not line.Contains("Message")) Or (Not line.Contains("Factor")) Or (Not line.Contains("Offset")) Or (Not line.Contains("Unit")) Then
                    MessageBox.Show("Invalid mapped_rx_file format")
                    result = False
                    Return
                End If
            End If
            dummy = False
        Next
        file_object.Close()
        '''''''''''''''''''''''''''''''''''''''''''''

        Dim file_object1
        For attemp As Decimal = 1 To 4
            Try
                file_object1 = New System.IO.StreamReader(rx_message, Encoding.GetEncoding("iso-8859-1"))
                Exit For
            Catch ex As Exception
                MessageBox.Show("Close rx message file before importing files")
            End Try
            If attemp = 4 Then
                Form1.console.Text += "- Failed to import rx message file" & vbCrLf
                Return
            End If
        Next

        lines = file_object1.ReadToEnd().Split(vbCrLf)
        dummy = True
        For Each line As String In lines
            If line = "" Then
                Exit For
            ElseIf dummy = False And line <> vbLf Then
                Dim components As String() = line.Replace(vbLf, "").Split(",")
                If components.Count < 7 Then
                    MessageBox.Show("Invalid rx_file format")
                    result = False
                    Return
                End If
                reference.Add(New rx_message(components))
            ElseIf dummy = True Then
                If (Not line.Contains("Name")) Or (Not line.Contains("ID")) Or (Not line.Contains("Transmitter")) Then
                    MessageBox.Show("Invalid rx_file format")
                    result = False
                    Return
                End If
            End If
            dummy = False
        Next
        file_object1.Close()
    End Sub

    Public Sub New(prirate_dbc As String, public_dbc As String, keyword_for_prirate As String, keyword_for_public As String)

        Dim sketch As List(Of keyword) = New List(Of keyword)
        Dim fl
        For attemp As Decimal = 1 To 4
            Try
                fl = New System.IO.StreamReader("search.csv", Encoding.GetEncoding("iso-8859-1"))
                Exit For
            Catch ex As Exception
                MessageBox.Show("Close search.csv before importing files")
            End Try
            If attemp = 4 Then
                Form1.console.Text += "- Failed to import search.csv"
                Return
            End If
        Next
        Dim data1 = fl.ReadToEnd.Split(vbCrLf)
        Dim dumm As Boolean = False
        For Each part As String In data1
            Dim added_row(2) As String
            If dumm = False Then
                'Dim keyword_index = part.Replace(vbLf, "").ToUpper.Split(",")
                dumm = True
            Else
                If part <> vbLf Then
                    Array.Copy(part.Replace(vbLf, "").ToUpper.Split(","), added_row, part.Replace(vbLf, "").ToUpper.Split(",").Length)
                    sketch.Add(New keyword(added_row))
                End If
            End If
        Next
        fl.Close()


        Dim file_object
        For attemp As Decimal = 1 To 4
            Try
                file_object = New System.IO.StreamReader(prirate_dbc, Encoding.GetEncoding("iso-8859-1"))
                Exit For
            Catch ex As Exception
                MessageBox.Show("Close prirate-can dbc file before importing files")
            End Try
            If attemp = 4 Then
                Form1.console.Text += "- Failed to import prirate-can dbc file" & vbCrLf
                Return
            End If
        Next

        Dim lines As String() = file_object.ReadToEnd().Split(vbCrLf)
        Dim current_message As String
        Dim current_id As String
        Dim check_node As String
        Dim env As Boolean = False
        For Each line As String In lines
            Dim components As String() = line.Replace(vbLf, "").Split(" ")
            If components(0) = "BU_:" Then
                check_node = Array.Find(components, Function(s) s.Contains("MPC") Or s.Contains("FCM") Or s.Contains("FVCM"))
            ElseIf components(0) = "BO_" Then
                If components.Last.Contains(check_node) Then
                    env = True
                End If
                current_id = Convert.ToInt32(components(1)).ToString("X")
                current_message = components(2).Replace(":", "")
            ElseIf components(1) = "SG_" And env = True Then
                Dim htt As keyword = sketch.Find(Function(x) components(2).ToUpper.Contains(x.keyword_name) And components(7).Replace(ControlChars.Quote, "").ToUpper.Contains(x.keyword_unit))
                Dim kt As New mapped_rx_signal(components, 1, 0)
                kt.Message = current_message
                kt.ID = current_id
                kt.scope = "prirate"
                kt.signal_type = "Rx message"
                If htt Is Nothing Then
                    special.Add(kt)
                Else
                    If htt.keyword_physical_value = "" Then
                        htt.keyword_physical_value = "0"
                    End If
                    kt.raw_value = (CDec(htt.keyword_physical_value) - kt.offset) / kt.factor
                    mandatory.Add(kt)
                End If
            ElseIf components(1) = "SG_" And components.Last.Contains(check_node) Then
                Dim htt As keyword = sketch.Find(Function(x) components(2).ToUpper.Contains(x.keyword_name) And components(7).Replace(ControlChars.Quote, "").ToUpper.Contains(x.keyword_unit))
                Dim kt As New mapped_rx_signal(components, 1, 0)
                kt.Message = current_message
                kt.ID = current_id
                kt.scope = "prirate"
                kt.signal_type = "Tx message"
                If htt Is Nothing Then
                    special.Add(kt)
                Else
                    If htt.keyword_physical_value = "" Then
                        htt.keyword_physical_value = "0"
                    End If
                    kt.raw_value = (CDec(htt.keyword_physical_value) - kt.offset) / kt.factor
                    mandatory.Add(kt)
                End If
            ElseIf line = "" Then
                env = False
            End If

        Next
    End Sub

    Public Function save_data() As String
        Dim total_string As String = ""
        total_string += "#Start of database" & vbCrLf
        total_string += "Project,Variant,Release,Version" & vbCrLf
        total_string += Form1.project.Text & "," & Form1.Vari.Text & "," & Form1.release.Text & "," & Form1.ver.Text & vbCrLf & vbCrLf

        total_string += "List of precondition" & vbCrLf
        total_string += "Name,Message,Multiplexing/Group,Startbit,Length [Bit],Byte Order,Value Type,Initial Value,Factor,Offset,Minimum,Maximum,Unit,Raw Value, Enable String" & vbCrLf
        For Each map_rx As mapped_rx_signal In Form1.mandatory
            total_string += map_rx.Name & "," & map_rx.Message & "," & map_rx.multiplexing_group & "," & CStr(map_rx.startbit) & "," & CStr(map_rx.Length) & "," & map_rx.byte_order & "," & map_rx.value_type & ","
            total_string += CStr(map_rx.initial_value) & "," & CStr(map_rx.factor) & "," & CStr(map_rx.offset) & "," & CStr(map_rx.minimun) & "," & CStr(map_rx.maximum) & "," & map_rx.unit
            If map_rx.additional = True Then
                total_string += "," & CStr(map_rx.raw_value) & "," & map_rx.enable_string & vbCrLf
            Else
                total_string += "," & CStr(map_rx.raw_value) & vbCrLf
            End If
        Next

        total_string += vbCrLf & "List of other signals" & vbCrLf
        total_string += "Name,Message,Multiplexing/Group,Startbit,Length [Bit],Byte Order,Value Type,Initial Value,Factor,Offset,Minimum,Maximum,Unit" & vbCrLf
        For Each map_rx As mapped_rx_signal In Form1.special
            total_string += map_rx.Name & "," & map_rx.Message & "," & map_rx.multiplexing_group & "," & CStr(map_rx.startbit) & "," & CStr(map_rx.Length) & "," & map_rx.byte_order & "," & map_rx.value_type & ","
            total_string += CStr(map_rx.initial_value) & "," & CStr(map_rx.factor) & "," & CStr(map_rx.offset) & "," & CStr(map_rx.minimun) & "," & CStr(map_rx.maximum) & "," & map_rx.unit & vbCrLf
        Next

        total_string += vbCrLf & "List of rx signal" & vbCrLf
        total_string += "Name,ID,Transmitter" & vbCrLf
        For Each rx_signal As rx_message In Form1.reference
            total_string += rx_signal.Name & "," & rx_signal.ID & "," & rx_signal.transmiter & vbCrLf
        Next

        total_string += vbCrLf & "List of necessary speed" & vbCrLf
        Dim temper As Decimal = 1
        For Each sp As Decimal In Form1.listof_speed
            total_string += "speed " & CStr(temper) & "," & CStr(sp) & vbCrLf
            temper = temper + 1
        Next

        total_string += vbCrLf & "List of supported function" & vbCrLf
        total_string += "Function,Signal,Scenario,Enable Value,Disable Value,High Level,Low Level,Press Counter,Enable Duration,Disable Duration,Enable String,Disable String,Security Level" & vbCrLf
        For Each sp_function As mapped_rx_signal In Form1.supported_function
            Select Case (sp_function.scenario)
                Case 1
                    total_string += sp_function.function_type & "," & sp_function.Name & "," & CStr(sp_function.scenario) & "," & sp_function.up_level & "," & sp_function.down_level & vbCrLf
                Case 2
                    total_string += sp_function.function_type & "," & sp_function.Name & "," & CStr(sp_function.scenario) & ",,," & sp_function.up_level & "," & sp_function.down_level & "," &
                        sp_function.press_counter & "," & sp_function.enable_duration & "," & sp_function.disable_duration & vbCrLf
                Case 3
                    total_string += sp_function.function_type & "," & sp_function.Name & "," & CStr(sp_function.scenario) & ",,,,,,,," & sp_function.enable_string & "," & sp_function.disable_string _
                        & "," & sp_function.security & vbCrLf
                Case 4
                    total_string += sp_function.function_type & "," & sp_function.Name & "," & CStr(sp_function.scenario) & "," & sp_function.up_level & "," & sp_function.down_level &
                        ",,,,,," & sp_function.enable_string & "," & sp_function.disable_string & "," & sp_function.security & vbCrLf
                Case 5
                    total_string += sp_function.function_type & "," & sp_function.Name & "," & CStr(sp_function.scenario) & ",,," & sp_function.up_level & "," & sp_function.down_level & "," &
                        sp_function.press_counter & "," & sp_function.enable_duration & "," & sp_function.disable_duration & "," & sp_function.enable_string & "," & sp_function.disable_string &
                        "," & sp_function.security & vbCrLf
            End Select
        Next
        total_string += "#End of database"

        Return total_string
    End Function
    Public Sub import_file()
        Dim file_object
        For attemp As Decimal = 1 To 4
            Try
                file_object = New System.IO.StreamReader("Database.csv", Encoding.GetEncoding("iso-8859-1"))
                Exit For
            Catch ex As Exception
                MessageBox.Show("Close datebase before importing data")
            End Try
            If attemp = 4 Then
                Form1.console.Text += "- Failed to import Database.csv" & vbCrLf
                Return
            End If
        Next

        Dim lines As String() = file_object.ReadToEnd.Split(vbCrLf)
        Dim selection As selection_import = selection_import.none_above
        Dim current As Decimal = 0
        For Each line As String In lines
            Dim components(17) As String
            Dim row As String() = line.Replace(vbLf, "").Split(",")
            Array.Copy(row, components, row.Length)
            If row(0) <> "" And row(0) <> "#End of database" Then
                Select Case (selection)
                    Case selection_import.project_title
                        Form1.project.Text = components(0)
                        Form1.Vari.Text = components(1)
                        Form1.release.Text = components(2)
                        Form1.ver.Text = components(3)
                    Case selection_import.precondition
                        If components(0) <> "Name" And components(14) = "" Then
                            Form1.mandatory.Add(New mapped_rx_signal(components, 2))
                        ElseIf components(0) <> "Name" And components(14) <> "" Then
                            Form1.mandatory.Add(New mapped_rx_signal(components, 1))
                        End If
                    Case selection_import.other_signal
                        If components(0) <> "Name" Then
                            Form1.special.Add(New mapped_rx_signal(components, 0))
                        End If
                    Case selection_import.rx_reference
                        If components(0) <> "Name" Then
                            Form1.reference.Add(New rx_message(components, 0))
                        End If
                    Case selection_import.speed_list
                        If current <> 0 Then
                            add_speed()
                        End If
                        Form1.speed_group.Controls.Item(Form1.group_indices(current)).Text = components(1)
                        current = current + 1
                    Case selection_import.sp_function
                        Dim new_function As mapped_rx_signal
                        If components(0) <> "Function" Then
                            Select Case CDec(components(2))
                                Case 1
                                    new_function = Form1.special.Find(Function(x) x.Name = components(1))
                                    new_function.scenario = 1
                                    new_function.up_level = components(3)
                                    new_function.down_level = components(4)
                                    new_function.function_type = components(0)
                                    Form1.supported_function.Add(new_function)
                                Case 2
                                    new_function = Form1.special.Find(Function(x) x.Name = components(1))
                                    new_function.scenario = 2
                                    new_function.up_level = components(5)
                                    new_function.down_level = components(6)
                                    new_function.enable_duration = components(8)
                                    new_function.disable_duration = components(9)
                                    new_function.press_counter = components(7)
                                    new_function.function_type = components(0)
                                    Form1.supported_function.Add(new_function)
                                Case 3
                                    new_function = Form1.special.Find(Function(x) x.Name = components(1))
                                    new_function.scenario = 3
                                    new_function.enable_string = components(10)
                                    new_function.disable_string = components(11)
                                    new_function.security = components(12)
                                    new_function.function_type = components(0)
                                    Form1.supported_function.Add(new_function)
                                Case 4
                                    new_function = Form1.special.Find(Function(x) x.Name = components(1))
                                    new_function.scenario = 4
                                    new_function.enable_string = components(10)
                                    new_function.disable_string = components(11)
                                    new_function.security = components(12)
                                    new_function.up_level = components(3)
                                    new_function.down_level = components(4)
                                    new_function.function_type = components(0)
                                    Form1.supported_function.Add(new_function)
                                Case 5
                                    new_function = Form1.special.Find(Function(x) x.Name = components(1))
                                    new_function.scenario = 5
                                    new_function.enable_string = components(10)
                                    new_function.disable_string = components(11)
                                    new_function.security = components(12)
                                    new_function.up_level = components(5)
                                    new_function.down_level = components(6)
                                    new_function.press_counter = components(7)
                                    new_function.enable_duration = components(8)
                                    new_function.disable_duration = components(9)
                                    new_function.function_type = components(0)
                                    Form1.supported_function.Add(new_function)
                            End Select
                        End If
                End Select
            End If
            If row(0) <> "" And selection = selection_import.none_above Then
                Dim current_line As String = line.Replace(vbLf, "")
                If current_line.StartsWith("Project") Then
                    selection = selection_import.project_title
                ElseIf current_line.StartsWith("List of precondition") Then
                    selection = selection_import.precondition
                ElseIf current_line.StartsWith("List of other") Then
                    selection = selection_import.other_signal
                ElseIf current_line.StartsWith("List of rx") Then
                    selection = selection_import.rx_reference
                ElseIf current_line.StartsWith("List of necessary") Then
                    selection = selection_import.speed_list
                ElseIf current_line.StartsWith("List of supported") Then
                    selection = selection_import.sp_function
                End If
            ElseIf row(0) = "" And selection <> selection_import.none_above Then
                selection = selection_import.none_above
            End If
        Next
        file_object.Close()
        Form1.man_pre.DataSource = Form1.mandatory.Select(Function(x) x.Name).ToList
        Form1.sf_signal.DataSource = Form1.supported_function.Select(Function(x) x.Name).ToList
        Form1.signal_dtc.DataSource = Form1.special.Select(Function(x) x.Name).ToList
    End Sub
    Private Sub add_speed()
        Form1.speed_th = Form1.speed_th + 1
        Dim new_speed As New TextBox
        Dim new_speed_label As New Label
        new_speed.Name = "speed_" & CStr(Form1.speed_th) & "th"
        new_speed_label.Name = "speed" & CStr(Form1.speed_th)
        new_speed_label.Text = "speed " & CStr(Form1.speed_th)


        new_speed.Location = New Point(87, Form1.current_pos + 26)
        new_speed.Size = New Size(75, 20)
        new_speed_label.Location = New Point(21, Form1.current_pos + 26)
        new_speed_label.Size = New Size(53, 13)
        new_speed.Visible = True
        new_speed_label.Visible = True
        Form1.current_pos = Form1.current_pos + 26

        Form1.speed_group.Controls.Add(new_speed)
        Form1.group_indices.Add(Form1.speed_group.Controls.Count - 1)
        Form1.speed_group.Controls.Add(new_speed_label)
        Form1.Refresh()
    End Sub

End Class

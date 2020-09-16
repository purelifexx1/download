Imports System.Linq
Imports System.Xml
Imports System.Xml.Linq
Public Class Form2
    Private mandatory As List(Of mapped_rx_signal) = New List(Of mapped_rx_signal)
    Private special As List(Of mapped_rx_signal) = New List(Of mapped_rx_signal)
    Private reference As List(Of rx_message) = New List(Of rx_message)
    Private name_list As List(Of String) = New List(Of String)
    Dim disable_tab(3) As Decimal
    Dim selection As Decimal = 1
    Public Sub New()
        InitializeComponent()
        Me.mandatory = Form1.mandatory
        Me.special = Form1.special
        Me.name_list = Form1.name_list
        Dim list_function As List(Of mapped_rx_signal) = Form1.special.FindAll(Function(x) x.Name.ToUpper.Contains("LDW") Or x.Name.ToUpper.Contains("LKS") Or x.Name.ToUpper.Contains("TJA") Or x.Name.ToUpper.Contains("RDP") _
                                                                                        Or x.Name.ToUpper.Contains("ELK") Or x.Name.ToUpper.Contains("HMA") Or x.Name.ToUpper.Contains("SLA"))
        signal_1.DataSource = list_function.Select(Function(x) x.Name).ToList
        signal_2.DataSource = list_function.Select(Function(x) x.Name).ToList
        signal_3.DataSource = list_function.Select(Function(x) x.Name).ToList
        signal_4.DataSource = list_function.Select(Function(x) x.Name).ToList
        signal_5.DataSource = list_function.Select(Function(x) x.Name).ToList

        Dim security_level As String() = New String() {"EnvLogInLevel1", "EnvLogInLevel2", "EnvLogInLevel3"}
        security_3.DataSource = security_level
        security_4.DataSource = security_level
        security_5.DataSource = security_level
    End Sub
    Private Sub Form2_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        normal.Checked = True
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim new_function As mapped_rx_signal
        Try
            Select Case selection
                Case 1
                    new_function = Form1.special.Find(Function(x) x.Name = signal_1.Text)
                    new_function.scenario = 1
                    If (Not Form1.check_value(enable_1.Text)) Or (Not Form1.check_value(disable_1.Text)) Then
                        Form1.console.Text += "- Failed to add function " & Me.Text & vbCrLf
                        Me.Close()
                        Return
                    End If
                    new_function.up_level = enable_1.Text
                    new_function.down_level = disable_1.Text
                    new_function.function_type = Me.Text
                    Form1.supported_function.Add(new_function)
                Case 2
                    new_function = Form1.special.Find(Function(x) x.Name = signal_2.Text)
                    new_function.scenario = 2
                    If (Not Form1.check_value(enable_2.Text)) Or (Not Form1.check_value(disable_2.Text)) Or (Not Form1.check_value(high_2.Text)) Or (Not Form1.check_value(low_2.Text)) Or (Not Form1.check_value(press_2.Text)) Then
                        Form1.console.Text += "- Failed to add function " & Me.Text & vbCrLf
                        Me.Close()
                        Return
                    End If
                    new_function.up_level = high_2.Text
                    new_function.down_level = low_2.Text
                    new_function.enable_duration = enable_2.Text
                    new_function.disable_duration = disable_2.Text
                    new_function.press_counter = press_2.Text
                    new_function.function_type = Me.Text
                    Form1.supported_function.Add(new_function)
                Case 3
                    new_function = Form1.special.Find(Function(x) x.Name = signal_3.Text)
                    new_function.scenario = 3
                    If (Not Form1.check_hex_string(enable_3.Text)) Or (Not Form1.check_hex_string(disable_3.Text)) Then
                        Form1.console.Text += "- Failed to add function " & Me.Text & vbCrLf
                        Me.Close()
                        Return
                    End If
                    new_function.enable_string = enable_3.Text
                    new_function.disable_string = disable_3.Text
                    new_function.security = security_3.Text
                    new_function.function_type = Me.Text
                    Form1.supported_function.Add(new_function)
                Case 4
                    new_function = Form1.special.Find(Function(x) x.Name = signal_4.Text)
                    new_function.scenario = 4
                    If (Not Form1.check_value(enablev_4.Text)) Or (Not Form1.check_value(disablev_4.Text)) Or (Not Form1.check_hex_string(enables_4.Text)) Or
                        (Not Form1.check_hex_string(disables_4.Text)) Then
                        Form1.console.Text += "- Failed to add function " & Me.Text & vbCrLf
                        Me.Close()
                        Return
                    End If
                    new_function.enable_string = enables_4.Text
                    new_function.disable_string = disables_4.Text
                    new_function.security = security_4.Text
                    new_function.up_level = enablev_4.Text
                    new_function.down_level = disablev_4.Text
                    new_function.function_type = Me.Text
                    Form1.supported_function.Add(new_function)
                Case 5
                    new_function = Form1.special.Find(Function(x) x.Name = signal_5.Text)
                    new_function.scenario = 5
                    If (Not Form1.check_value(enabled_5.Text)) Or (Not Form1.check_value(disabled_5.Text)) Or (Not Form1.check_value(high_5.Text)) Or (Not Form1.check_value(low_5.Text)) Or
                        (Not Form1.check_value(press_5.Text)) Or (Not Form1.check_hex_string(enables_5.Text)) Or (Not Form1.check_hex_string(disables_5.Text)) Then
                        Form1.console.Text += "- Failed to add function " & Me.Text & vbCrLf
                        Me.Close()
                        Return
                    End If
                    new_function.enable_string = enables_5.Text
                    new_function.disable_string = disables_5.Text
                    new_function.security = security_5.Text
                    new_function.up_level = high_5.Text
                    new_function.down_level = low_5.Text
                    new_function.press_counter = press_5.Text
                    new_function.enable_duration = enabled_5.Text
                    new_function.disable_duration = disabled_5.Text
                    new_function.function_type = Me.Text
                    Form1.supported_function.Add(new_function)
            End Select
            Form1.console.Text += "- function " & Me.Text & " is added successfully" & vbCrLf
            Form1.sf_signal.DataSource = Form1.supported_function.Select(Function(x) x.Name).ToList
        Catch ex As Exception
            Form1.console.Text += "- System error: " & ex.ToString & vbCrLf
        End Try
        Me.Close()
    End Sub

    Private Sub tick_CheckedChanged(sender As Object, e As EventArgs) Handles normal.CheckedChanged, even.CheckedChanged, str.CheckedChanged
        If normal.Checked = True And even.Checked = True And str.Checked = True Then
            MessageBox.Show("cant all 3 be ticked")
            even.Checked = False
        ElseIf normal.Checked = False And even.Checked = False And str.Checked = False Then
            ' empty
        Else
            If normal.Checked = True And even.Checked = False And str.Checked = False Then
                Scenario1()
                selection = 1
            ElseIf normal.Checked = False And even.Checked = True And str.Checked = False Then
                Scenario2()
                selection = 2
            ElseIf normal.Checked = False And even.Checked = False And str.Checked = True Then
                Scenario3()
                selection = 3
            ElseIf normal.Checked = True And even.Checked = False And str.Checked = True Then
                Scenario4()
                selection = 4
            ElseIf normal.Checked = False And even.Checked = True And str.Checked = True Then
                Scenario5()
                selection = 5
            ElseIf normal.Checked = True And even.Checked = True And str.Checked = False Then
                MessageBox.Show("cant check normal and event")
                even.Checked = False
            End If
        End If
    End Sub
#Region "tab display"
    Private Sub Scenario1()
        Me.Size = New Size(417, 221)
        tab.Size = New Size(367, 121)
        disable_tab(0) = 1
        disable_tab(1) = 2
        disable_tab(2) = 3
        disable_tab(3) = 4
        tab.SelectTab(0)
    End Sub
    Private Sub Scenario2()
        Me.Size = New Size(417, 298)
        tab.Size = New Size(377, 212)
        disable_tab(0) = 0
        disable_tab(1) = 2
        disable_tab(2) = 3
        disable_tab(3) = 4
        tab.SelectTab(1)
    End Sub
    Private Sub Scenario3()
        Me.Size = New Size(417, 244)
        tab.Size = New Size(367, 156)
        disable_tab(0) = 1
        disable_tab(1) = 0
        disable_tab(2) = 3
        disable_tab(3) = 4
        tab.SelectTab(2)
    End Sub
    Private Sub Scenario4()
        Me.Size = New Size(417, 279)
        tab.Size = New Size(367, 197)
        disable_tab(0) = 1
        disable_tab(1) = 2
        disable_tab(2) = 0
        disable_tab(3) = 4
        tab.SelectTab(3)
    End Sub
    Private Sub Scenario5()
        Me.Size = New Size(417, 357)
        tab.Size = New Size(367, 274)
        disable_tab(0) = 1
        disable_tab(1) = 2
        disable_tab(2) = 3
        disable_tab(3) = 0
        tab.SelectTab(4)
    End Sub

    Private Sub tab_Selecting(sender As Object, e As TabControlCancelEventArgs) Handles tab.Selecting
        If e.TabPageIndex = disable_tab(0) Or e.TabPageIndex = disable_tab(1) Or e.TabPageIndex = disable_tab(2) Or e.TabPageIndex = disable_tab(3) Then
            e.Cancel = True
        End If
    End Sub
#End Region

End Class
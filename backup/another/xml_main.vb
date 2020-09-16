Imports System.Xml
Imports System.Xml.Linq
Imports System.Linq
Public Class xml_main
    Public external_ref As XElement
    Dim test_module As XElement = New XElement("testmodule")
    Dim Wait_default As XElement '5ms
    Public Sub New()
        MyBase.New()
        Dim temper As New List(Of XAttribute)({New XAttribute("type", "doors"), New XAttribute("owner", "TAE - DOORS extension"), New XAttribute("title", "CHERY_LabT_SIT")})
        external_ref = create_opentag("externalref", temper)
        Wait_default = create_opentag("wait", New List(Of XAttribute)({New XAttribute("time", "5"), New XAttribute("title", "wait")}))
    End Sub
    Public Function xml_construct_precondition(mandatory As List(Of mapped_rx_signal), special As List(Of mapped_rx_signal)) As XElement
        Dim test_group_precondition_mandatory As List(Of XElement) = New List(Of XElement)
        Dim test_group_precondition_special As List(Of XElement) = New List(Of XElement)
        test_group_precondition_mandatory.Add(external_ref)
        test_group_precondition_special.Add(external_ref)
        For Each mapped_rx_part As mapped_rx_signal In mandatory
            If mapped_rx_part.additional = True And mapped_rx_part.enable_string <> "" Then
                test_group_precondition_special.Add(create_testcase(mapped_rx_part, mapped_rx_part.raw_value * mapped_rx_part.factor + mapped_rx_part.offset, mapped_rx_part.enable_string))
            ElseIf mapped_rx_part.additional = True And mapped_rx_part.enable_string = "" Then
                test_group_precondition_special.Add(create_testcase(mapped_rx_part, mapped_rx_part.raw_value * mapped_rx_part.factor + mapped_rx_part.offset))
            Else
                test_group_precondition_mandatory.Add(create_testcase(mapped_rx_part, mapped_rx_part.raw_value * mapped_rx_part.factor + mapped_rx_part.offset))
            End If
        Next

        Return create_tag("testgroup", New XAttribute("title", "Precondition"), New List(Of XElement)({external_ref, create_tag("testgroup", New XAttribute("title", "mandatory"), test_group_precondition_mandatory), create_tag("testgroup", New XAttribute("title", "special"), test_group_precondition_special)}))
    End Function
    Public Function xml_construct_speed(mandatory As List(Of mapped_rx_signal), listof_speed As List(Of Decimal)) As XElement
        Dim speed As List(Of XElement) = New List(Of XElement)
        speed.Add(external_ref)
        For Each current_speed As Decimal In listof_speed
            Dim dummy As List(Of XElement) = New List(Of XElement)
            dummy.Add(external_ref)
            For Each element As mapped_rx_signal In Form1.necessary_sp
                dummy.Add(create_testcase(element, current_speed))
            Next
            speed.Add(create_tag("testgroup", New XAttribute("title", "Both speeds = " & CStr(current_speed) & "kph"), dummy))
        Next
        Return create_tag("testgroup", New XAttribute("title", "speed"), speed)
    End Function
    Public Function xml_construct_function() As XElement
        Dim testgroup_function As List(Of XElement) = New List(Of XElement)
        testgroup_function.Add(external_ref)
        For Each select_function As mapped_rx_signal In Form1.supported_function
            Dim temper_testgroup As List(Of XElement) = New List(Of XElement)
            Select Case (select_function.scenario)
                Case 1
                    testgroup_function.Add(create_tag("testgroup", New XAttribute("title", "Enable " & select_function.function_type & " function"),
                        New List(Of XElement)({external_ref, create_testcase(select_function, select_function.up_level)})))
                    testgroup_function.Add(create_tag("testgroup", New XAttribute("title", "Disable " & select_function.function_type & " function"),
                        New List(Of XElement)({external_ref, create_testcase(select_function, select_function.down_level)})))
                Case 2
                    testgroup_function.Add(create_tag("testgroup", New XAttribute("title", "Enable " & select_function.function_type & " function"),
                        New List(Of XElement)({external_ref, create_testcase(select_function, select_function.up_level, select_function.down_level, select_function.enable_duration, select_function.press_counter)})))
                    testgroup_function.Add(create_tag("testgroup", New XAttribute("title", "Disable " & select_function.function_type & " function"),
                        New List(Of XElement)({external_ref, create_testcase(select_function, select_function.up_level, select_function.down_level, select_function.disable_duration, select_function.press_counter)})))
                Case 3
                    temper_testgroup.AddRange(string_testcase(select_function.enable_string, select_function.security, select_function.function_type, "enable"))
                    testgroup_function.Add(create_tag("testgroup", New XAttribute("title", "Enable " & select_function.function_type & " function"), temper_testgroup))
                    temper_testgroup = New List(Of XElement)
                    temper_testgroup.AddRange(string_testcase(select_function.disable_string, select_function.security, select_function.function_type, "disable"))
                    testgroup_function.Add(create_tag("testgroup", New XAttribute("title", "Disable " & select_function.function_type & " function"), temper_testgroup))
                Case 4
                    temper_testgroup.AddRange(string_testcase(select_function.enable_string, select_function.security, select_function.function_type, "enable"))
                    temper_testgroup.Add(create_testcase(select_function, select_function.up_level))
                    testgroup_function.Add(create_tag("testgroup", New XAttribute("title", "Enable " & select_function.function_type & " function"), temper_testgroup))
                    temper_testgroup = New List(Of XElement)
                    temper_testgroup.AddRange(string_testcase(select_function.disable_string, select_function.security, select_function.function_type, "disable"))
                    temper_testgroup.Add(create_testcase(select_function, select_function.down_level))
                    testgroup_function.Add(create_tag("testgroup", New XAttribute("title", "Disable " & select_function.function_type & " function"), temper_testgroup))
                Case 5
                    temper_testgroup.AddRange(string_testcase(select_function.enable_string, select_function.security, select_function.function_type, "enable"))
                    temper_testgroup.Add(create_testcase(select_function, select_function.up_level, select_function.down_level, select_function.enable_duration, select_function.press_counter))
                    testgroup_function.Add(create_tag("testgroup", New XAttribute("title", "Enable " & select_function.function_type & " function"), temper_testgroup))
                    temper_testgroup = New List(Of XElement)
                    temper_testgroup.AddRange(string_testcase(select_function.disable_string, select_function.security, select_function.function_type, "disable"))
                    temper_testgroup.Add(create_testcase(select_function, select_function.up_level, select_function.down_level, select_function.disable_duration, select_function.press_counter))
                    testgroup_function.Add(create_tag("testgroup", New XAttribute("title", "Disable " & select_function.function_type & " function"), temper_testgroup))
            End Select
        Next

        Return create_tag("testgroup", New XAttribute("title", "Function"), testgroup_function)
        'grap in two test group: enable [Name] function, disable [Name] function
    End Function
    Public Function create_testcase(map_rx As mapped_rx_signal, physical_value As Decimal) As XElement
        Dim dummy As List(Of XElement) = New List(Of XElement)
        Dim set_tag As XElement = create_set_tag("E_pubc_" & map_rx.transmitter & "_" & map_rx.Message & "_" & map_rx.Name & "_Rv", "-", CStr((physical_value - map_rx.offset) / map_rx.factor))
        dummy.Add(set_tag)
        dummy.Add(Wait_default)
        set_tag = create_set_tag("E_pubc_" & map_rx.transmitter & "_" & map_rx.Message & "_" & map_rx.signal_type.Substring(0, 2).ToLower, "-", "1")
        dummy.Add(set_tag)
        dummy.Add(Wait_default)
        set_tag = create_set_tag("E_pubc_" & map_rx.transmitter & "_" & map_rx.Message & "_" & map_rx.signal_type.Substring(0, 2).ToLower, "-", "0")
        dummy.Add(set_tag)
        Return create_tag("testcase", New List(Of XAttribute)({New XAttribute("title", map_rx.signal_type & map_rx.Message & "(ID:" & map_rx.ID & ")::" & map_rx.Name & ": " & CStr(physical_value)), New XAttribute("ident", "-")}), dummy)
    End Function

    Public Function create_testcase(map_rx As mapped_rx_signal, physical_value As Decimal, input_string As String) As XElement
        Dim dummy As List(Of XElement) = New List(Of XElement)
        Dim set_tag As XElement = create_set_tag("E_pubc_" & map_rx.transmitter & "_" & map_rx.Message & "_" & map_rx.Name & "_Rv", "-", CStr((physical_value - map_rx.offset) / map_rx.factor))
        dummy.Add(set_tag)
        dummy.Add(Wait_default)
        set_tag = create_set_tag("E_pubc_" & map_rx.transmitter & "_" & map_rx.Message & "_" & map_rx.signal_type.Substring(0, 2).ToLower, "-", "1")
        dummy.Add(set_tag)
        dummy.Add(Wait_default)
        set_tag = create_set_tag("E_pubc_" & map_rx.transmitter & "_" & map_rx.Message & "_" & map_rx.signal_type.Substring(0, 2).ToLower, "-", "0")
        dummy.Add(set_tag)
        dummy.AddRange(string_testcase(input_string, "EnvLogInLevel1", "", "enable"))
        Return create_tag("testcase", New List(Of XAttribute)({New XAttribute("title", map_rx.signal_type & map_rx.Message & "(ID:" & map_rx.ID & ")::" & map_rx.Name & ": " & CStr(physical_value)), New XAttribute("ident", "-")}), dummy)
    End Function
    Public Function create_testcase(map_rx As mapped_rx_signal, high_value As Decimal, low_value As Decimal, duration As Decimal, press_counter As Decimal) As XElement
        Dim dummy As List(Of XElement) = New List(Of XElement)
        Dim set_tag As XElement
        For count As Decimal = 1 To press_counter
            set_tag = create_set_tag("E_pubc_" & map_rx.transmitter & "_" & map_rx.Message & "_" & map_rx.Name & "_Rv", "-", CStr((high_value - map_rx.offset) / map_rx.factor))
            dummy.Add(set_tag)
            dummy.Add(wait_tag(CStr(duration)))
            set_tag = create_set_tag("E_pubc_" & map_rx.transmitter & "_" & map_rx.Message & "_" & map_rx.Name & "_Rv", "-", CStr((low_value - map_rx.offset) / map_rx.factor))
            dummy.Add(set_tag)
            dummy.Add(Wait_default)
        Next
        set_tag = create_set_tag("E_pubc_" & map_rx.transmitter & "_" & map_rx.Message & "_" & map_rx.signal_type.Substring(0, 2).ToLower, "-", "1")
        dummy.Add(set_tag)
        dummy.Add(Wait_default)
        set_tag = create_set_tag("E_pubc_" & map_rx.transmitter & "_" & map_rx.Message & "_" & map_rx.signal_type.Substring(0, 2).ToLower, "-", "0")
        dummy.Add(set_tag)
        Return create_tag("testcase", New List(Of XAttribute)({New XAttribute("title", map_rx.signal_type & map_rx.Message & "(ID:" & map_rx.ID & ")::" & map_rx.Name & ": " & CStr(high_value) & " to " & CStr(low_value) & " in " & CStr(duration) & "ms"), New XAttribute("ident", "-")}), dummy)
    End Function
    Public Function create_testcase_string(input As String, function_enable As String, enable_disable As String) As XElement
        Dim temper_tag As List(Of XElement) = New List(Of XElement)
        temper_tag.Add(create_tag("caplparam", New List(Of XAttribute)({New XAttribute("name", "Request"), New XAttribute("type", "string")}), input))
        temper_tag.Add(create_tag("caplparam", New List(Of XAttribute)({New XAttribute("name", "Response"), New XAttribute("type", "string")}), "6e" & input.Substring(2, 4)))
        temper_tag.Add(create_tag("caplparam", New List(Of XAttribute)({New XAttribute("name", "CompareMode"), New XAttribute("type", "string")}), "Equal"))
        Dim string2e = String.Join(" ", input.ToUpper.Select(Function(x, n) New With {x, n}).GroupBy(Function(x) x.n \ 2, Function(t) t.x).Select(Function(y) New String(y.ToArray())))
        Dim string6e = String.Join(" ", input.Substring(2, 4).ToUpper.Select(Function(x, n) New With {x, n}).GroupBy(Function(x) x.n \ 2, Function(t) t.x).Select(Function(y) New String(y.ToArray())))
        Return create_tag("capltestcase", New List(Of XAttribute)({New XAttribute("name", "RequestResponse"), New XAttribute("title", "Write the string to " & enable_disable & " " & function_enable & " function: " & string2e), New XAttribute("ident", "Positive response is received: 0x6E " & string6e)}), temper_tag)
    End Function
    Public Function string_testcase(input_string As String, security As String, function_enable As String, enable_disable As String) As List(Of XElement)
        Dim tag As List(Of XElement) = New List(Of XElement)
        tag.Add(external_ref)
        tag.Add(create_tag("testcase", New List(Of XAttribute)({New XAttribute("title", "Tester Present is On"), New XAttribute("ident", "-")}), New List(Of XElement)({create_set_tag("EnvTesterPresentOnOff", "", "1"), wait_tag(0)})))
        tag.Add(create_tag("capltestcase", New List(Of XAttribute)({New XAttribute("name", "DiagSessionCtrl"), New XAttribute("title", "Change to Extended session with Service 0x10 03"), New XAttribute("ident", "Positive response is received: 0x50 03 00 32 00 C8")}) _
                           , create_tag("caplparam", New List(Of XAttribute)({New XAttribute("type", "String"), New XAttribute("name", "sessionName")}), "Extended")))
        tag.Add(create_tag("testcase", New List(Of XAttribute)({New XAttribute("title", "Request Seed from the camera 0x27 01"), New XAttribute("ident", "Positive response is received: 0x67 01 .{4}")}), New List(Of XElement)({create_set_tag(security, "", "1"), wait_tag(0)})))
        tag.Add(create_tag("testcase", New List(Of XAttribute)({New XAttribute("title", "Wait for Seed-Key Calculation."), New XAttribute("ident", "-")}), wait_tag(1000)))
        tag.Add(create_tag("testcase", New List(Of XAttribute)({New XAttribute("title", "Send valid Key to the camera : 0x27 02 XX XX XX XX (Where XX XX XX XX is the exact calculated key using seed key algorithm)"), New XAttribute("ident", "Positive response is received: 0x67 02")}), New List(Of XElement)({create_set_tag(security, "", "0"), wait_tag(0)})))
        tag.Add(create_testcase_string(input_string, function_enable, enable_disable))
        tag.Add(create_tag("testcase", New List(Of XAttribute)({New XAttribute("title", "Tester Present is Off"), New XAttribute("ident", "-")}), New List(Of XElement)({create_set_tag("EnvTesterPresentOnOff", "", "0"), wait_tag(0)})))
        Return tag
    End Function
    Public Function create_set_tag(title As String, ident As String, value As String) As XElement
        Dim temper_tag As XElement = create_tag("envvar", New XAttribute("name", title), value)
        If ident <> "" Then
            Return create_tag("set", New List(Of XAttribute)({New XAttribute("title", title), New XAttribute("ident", ident)}), temper_tag)
        Else
            Return create_tag("set", New XAttribute("title", title), temper_tag)
        End If
    End Function
    Private Function wait_tag(Time As String) As XElement
        Return create_opentag("wait", New List(Of XAttribute)({New XAttribute("time", Time), New XAttribute("title", "wait")}))
    End Function
    Public Function create_tag(name As String, attribute As List(Of XAttribute), content As List(Of XElement)) As XElement
        Dim temper As XElement = New XElement(name, content)
        temper.Add(attribute)
        Return temper
    End Function
    Public Function create_tag(name As String, attribute As List(Of XAttribute), content As XElement) As XElement
        Dim temper As XElement = New XElement(name, content)
        temper.Add(attribute)
        Return temper
    End Function
    Public Function create_tag(name As String, attribute As XAttribute, content As List(Of XElement)) As XElement
        Dim temper As XElement = New XElement(name, content)
        temper.Add(attribute)
        Return temper
    End Function
    Public Function create_tag(name As String, attribute As XAttribute, value As UInt32) As XElement
        Dim temper As XElement = New XElement(name, value)
        temper.Add(attribute)
        Return temper
    End Function
    Public Function create_tag(name As String, attribute As List(Of XAttribute), value As UInt32) As XElement
        Dim temper As XElement = New XElement(name, value)
        temper.Add(attribute)
        Return temper
    End Function
    Public Function create_tag(name As String, attribute As List(Of XAttribute), value As String) As XElement
        Dim temper As XElement = New XElement(name, value)
        temper.Add(attribute)
        Return temper
    End Function
    Public Function create_opentag(name As String, attribute As List(Of XAttribute)) As XElement
        Dim temper As String = ""
        For Each cc As XAttribute In attribute
            temper &= cc.ToString() & " "
        Next
        Return XElement.Parse("<" & name & " " & temper & "/>")
    End Function

End Class

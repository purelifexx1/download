Public Class mapped_rx_signal

    Public Name As String
    Public Message As String
    Public multiplexing_group As String
    Public startbit As Decimal
    Public Length As Decimal
    Public byte_order As String
    Public value_type As String
    Public initial_value As Decimal
    Public factor As Decimal
    Public offset As Decimal
    Public minimun As Decimal
    Public maximum As Decimal
    Public unit As String
    Public additional As Boolean = False 'if additional signal is added, this value is true
    Public raw_value As Decimal
    Public scenario As Decimal
    Public up_level As String
    Public down_level As String
    Public press_counter As String
    Public enable_duration As String
    Public disable_duration As String
    Public enable_string As String
    Public disable_string As String
    Public security As String
    Public function_type As String
    Public scope As String 'prirate can or public can
    Public signal_type As String
    Public ID As String
    Public transmitter As String
    Public receiver As String
    Public value_define As List(Of String) = New List(Of String)
    Public value As List(Of Decimal) = New List(Of Decimal)
    'Public Sub New(input As String(), extend As Decimal)
    '    MyBase.New()
    '    Name = input(0)
    '    Message = input(1)
    '    multiplexing_group = input(2)
    '    startbit = CDec(input(3))
    '    Length = CDec(input(4))
    '    byte_order = input(5)
    '    value_type = input(6)
    '    initial_value = CDec(input(7))
    '    factor = CDec(input(8))
    '    offset = CDec(input(9))
    '    minimun = CDec(input(10))
    '    maximum = CDec(input(11))
    '    unit = input(12)
    '    If extend = 1 Then
    '        raw_value = CDec(input(13))
    '        enable_string = input(14)
    '        additional = True
    '    ElseIf extend = 2 Then
    '        raw_value = CDec(input(13))
    '    End If
    'End Sub

    Public Sub New(input As String(), extend As Decimal, extend1 As Decimal)
        If extend = 1 Then
            Name = input(2)
            startbit = CDec(input(4).Split("|")(0))
            Length = CDec(input(4).Split("|")(1).Split("@")(0))
            If input(4).Split("|")(1).Split("@")(1) = "0+" Then
                byte_order = "Motorola"
            Else
                byte_order = "Intel"
            End If
            factor = CDec(input(5).Split(",")(0).Replace("(", ""))
            offset = CDec(input(5).Split(",")(1).Replace(")", ""))
            minimun = CDec(input(6).Split("|")(0).Replace("[", ""))
            maximum = CDec(input(6).Split("|")(1).Replace("]", ""))
            unit = input(7).Replace(ControlChars.Quote, "")
        ElseIf extend = 2 Then
            Name = input(0)
            Message = input(1)
            ID = input(2)
            startbit = CDec(input(3))
            Length = CDec(input(4))
            byte_order = input(5)
            factor = CDec(input(6))
            offset = CDec(input(7))
            minimun = CDec(input(8))
            maximum = CDec(input(9))
            unit = input(10)
            signal_type = input(11)
            If input(12) = "" Then
                raw_value = 0
            Else
                raw_value = CDec(input(12))
            End If
            enable_string = input(13)
            transmitter = input(14)
            receiver = input(15)
            If extend1 = 0 Then
                If input(16) = "man" Then
                    additional = False
                ElseIf input(16) = "spec" Then
                    additional = True
                End If
            Else

            End If
            If input(17) <> "" Then
                For Each fac As String In input(17).Split("|")
                    Dim tempp = fac.Split(":")
                    value.Add(CDec(tempp(0)))
                    value_define.Add(tempp(1))
                Next
            End If
        End If
    End Sub

    Public Function get_data_string(extend As Decimal) As String
        Dim total_string As String = ""
        total_string += Name & "," & Message & "," & ID & "," & CStr(startbit) & "," & CStr(Length) & "," & byte_order & "," & CStr(factor) & "," & CStr(offset) & "," _
                        & CStr(minimun) & "," & CStr(maximum) & "," & unit & "," & signal_type & ","
        If raw_value = 0 Then
            total_string += "" & "," & enable_string & "," & transmitter & "," & receiver & ","
        Else
            total_string += CStr(raw_value) & "," & enable_string & "," & transmitter & "," & receiver & ","
        End If

        If extend = 0 Then
            If additional = False Then
                total_string += "man" & ","
            Else
                total_string += "spec" & ","
            End If
        Else
            total_string += ","
        End If
        Dim real_value As Decimal = 0
        If value_define.Count <> 0 Then
            For Each element As String In value_define
                If real_value = value_define.Count - 1 Then
                    total_string += CStr(value(real_value)) & ":" & element
                Else
                    total_string += CStr(value(real_value)) & ":" & element & "|"
                End If
                real_value += 1
            Next
            total_string += vbCrLf
        Else
            total_string += vbCrLf
        End If
        Return total_string
    End Function
    Public Sub set_string_value(input As String)
        Dim element1 As String() = input.Split(ControlChars.Quote)
        Dim start_index = element1.Length - 2
        Dim number_of_value = (element1.Length - 1) / 2
        For count As Decimal = 1 To number_of_value
            value_define.Add(element1(start_index))
            If count = number_of_value Then
                value.Add(CDec(element1(start_index - 1).Split(" ")(3)))
            Else
                value.Add(CDec(element1(start_index - 1)))
                start_index -= 2
            End If
        Next
    End Sub
    Public Sub New()
        MyBase.New()
    End Sub

End Class

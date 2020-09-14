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
    Public Sub New(input As String(), extend As Decimal)
        MyBase.New()
        Name = input(0)
        Message = input(1)
        multiplexing_group = input(2)
        startbit = CDec(input(3))
        Length = CDec(input(4))
        byte_order = input(5)
        value_type = input(6)
        initial_value = CDec(input(7))
        factor = CDec(input(8))
        offset = CDec(input(9))
        minimun = CDec(input(10))
        maximum = CDec(input(11))
        unit = input(12)
        If extend = 1 Then
            raw_value = CDec(input(13))
            enable_string = input(14)
            additional = True
        ElseIf extend = 2 Then
            raw_value = CDec(input(13))
        End If
    End Sub

    Public Sub New(input As String(), extend As Decimal, extend2 As Decimal)
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
        End If
    End Sub
    Public Sub New()
        MyBase.New()
    End Sub

End Class

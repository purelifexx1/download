Public Class rx_message
    Public Name As String
    Public ID As String
    Public transmiter As String

    Public Sub New(input As String())
        MyBase.New()
        Name = input(0)
        ID = input(1)
        transmiter = input(6)
    End Sub
    Public Sub New(input As String(), exception As Decimal)
        MyBase.New()
        Name = input(0)
        ID = input(1)
        transmiter = input(2)
    End Sub
End Class

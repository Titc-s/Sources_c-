<Script Language="VB" Runat="Server">
Sub Page_Load(sender As Object, e As EventArgs)
    counter.Text = "在线人数：" & Application("cnt")         
End Sub
</Script>
<Html><Body><H3 Align="Center" Color=Red>统计在线人数</H3>
<Center><Form Runat="Server">
    <Td><ASP:TextBox Id="counter" Runat="server" Size=20/>
</Form></Center></Body></Html>

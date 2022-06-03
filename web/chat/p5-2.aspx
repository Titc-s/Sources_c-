<Script Language="VB" Runat="Server">
Sub Login(sender As Object, e As EventArgs)
    If usrname.Text="" Then
       LblDesc.Text="错误的用户名!请重新输入。"
    Else
       Session("usrname")= usrname.Text
       Response.Redirect("p5-3.aspx")
    End If        
End Sub
</Script>
<Html>
<! -- 生成登录界面 -- >  
<H1 align="center">在线讨论区</h1>
<Form name="f1"  Runat="Server">
<Div Align="center">
请输入用户名<Asp:TextBox Runat="Server" Id="usrname" size="10" /><Br><Br>
<ASP:Button Text="登录" Runat="server" OnClick="Login"/></Div>
<Asp:Label Id="LblDesc" ForeColor="Red" Runat="server"/>
</Form></Html>

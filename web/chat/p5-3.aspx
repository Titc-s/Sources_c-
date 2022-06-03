 <Script Language="VB" Runat="Server">
Sub Page_Load(sender As Object, e As EventArgs)
    If Session("usrname")="" Then
       Response.Redirect("p5-2.aspx")  
    Else       
       cont.Text=Replace(Application("message"),"<para>",vbCrLf)
    End If        
End Sub
Sub talk(sender As Object, e As EventArgs)
    If Session("usrname")="" Then
       Response.Redirect("p5-2.aspx")     
    Else
       Dim name,content,ip,show As String
       Dim i,n As Integer
       name=session("usrname")                      '读取用户名
       content=Request("cont1")                      '读取讨论内容
       ip=Request.Servervariables("remote_addr")        '读取用户的IP地址
       Application.Lock
       '将用户名、IP地址以及发言内容写入application对象中
       Application("message")=name+":"+ip+":"+content+"<para>"+Application("message")
       Application.unlock
       show=Application("message")
       '只保存最新的20条信息，其他的内容删除
       i=1
       For n=1 To 20
           i=instr(i,show,"<para>")+6                 '查找是否到达最末消息   
           If i=6 Then Exit For                       '已到达最末消息
       Next
       If i<>6 Then
          Application.Lock
          Application("message")=left(show,i-5)         '去除最后一条消息的<para>标记
          Application.Unlock
       End If  
       cont.Text=Replace(Application("message"),"<para>",vbCrLf)
    End If        
End Sub
Sub logout(sender As Object, e As EventArgs)
    Session.abandon               
    Response.Redirect ("p5-1.aspx")
End Sub
</Script>
<Html>
<H1 Align="center">在线讨论区</H1>
<Form Name="f1"  Runat="Server">
<Asp:TextBox Runat="Server" Id="cont" Columns="120" Rows="30" 
ReadOnly="True" TextMode="Multiline"  /><Br><Br>
参与讨论：<Asp:TextBox Runat="Server" Id="cont1" Size=50  />&nbsp;&nbsp;
<ASP:Button Text="发言" Runat="server" OnClick="talk"/> &nbsp;&nbsp;
<ASP:Button Text="退出" Runat="server" OnClick="logout"/>
</Form></Html>

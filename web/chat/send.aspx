<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="send.aspx.cs" Inherits="chat.send" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
        </div>
        <p>
            姓名：<asp:TextBox ID="sender" runat="server" Columns="10" OnTextChanged="TextBox1_TextChanged"></asp:TextBox>
        </p>
        <p>
            内容：<asp:TextBox ID="content" runat="server" Columns="60" Width="835px"></asp:TextBox>
            <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="发送" />
        </p>
    </form>
</body>
</html>

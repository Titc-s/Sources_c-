<%@ page language="java" pageEncoding="utf-8" import="org.easybooks.test.model.vo.UserTable"%>
<html>
<head>
	<title>留言板信息</title>
</head>
<body>
	<%
		UserTable user=(UserTable)session.getAttribute("user");
		String usr=user.getUsername();
	%>
	<%=usr%>，您好！欢迎登录留言板。
</body>
</html>

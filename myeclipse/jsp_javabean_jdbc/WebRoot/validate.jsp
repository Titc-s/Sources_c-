<%@ page language="java" pageEncoding="gb2312" import="java.sql.*,org.easybooks.test.model.vo. UserTable"%>
<jsp:useBean id="SqlSrvDB" scope="page" class="org.easybooks.test.jdbc.SqlSrvDBConn" />
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html;charset=gb2312">
    </head>
    <body>
        <%
        	request.setCharacterEncoding("gb2312");				//�����������
        	String usr=request.getParameter("username");			//��ȡ�ύ���û���
            String pwd=request.getParameter("password");		//��ȡ�ύ������
            boolean validated=false;						//��֤�ɹ���ʶ
        	UserTable user=null;
        	//�Ȼ��UserTable��������ǵ�һ�η��ʸ�ҳ���û�����϶�Ϊ�գ�������ǵڶ��������ǵ�
  		//���Σ���ֱ�ӵ�¼��ҳ�������ٴ��ظ���֤���û�����Ϣ
        	user=(UserTable)session.getAttribute("user");
        	//����û��ǵ�һ�ν��룬�Ự����δ�洢user�־û����󣬹�Ϊnull
        	if(user==null){
        		//��ѯuserTable���еļ�¼
        		String sql="select * from userTable";
        		ResultSet rs=SqlSrvDB.executeQuery(sql);		//ȡ�ý����
        		while(rs.next())
        		{
        			if((rs.getString("username").trim().compareTo(usr)==0)&&(rs.getString("password").compareTo 
        			  (pwd)==0)){
        				user=new UserTable();		//�����־û���JavaBean����user
        				user.setId(rs.getInt(1));
        				user.setUsername(rs.getString(2));
        				user.setPassword(rs.getString(3));
        				session.setAttribute("user", user);	//��user����洢�ڻỰ��
        				validated=true;					//��ʶΪtrue��ʾ��֤�ɹ�ͨ��
        			}
        		}
        		rs.close();
        		SqlSrvDB.closeStmt();
        		SqlSrvDB.closeConn();
            }
            else{
            	validated=true;	//���û���֮ǰ�ѵ�¼�����ɹ���֤���ʱ�ʶΪtrue��ʾ����������
            }
            if(validated)
            {
                //��֤�ɹ���ת��main.jsp
        %>
                <jsp:forward page="main.jsp"/>
        <%
            }
            else
            {
                //��֤ʧ����ת��error.jsp
        %>
                <jsp:forward page="error.jsp"/>
        <%
            }
        %>
    </body>
</html>
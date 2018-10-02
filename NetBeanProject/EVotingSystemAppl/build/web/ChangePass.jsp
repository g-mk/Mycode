<%-- 
    Document   : ChangePass
    Created on : 15 Apr, 2017, 3:18:42 PM
    Author     : Guru Manikandan
--%>
<%@page import="java.sql.SQLException"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="evoting.DbConnect"%>
<%@page import="java.sql.Connection"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Change Password</title>
        <link rel="icon" type="image/png" href="image\Vote-icon.png"/>
        <link href="css/background.css" type="text/css" rel="stylesheet"/>
        <meta http-equiv="refresh" content="3;url=ChangePassword.jsp">
    </head>
    <body>
        <%!
           String User;
           Connection conn;
        %>
        <%
            if(session!=null)
            {
                if(session.getAttribute("USER")!=null && !session.
                        getAttribute("USER").toString().equals(""))
                    User = session.getAttribute("USER").toString();
                else
                {
                    RequestDispatcher dispatch = getServletContext().
                        getRequestDispatcher("/LoginError.jsp");
                    dispatch.forward(request, response);
                }
            }
        %>
        <%
            try{
                conn = DbConnect.Connect();
                String sql = "UPDATE 14bcs068_login SET password=md5(?) WHERE user = ? AND password = md5(?);";
                PreparedStatement stmt = conn.prepareStatement(sql);
                stmt.setString(1, request.getParameter("passwd"));
                stmt.setString(2, User);
                stmt.setString(3, request.getParameter("oldpassword"));
                int rs = stmt.executeUpdate();
                if(rs>0)
                {
                    out.println("<h2 align=\"center\">Password Changed Successfully</h2>");
                }
                else
                {
                    out.println("<h2 align=\"center\">Password Changed Failed <br/> "
                            + "Check Your Old Password and try again later!!!!</h2>");
                }
                
            }catch(SQLException ex)
            {
                out.println(ex.getMessage());
            }
        %>
    </body>
</html>

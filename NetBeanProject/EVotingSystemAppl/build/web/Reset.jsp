<%-- 
    Document   : Reset
    Created on : 16 Apr, 2017, 2:07:35 PM
    Author     : Guru Manikandan
--%>
<%@page import="java.sql.Connection"%>
<%@page import="java.sql.SQLException"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="evoting.DbConnect"%>
<%@page import="java.sql.Connection"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>E-Voting</title>
        <link rel="icon" type="image/png" href="image\Vote-icon.png"/>
        <link rel="stylesheet" type="text/css" href="css\background.css" />
    </head>
    <%!
           String User;
           Connection conn;
        %>
        <%
            if(session!=null)
            {
                if(session.getAttribute("USER")!=null && session.
                        getAttribute("USER").toString().equals("Admin"))
                    User = session.getAttribute("USER").toString();
                else
                {
                    RequestDispatcher dispatch = getServletContext().
                        getRequestDispatcher("/LoginAuthenticate.jsp");
                    dispatch.forward(request, response);
                }
            }
        %>
    <body>
        <%
            try{
                conn = DbConnect.Connect();
                String sql = "TRUNCATE 14bcs068_election";
                PreparedStatement stmt = conn.prepareStatement(sql);
                boolean stat = stmt.execute();
                if(!stat)
                {
                    out.println("<h2 align=center>System Reset Successfull</h2>");
                }
                else
                    out.println("<h2 align=center>System Reset Failed</h2>");
            }
            catch(SQLException exp)
            {
                out.println(exp.getMessage());
            }
            finally{
                conn.close();
            }
        %>
    </body>
</html>

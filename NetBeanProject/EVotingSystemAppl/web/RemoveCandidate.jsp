<%-- 
    Document   : RemoveCandidate
    Created on : 11 Apr, 2017, 7:48:01 PM
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
        <meta charset="UTF-8">
        <title>Remove Candidate</title>
        <link rel="icon" type="image/png" href="image\Vote-icon.png"/>
        <link href="css/background.css" type="text/css" rel="stylesheet"/>
        <meta http-equiv="refresh" content="3;url=RemoveCandidateForm.jsp">
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
            try
            {
                conn = DbConnect.Connect();
                String sql = "DELETE FROM 14bcs068_candidate WHERE candid=?";
                PreparedStatement stmt = conn.prepareStatement(sql);
                stmt.setString(1, request.getParameter("CandidateID"));
                int stat = stmt.executeUpdate();
                if(stat>0)
                {
                    out.println("<h2 align=center>Candidate Removed Successfully</h2>");
                }
                else
                    out.println("<h2 align=center>Candidate Removal Faild due to some error.!!"
                            + "<br/>Try Again Some Time!!!!</h2>");
            }
            catch(SQLException exp)
            {
                out.println("Error"+exp.getMessage());
            }
            finally{
                conn.close();
            }
        %>
    </body>
</html>

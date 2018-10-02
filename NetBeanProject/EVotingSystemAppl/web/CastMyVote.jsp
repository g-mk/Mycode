<%-- 
    Document   : CastMyVote
    Created on : 16 Apr, 2017, 11:48:58 AM
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
        <title>Caste My Vote</title>
        <link rel="icon" type="image/png" href="image\Vote-icon.png"/>
        <link href="css/background.css" type="text/css" rel="stylesheet"/>
        <meta http-equiv="refresh" content="3;url=ViewCandidate.jsp">
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
                String sql = "INSERT INTO 14bcs068_election(voterid,candid) VALUES (?,?);";
                PreparedStatement stmt = conn.prepareStatement(sql);
                stmt.setString(1,request.getParameter("voterid").toString());
                stmt.setString(2,request.getParameter("candid").toString());
                int stat = stmt.executeUpdate();
                if(stat>0)
                    out.println("<h2 align=center>Thanks For Casting Your Vote!!!</h2>");
                else
                    out.println("<h2 align=center>Your Vote is not Considered "
                            + "due to some fault.<br/>Please Try Again Later!!!</h2>");
            }catch(SQLException ex)
            {
                out.println(ex.getMessage());
            }
        %>
    </body>
</html>

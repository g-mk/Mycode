<%-- 
    Document   : Update
    Created on : 9 Apr, 2017, 11:26:24 AM
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
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>E-Voting System</title>
        <link rel="stylesheet" type="text/css" href="css\background.css" />
    </head>
    <body>
        <%!
            Connection conn;
        %>
        <%
            String voterid;
            String fName = request.getParameter("voterFName");
            String mName = request.getParameter("voterMName");
            String lName = request.getParameter("voterLName");
            String fatherName = request.getParameter("vFatherName");
            String DOB = request.getParameter("voterDOB");
            String age = request.getParameter("age");
            String mobile = request.getParameter("mobile");
            String email = request.getParameter("email");
            //if(!session.getAttribute("USER").equals("Admin"))
                voterid = session.getAttribute("VOTERID").toString();
            
            try{
                conn=DbConnect.Connect();
                String sql = "UPDATE 14bcs068_voterinfo SET fname=?,mname=?,"
                        + "lname=?,fathername=?,dob=?,age=?,mobile=?,email=? "
                        + "WHERE voterid=?;";
                PreparedStatement stmt = conn.prepareStatement(sql);
                stmt.setString(1, fName);
                stmt.setString(2, mName);
                stmt.setString(3, lName);
                stmt.setString(4, fatherName);
                stmt.setString(5, DOB);
                stmt.setInt(6, Integer.parseInt(age));
                stmt.setString(7, mobile);
                stmt.setString(8, email);
                stmt.setString(9, voterid);
                int result = stmt.executeUpdate();
                if(result>0)
                {
                    out.print("<h2 align='center' >Changes were Noted and Updated</h2>");
                }
                else
                {
                    out.print("<h2 align='center'>Updation Failed. Try Again Sometime!!!</h2>");
                }
                if(!session.getAttribute("USER").equals("Admin"))
                    response.setHeader("Refresh", "3;url=UpdateDetails.jsp");
                else
                    response.setHeader("Refresh", "3;url=UpdateAll.jsp");
                
            }
            catch(SQLException exp)
            {
                out.println("Error "+exp.getMessage());
            }
            finally{
                conn.close();
            }
            
            
        %>
    </body>
</html>

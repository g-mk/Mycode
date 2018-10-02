<%-- 
    Document   : ViewResult
    Created on : 16 Apr, 2017, 1:38:25 PM
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
        <title>View Result</title>
        <link rel="icon" type="image/png" href="image\Vote-icon.png"/>
        <link href="css/background.css" type="text/css" rel="stylesheet"/>
        <script src="javascript\jquery-1.11.3.min.js"></script>
        <script>
          $(document).ready(function(){
            $("a").on('click', function(event) {
              if (this.hash !== "") {
                event.preventDefault();
                var hash = this.hash; 
                $('html, body').animate({
                  scrollTop: $(hash).offset().top
                }, 600, function(){
                  window.location.hash = hash;
                });
              } // End if
            });
          });
        </script>
        <style>
            table{
                width:50%;
                text-align: center;
            }
            th{
                font-family:"Lucida Grande",cursive;
                font-style: italic;
                font-weight: bold;
                font-size: 20px;
            }
            td,th{
                font-family:"Lucida Grande",cursive;
                font-style: italic;
                font-weight: bold;
                font-size: 15px;
            }
        </style>
    </head>
        <%!
           String User;
           Connection conn;
           public boolean checkElection() throws ClassNotFoundException, SQLException{
                conn = DbConnect.Connect();
                String sql = "SELECT * FROM 14bcs068_election ";
                PreparedStatement stmt = conn.prepareStatement(sql);
                ResultSet rs = stmt.executeQuery();
                if(rs.next())
                    return true;
                conn.close();
                return false;
            }
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
        <div id="topDiv" align="center">
            <h1>Vote for each Candidate</h1>
                <table border="2" cellpadding="2" cellspacing="2">
                    <tr bgcolor="#293e6a" style="color:white;">
                        <th>Candidate ID</th>
                        <th>Number of Votes</th>
                    </tr>
                    <%
                        try{
                            if(checkElection())
                            {
                                conn = DbConnect.Connect();
                                String sql = "SELECT candid,count(candid) as c FROM "
                                        + "14bcs068_election GROUP BY candid ORDER BY c desc";
                                PreparedStatement stmt = conn.prepareStatement(sql);
                                ResultSet rs = stmt.executeQuery();
                                while(rs.next())
                                {
                                    out.println("<tr>");
                                    out.println("<td>"+rs.getString("candid")+"</td>");
                                    out.println("<td>"+rs.getString("c")+"</td>");
                                    out.println("</tr>");
                                }
                            }
                            else
                                out.println("<tr><td colspan=2>No Details Found</td></tr>");
                        }
                        catch(SQLException exp)
                        {
                            out.println(exp.getMessage());
                        }
                        finally{
                            conn.close();
                        }
                    %>
                </table>
        </div>
        <div>
         <a href="#topDiv" >
            <img id="goTop" src="image\arrow.jpg" width="50px" height="50px" 
               alt="Not Found"/>
         </a>
      </div>
    </body>
</html>

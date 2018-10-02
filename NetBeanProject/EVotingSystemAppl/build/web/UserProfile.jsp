<%-- 
    Document   : UserProfile
    Created on : 5 Mar, 2017, 3:35:40 PM
    Author     : Guru Manikandan
--%>

<%@page import="java.util.Base64"%>
<%@page import="java.io.OutputStream"%>
<%@page import="java.sql.Blob"%>
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
        <link href="css/background.css" type="text/css" rel="stylesheet"/>
        <script src="javascript\jquery-1.11.3.min.js"></script>
        <style>
            #propic{
                position: fixed;
                left:10px;
                float:right;
            }
            table{
                letter-spacing:1px;
                font-family:"Lucida Grande",cursive;
                text-indent:50px;
                font-size:20px;
                color: midnightblue;
            }
        </style>
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
              }
            });
          });
        </script>
    </head>
    <body>
        <%!
            Connection conn;
            Blob image = null;
            byte[] imgData = null;
        %>
        <%
            if(session!=null)
            {
                if(session.getAttribute("VOTERID")==null)
                {
                    RequestDispatcher dispatch = getServletContext().
                        getRequestDispatcher("/LoginError.jsp");
                    dispatch.forward(request, response);
                }
                else
                {
                    try{
                        conn = DbConnect.Connect();
                        String sql = "SELECT * FROM 14bcs068_voterinfo WHERE voterid = ?";
                        String sql1 = "SELECT photo FROM 14bcs068_voterproof"
                                + " WHERE voterid = ?";
                        PreparedStatement stmt = conn.prepareStatement(sql);
                        PreparedStatement stmt1 = conn.prepareStatement(sql1);
                        stmt.setString(1, session.getAttribute("VOTERID").toString());
                        stmt1.setString(1, session.getAttribute("VOTERID").toString());
                        ResultSet rs = stmt.executeQuery();
                        ResultSet rs1 = stmt1.executeQuery();
                        if(rs.next() && rs1.next())
                        {
                            image = rs1.getBlob("photo");
                            imgData = image.getBytes(1, (int)image.length());
                            String encode = Base64.getEncoder().encodeToString(imgData);

                            out.println("<img id=\"propic\" width=\"180px\" "
                                    + "height=\"250px\" alt=\"Not found\" "
                                    + "src = \"data:image;base64,"
                                    +encode+"\" />");
                            out.println("<table align=\"center\" cellspacing=2>");
                            out.println("<tr>"
                                    + "<td>Voter ID</td>"
                                    + "<td>"+rs.getString("voterid")+"</td>"
                                    + "</tr>");
                            out.println("<tr>"
                                    + "<td>Name</td>"
                                    + "<td>"+rs.getString("fname").toUpperCase()+" "
                                    +rs.getString("lname").toUpperCase()+"</td>"
                                    + "</tr>");
                            out.println("<tr>"
                                    + "<td>DOB</td>"
                                    + "<td>"+rs.getString("dob")+"</td>"
                                    + "</tr>");
                            out.println("<tr>"
                                    + "<td>Age</td>"
                                    + "<td>"+rs.getString("age")+"</td>"
                                    + "</tr>");
                            out.println("<tr>"
                                    + "<td>Gender</td>"
                                    + "<td>"+rs.getString("gender")+"</td>"
                                    + "</tr>");
                            out.println("<tr>"
                                    + "<td>Father Name</td>"
                                    + "<td>"+rs.getString("fathername").toUpperCase()+"</td>"
                                    + "</tr>");
                            out.println("<tr>"
                                    + "<td>Mobile</td>"
                                    + "<td>"+rs.getString("mobile")+"</td>"
                                    + "</tr>");
                            out.println("<tr>"
                                    + "<td>Email</td>"
                                    + "<td>"+rs.getString("email")+"</td>"
                                    + "</tr>");
                            out.println("<tr>"
                                    + "<td>Address</td>"
                                    + "<td>"+ rs.getString("dno").toUpperCase()
                                            + ", "+rs.getString("street").toUpperCase()
                                            + ", "+rs.getString("city").toUpperCase()
                                            + ", "+rs.getString("state").toUpperCase()
                                    +".</td>"
                                    + "</tr>");
                            out.println("</table>");
                        }
                    }
                    finally{
                        conn.close();
                    }
                }
            }
        %>
        
        
    </body>
</html>

<%-- 
    Document   : ViewCandidate
    Created on : 10 Apr, 2017, 11:11:01 PM
    Author     : Guru Manikandan
--%>
<%@page import="java.util.Base64"%>
<%@page import="java.sql.Blob"%>
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
        <title>Candidate List</title>
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
      <%!
            Connection conn;
            Blob image = null;
            byte[] imgData = null;
            String User =null,Voter=null;
            public boolean checkVoterCasting(String VoterID) throws ClassNotFoundException, SQLException{
                conn = DbConnect.Connect();
                String sql = "SELECT * FROM 14bcs068_election WHERE voterid = ? ";
                PreparedStatement stmt = conn.prepareStatement(sql);
                stmt.setString(1, VoterID);
                ResultSet rs = stmt.executeQuery();
                if(rs.next())
                    return true;
                conn.close();
                return false;
            }
      %>
        <style>
            table{
                width:60%;
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
            a{
                text-decoration: none;
                font-family:"Lucida Grande",cursive;
                font-weight: bold;
                font-size: 20px;
                color: black;
            }
            td a:hover{
                color: white;
                font-weight: bold;
            }
            tr:hover{
                transition: .8s;
                background-color: #293e6a; 
                color:white;
            }
        </style>
    </head>
    <body>
        <%
            if(session!=null)
            {
                if(session.getAttribute("USER")!=null && !session.
                        getAttribute("USER").toString().equals(""))
                {
                    User = session.getAttribute("USER").toString();
                    Voter = session.getAttribute("VOTERID").toString(); 
                }
            }
        %>
        
        <div id="topDiv" align="center">
            <h1>Candidate List</h1>
                <table border="2" cellpadding="1" cellspacing="1">
                    <tr bgcolor="#293e6a" style="color:white;">
                        <th>Candidate ID</th>
                        <th>Symbol Name</th>
                        <th>Symbol</th>
                        <%
                            if(User!=null)
                            {
                                if(!checkVoterCasting(Voter))
                                    out.println("<th>Vote</th>");
                            }
                        %>
                    </tr>
                    <%
                        try{
                            conn = DbConnect.Connect();
                            String sql = "SELECT * FROM 14bcs068_candidate";
                            PreparedStatement stmt = conn.prepareStatement(sql);
                            ResultSet rs = stmt.executeQuery();
                            while(rs.next())
                            {
                                image = rs.getBlob("symbol");
                                imgData = image.getBytes(1, (int)image.length());
                                String encode = Base64.getEncoder().encodeToString(imgData);
                                out.println("<tr>");
                                out.println("<td>"+
                                        rs.getString("candid")+"</td>");
                                out.println("<td>"+rs.getString("symbolname")+"</td>");
                                out.println("<td><img id=\"propic\" width=\"250px\" "
                                        + "height=\"150px\" alt=\"Not found\" "
                                        + "src = \"data:image;base64,"
                                        +encode+"\" /></td>");
                                if(User!=null)
                                {
                                    if(!checkVoterCasting(session.getAttribute("VOTERID").toString()))
                                        out.println("<td><a href=\"CastMyVote.jsp?candid="+rs.getString("candid")+"&voterid="+Voter+"\">Vote Him</a></td>");
                                }
                                out.println("</tr>");
                            }
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
                <%
                    if(User!=null)
                    {
                        if(!checkVoterCasting(session.getAttribute("VOTERID").toString()))
                            out.println("<h2>Vote Now</h2>");
                        else
                            out.println("<h2>You have already casted your vote<br/>Thanks for your Vote!!!</h2>");
                    }
                %>
        </div>
        <div>
         <a href="#topDiv" >
            <img id="goTop" src="image\arrow.jpg" width="50px" height="50px" 
               alt="Not Found"/>
         </a>
      </div>
    </body>
</html>

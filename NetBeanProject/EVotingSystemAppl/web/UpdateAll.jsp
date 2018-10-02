<%-- 
    Document   : UpdateDetails
    Created on : 9 Apr, 2017, 9:14:23 AM
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
        <title>Voter Registration Form</title>
      <link href="css\background.css" type="text/css" rel="stylesheet"/>
      <link rel="stylesheet" href="font-awesome-4.7.0\css\font-awesome.min.css">
      <script src="javascript/validateRegForm.js" type="text/javascript">
      </script>
      <script src="javascript/ajax.js" type="text/javascript">
      </script>
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
      <style type="text/css">
        .errorLabel{
            color:red;
            -webkit-transition: all 0.50s ease-in-out;
            -moz-transition: all 0.50s ease-in-out;
            transition: all 0.50s ease-in-out;
            opacity:0;
        }
        #regForm{
            letter-spacing:1px;
            font-family:serif;
            display:table;
            width:100%;
        }
        p{
            display:table-row;
        }
        label{
            display:table-cell;
            text-align: right;
        }
        input{
            display:table-cell;
        }
        
        i{
            -webkit-transition: all 0.50s ease-in-out;
            -moz-transition: all 0.50s ease-in-out;
            transition: all 0.50s ease-in-out;
            display:inline;
        }
        #submit,#reset{
            background-color: rgba(66,118,208,1);
            padding: 2px 2px 2px 2px;
            color: white;
            font-style:bold;
        }
        #submit:hover,#reset:hover{
            cursor: pointer;
            background-color: white;
            padding: 2px 2px 2px 2px;
            color: rgba(66,118,208,1);
            font-style:bold;
        }
      </style>
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
        <h2 id="topDiv" align="center">Voter Registration Form</h2>
        
        <div>
           <form id="regForm" method="GET" 
                 action="UpdateDetails.jsp" 
                 autocomplete="on" >
              
               <div align="center">
                   <label for="Voter ID">Voter ID: </label>
                   <select id = "voterid" name = "voterid">
                       <option>--Select--</option>
                       <%
                            try{
                                conn = DbConnect.Connect();
                                String sql = "SELECT voterid FROM 14bcs068_voterinfo";
                                PreparedStatement stmt = conn.prepareStatement(sql);
                                ResultSet rs = stmt.executeQuery();
                                while(rs.next())
                                {
                                    out.println("<option>"+rs.getString(1)+"</option>");
                                }
                            }
                            catch(SQLException exp)
                            {
                                out.println("Error"+exp.getMessage());
                            }
                            finally{
                                conn.close();
                            }
                        %>
                   </select>
                   <br/><br/>
                 <input id="submit"type="submit" name="Submit" value="Update" 
                           />
                 <input id = "reset" type="reset" name="Reset" value="Reset" />
              </div>
           </form>
        </div>
   </body>
</html>

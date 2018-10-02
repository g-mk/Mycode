<%-- 
    Document   : Login
    Created on : 5 Mar, 2017, 11:51:53 AM
    Author     : Guru Manikandan
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Login</title>
        <link href="css/background.css" type="text/css" rel="stylesheet"/>
        <%
                         if(session!=null)
                         {
                             if(session.getAttribute("USER")!=null && 
                                    !session.getAttribute("USER").toString().
                                            equals(""))
                             {
                                    out.print("<script>parent.location.href='Loading.jsp'</script></head></html>");
                             }
                             else{
        %>
        <style>
            #errorLable{
                color:red;
            }
           #loginDiv{
                position:relative;
                display:box;
                padding: 15px 15px 15px 15px;
                font-size:20px;
                top:50px;
                -webkit-transition: 2s;
                transition: 2s;
           }
           a{
                text-decoration:none;
                color:black;
                font-weight:bold;
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
        
        <div id="loginDiv" align="center" >
            <h3>Login To Vote</h3>
            <form id="login" method="POST"
                  action="/EVotingSystemAppl/LoginServlet">
                  <label for="user">User Name</label>
                  <input type="text" id="user" name="user" 
                                 minlength=3 autocomplete="on" autofocus required/>
                     <br/><br/>
                  <label for="password">Password</label>&nbsp;&nbsp;
                  <input id="password" type="password" name="password" 
                                 minlength=6 required/>
                    <br/>
                    <%
                         if(session!=null)
                         {
                             if(session.getAttribute("ERROR")!=null && 
                                    session.getAttribute("ERROR").toString().
                                            equals("Invalid"))
                             {
                                 out.print("<p id=\"errorLable\">"
                                         + "Invalid User Name/Password</p>");
                             }
                         }
                    %>     
                  <input id="submit" type="submit" name="sumbit" value="Submit"/>
                  <input id="reset" type="reset" name="reset" value="Clear"/>
                     <br/><br/>
                  New User? <a href="VotersRegForm.html">Register Here!!!</a>
                  <br/><br/>
                  <a target = "_parent" href="index.html">&lArr;Back</a>
            </form>
        </div>
      <div>
         <a href="#topDiv" >
            <img id="goTop" src="image\arrow.jpg" width="50px" height="50px" 
               alt="Not Found"/>
         </a>
      </div>
    </body>
</html>
<%
            }
        }
%>

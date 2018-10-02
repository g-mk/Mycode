<%-- 
    Document   : ChangePassword
    Created on : 14 Apr, 2017, 8:01:15 PM
    Author     : Guru Manikandan
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Candidate Registration</title>
        <link rel="icon" type="image/png" href="image\Vote-icon.png"/>
        <link href="css/background.css" type="text/css" rel="stylesheet"/>
        <script type="text/javascript">
            function newPassword(e)
            {
                if(e.value.length<6)
                {
                    e.setCustomValidity("Give Atleast 6 character");
                    alert("Give Atleast 6 character");
                }
                else
                    e.setCustomValidity("");
            }
            function confirmNewPass(e)
            {
                var newPassword = document.getElementById("passwd");
                if(e.value !== newPassword.value)
                {
                    e.setCustomValidity("Password Mismatch");
                    alert("Password Mismatch");
                }
                else
                    e.setCustomValidity("");
            }
        </script>
        <style>
            .button{
                position: relative;
                left: 52.5%;
            }
            span{
                color: red;
            }
           #Div{
                font-size:20px;
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
            p{
                display:table-row;
            }
            label,span{
                display:table-cell;
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
            form{
                display: table;
            }
        </style>
    </head>
    <body>
        <%!
           String User;
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
        <div id="Div" align="center" >
            <h3 align="center">Change Your Password</h3>
            <form id="login" method="POST"
                  action="ChangePass.jsp">
                <p>
                  <label for="oldpassword">Old Password</label>
                  <input type="password" id="oldpassword" name="oldpassword" 
                                 minlength=6 autocomplete="on" autofocus required/>
                     <br/><br/>
                </p>
                <p>
                  <label for="passwd">New Password</label> 
                  <input type="password" id="passwd" name="passwd"
                          title="Password" onblur="newPassword(this)" 
                           minlength=6 required/>&nbsp;
                  <br/><br/>
                   
               </p>
               <p>
                  <label for="passwd">Confirm Password</label> 
                  <input type="password" id="cpasswd" name="cpasswd"
                          title="Confirm Password" onblur="confirmNewPass(this)" 
                           minlength=6 required/>&nbsp;
                  <br/><br/>
                  
               </p> 
               <p>
                  <input class="button" id="submit" type="submit" name="sumbit" value="Submit"/>
                  <input class="button" id="reset" type="reset" name="reset" value="Clear"/>
                     <br/><br/>
               </p>
            </form>
            <div align="center">
                <a target = "_parent" href="Loading.jsp">&lArr;Home</a>
            </div>
        </div>
    </body>
</html>

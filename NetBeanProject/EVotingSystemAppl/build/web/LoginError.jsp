<%-- 
    Document   : LoginError
    Created on : 5 Mar, 2017, 12:24:37 PM
    Author     : Guru Manikandan
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>E-Voting</title>
        <link rel="icon" type="image/png" href="image\Vote-icon.png"/>
        <link rel="stylesheet" type="text/css" href="css\background.css" />
        <%
            out.println("<style type='text/css'> "
                    + "a{text-decoration: none;"
                    + "color:black;"
                    + "font-size:20px;"
                    + "text-shadow: .5px 1px blue;}"
                    + "</style>");
        %>
    </head>
    <body>
        <div align="center">
            <h2>Please Login to Proceed</h2>
            <a target="_top" href="index.html">Login</a>
        </div>
    </body>
</html>

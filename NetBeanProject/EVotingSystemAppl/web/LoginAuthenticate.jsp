<%-- 
    Document   : LoginAuthenticate
    Created on : 10 Apr, 2017, 11:43:30 AM
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
            <h2>You have no Access to this page</h2>
            <a target="_top" href="UserPage.jsp">Back</a>
        </div>
    </body>
</html>

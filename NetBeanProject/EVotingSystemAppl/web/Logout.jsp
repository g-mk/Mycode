<%-- 
    Document   : Logout
    Created on : 5 Mar, 2017, 12:20:27 PM
    Author     : Guru Manikandan
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Logout</title>
        <%
            out.println("<style type=\"text/css\">"
                    + "img{ position:absolute;top:40%;left:45%}"
                    + "</style>");
        %>
    </head>
    <body>
        <%
            session.removeAttribute("USER");
            session.removeAttribute("VOTERID");
            session.invalidate();
            out.print("<img width=\"100px\" height=\"100px\" "
                        + "src=\"svg/graphics.svg\" />");
            response.setHeader("Refresh", "3;url=index.html");
        %>
    </body>
</html>

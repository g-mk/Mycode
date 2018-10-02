<%-- 
    Document   : Loading
    Created on : 9 Apr, 2017, 11:19:38 AM
    Author     : Guru Manikandan
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>E-Voting System</title>
        <link rel="icon" type="image/png" href="image\Vote-icon.png"/>
    </head>
    <body>
        <%  
            out.println("<style type=\"text/css\">"
                    + "#load{ position:absolute;top:40%;left:45%}"
                    + "</style>");
            
            out.print("<img id = \"load\" width=\"100px\" height=\"100px\" "
                        + "src=\"svg/graphics.svg\" />");
            if(session!=null)
            {
                if(session.getAttribute("USER")!=null && !session.getAttribute("USER").equals("Admin") )
                    response.setHeader("Refresh", "3;url=UserPage.jsp");
                else
                    response.setHeader("Refresh", "3;url=AdminPage.jsp");
            }
        %>
    </body>
</html>

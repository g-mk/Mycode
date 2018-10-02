<%-- 
    Document   : RemoveCandidate
    Created on : 11 Apr, 2017, 12:02:04 AM
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
        <meta charset="UTF-8">
        <title>Remove Candidate</title>
        <link rel="icon" type="image/png" href="image\Vote-icon.png"/>
        <link href="css/background.css" type="text/css" rel="stylesheet"/>
        <style type="text/css">
            form{
                display: table;
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
            a{
                text-decoration: none;
                font-size: 23px;
                color: background;
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
        <h1 align="center">Remove a candidate</h1>
        <div align="center">
            <form name="candidReg" method="GET" 
                  action ="RemoveCandidate.jsp" >
                <fieldset>
                    <legend>Candidate Information</legend>
                    <p>
                        <label for="CandidateID">Candidate ID</label>
                        <select id ="CandidateID" name="CandidateID">
                            <option>--Select--</option>
                            <%
                                try
                                {
                                    conn = DbConnect.Connect();
                                    String sql = "SELECT candid FROM 14bcs068_candidate";
                                    PreparedStatement stmt = conn.prepareStatement(sql);
                                    ResultSet rs = stmt.executeQuery();
                                    while(rs.next())
                                    {
                                        out.println("<option>"+rs.getString("candid")+"</option>");
                                    }
                                    out.println("</select>");
                                }
                                catch(SQLException exp)
                                {
                                    out.println("Error"+exp.getMessage());
                                }
                                finally{
                                    conn.close();
                                }
                            %>
                    </p>
                    <br/>
                    <div align="center">
                        <input id ="submit" type="submit" name="submit" value="Submit"/>&nbsp;
                        <input id = "reset"type="reset" name="reset" value="Reset"/>
                    </div>
                    
                </fieldset>
            </form>
            <br/>
            <a target="_parent" href="./AdminPage.jsp">Back</a>
        </div>
    </body>
</html>
<%-- 
    Document   : AddCandidate
    Created on : 10 Apr, 2017, 11:37:08 AM
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
        <title>Candidate Registration</title>
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
        <script type="text/javascript">
            function checkText(e)
            {
                var pattn = /^[a-zA-Z .]+$/;
                if(!pattn.test(e.value))
                {
                    e.setCustomValidity("Use Only Alphabets");
                }
                else
                    e.setCustomValidity("");
                
            }
            function checkSelect(e)
            {
                if(e.value === "--Select--")
                    e.setCustomValidity("Select a valid Option");
                else
                    e.setCustomValidity("");
            }
        </script>
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
        
        <h1 align="center">Register as a candidate</h1>
        <div align="center">
            <form name="candidReg" method="POST" 
                  action = "/EVotingSystemAppl/AddCandidateServlet" 
                  enctype="multipart/form-data">
                <fieldset>
                    <legend>Candidate Information</legend>
                    <p>
                        <label for="VoterID">Voter ID</label>
                        <select id ="VoterID" onload="checkSelect(this)" 
                                onblur="checkSelect(this)"
                                autofocus name="VoterID">
                            <option>--Select--</option>
                            <%
                                try
                                {
                                    conn = DbConnect.Connect();
                                    String sql = "SELECT voterid FROM 14bcs068_voterinfo";
                                    PreparedStatement stmt = conn.prepareStatement(sql);
                                    ResultSet rs = stmt.executeQuery();
                                    while(rs.next())
                                    {
                                        out.println("<option>"+rs.getString("voterid")+"</option>");
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
                    <p>
                        <label for="SymbolName">Symbol Name</label>
                        <input id ="SymbolName" type="text" name="SymbolName" 
                            onblur="checkText(this)" value="" size="15" 
                            required />
                    </p><br/>
                    <p>
                        <label for="Symbol">Logo</label>
                        <input type="file" name="Symbol" accept="image/*" 
                               required value=""/>
                    </p><br/>
                    <div align="center">
                        <input id = "submit" type="submit" name="submit" value="Submit"/>&nbsp;
                        <input id = "reset" type="reset" name="reset" value="Reset"/>
                    </div>
                </fieldset>
            </form>
            <br/>
            <a target="_parent" href="./AdminPage.jsp">Back</a>
        </div>
    </body>
</html>
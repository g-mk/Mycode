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
           String User,fName,mName,lName,fatherName,gender,dob,mobile,email;
           int age;
           Connection conn;
        %>
        <%
            if(session!=null)
            {
                if(session.getAttribute("USER")!=null && !session.
                        getAttribute("USER").toString().equals(""))
                {
                    User = session.getAttribute("USER").toString();
                    if (User.equals("Admin"))
                        session.setAttribute("VOTERID", request.getParameter("voterid"));
                }
                else
                {
                    RequestDispatcher dispatch = getServletContext().
                        getRequestDispatcher("/LoginError.jsp");
                    dispatch.forward(request, response);
                }
            }
        %>
        <h2 id="topDiv" align="center">Voter Registration Form</h2>
        <%
            try{
                conn = DbConnect.Connect();
                String sql = "SELECT * FROM 14bcs068_voterinfo WHERE voterid = ?";
                PreparedStatement stmt = conn.prepareStatement(sql);
                stmt.setString(1, session.getAttribute("VOTERID").toString());
                ResultSet rs = stmt.executeQuery();
                if(rs.next())
                {
                    fName = rs.getString("fname");
                    mName = rs.getString("mname");
                    lName = rs.getString("lname");
                    fatherName = rs.getString("fathername");
                    dob=rs.getString("dob");
                    age = rs.getInt("age");
                    mobile = rs.getString("mobile");
                    email = rs.getString("email");
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
        <div>
           <form id="regForm" method="GET" 
                 action="Update.jsp" 
                 autocomplete="on" >
              <fieldset>
                 <legend>Personal Information</legend>
                 <p>
                    <label for="voterFName">First Name</label> 
                    <input type="text" id="voterFName" name="voterFName"
                           value="<%= fName%>" onblur="checkText(this)" autofocus 
                          title="First Name" autocomplete="on" required/> &nbsp;
                    <i id ="CheckvoterFName" class="fa fa-check-circle-o" 
                       style="color:green;opacity:0;font-size: 20px;"></i>
                    <span class="errorLabel" id="errorvoterFName"></span> 
                    <br/><br/>
                 </p>
                 <p>
                    <label for="voterMName">Middle Name</label> 
                    <input type="text" id="voterMName" name="voterMName"
                            onblur="checkText(this)" value="<%= mName%>" /> &nbsp;
                    <i id ="CheckvoterMName" class="fa fa-check-circle-o" 
                       style="color:green;opacity:0;font-size: 20px;"></i>
                    <span class="errorLabel" id="errorvoterMName"></span> 
                    <br/><br/>

                 </p>
                 <p>
                    <label for="voterLName">Last Name</label> 
                    <input type="text" id="voterLName" name="voterLName"
                             value="<%= lName%>" onblur="checkText(this)"/> &nbsp;
                    <i id ="CheckvoterLName" class="fa fa-check-circle-o" 
                       style="color:green;opacity:0;font-size: 20px;"></i>
                    <span class="errorLabel" id="errorvoterLName"></span> 
                    <br/><br/>

                 </p>
                 <p>
                    <label for="vFatherName">Father's Name</label> 
                    <input type="text" id="vFatherName" title="Father Name"
                           value="<%= fatherName%>" onblur="checkText(this)" name="vFatherName" required/>
                    &nbsp;
                    <i id ="CheckvFatherName" class="fa fa-check-circle-o" 
                       style="color:green;opacity:0;font-size: 20px;"></i>
                    <span class="errorLabel" id="errorvFatherName"></span>
                    <br/><br/>

                 </p>
                 <p>
                    <label for="voterDOB">Date of Birth</label> 
                    <input type="date" id="voterDOB" name="voterDOB"
                       value="<%= dob%>" onblur="checkDOB(this)" 
                       placeholder="YYYY-MM-DD" 
                       onkeyup="appendDOB(this,event)"
                       title="Date Of Birth" required/> &nbsp;
                    <i id ="CheckvoterDOB" class="fa fa-check-circle-o" 
                       style="color:green;opacity:0;font-size: 20px;"></i>
                    <span class="errorLabel" id="errorDOB"></span>
                    <br/><br/>
                 </p>
                 <p>
                    <label for="age">Age</label> 
                    <input type="text" id="age" name="age" size="3"
                          value="<%= age%>" onblur ="checkAge(this)"
                          title="Age" required/> &nbsp;
                    <i id ="Checkage" class="fa fa-check-circle-o" 
                       style="color:green;opacity:0;font-size: 20px;"></i>
                    <span class="errorLabel" id="errorAge"></span>
                    <br/><br/>

                 </p>
              </fieldset>

              <fieldset>
                 <legend>Contact Information</legend>
                 <p>
                    <label for="mobile">Mobile</label> 
                    <input type="tel" id="mobile" name="mobile" title="Mobile"
                        pattern="^(\+\d{1,3}[- ]?)?\d{10}$" required
                        onblur="checkMobile(this)" value= "<%= mobile%>" 
                            placeholder="+91 1234567890"/>&nbsp;
                    <i id ="Checkmobile" class="fa fa-check-circle-o" 
                       style="color:green;opacity:0;font-size: 20px;"></i>
                    <span class="errorLabel" id="errorMobile"></span>
                    <br/><br/>

                 </p>

                 <p>
                    <label for="email">E-Mail</label> 
                    <input type="email" id="email" name="email" required
                        value="<%=email%>" onblur="checkMail(this)" 
                           placeholder="sample@mail.com" 
                           title="Mail Id" autocomplete="on"/>&nbsp;
                    <i id ="Checkemail" class="fa fa-check-circle-o" 
                       style="color:green;opacity:0;font-size: 20px;"></i>
                    <span class="errorLabel" id="errorMail"></span>
                    <br/><br/>
                 </p>
              </fieldset>
               <br/><br/>
               <div align="center">
                 <input id="submit"type="submit" name="Submit" value="Update" 
                           />
                 <input id = "reset" type="reset" name="Reset" value="Reset" />
              </div>
           </form>
        </div>
        <br/><br/><br/><br/><br/>
        <div>
           <a href="#topDiv" >
              <img id="goTop" src="image\arrow.jpg" width="50px" height="50px" 
                 alt="Not Found"/>
           </a>
        </div>
   </body>
</html>

<%-- 
    Document   : AdminPage
    Created on : 9 Apr, 2017, 12:37:02 PM
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
        <link rel="stylesheet" href="font-awesome-4.7.0\css\font-awesome.min.css">
        <script type="text/javascript" src="javascript\navigateTop.js" ></script>
        <script type="text/javascript">
           function linkTop()
           {
               var frm = document.getElementById("frame");
               frm.contentWindow.onscroll = function()
               {
                   showNavigation();
               }
           }
           window.onload = function()
           { 
               adjustFrame();
           }
           window.onresize = function(){ adjustFrame(); }
           function adjustFrame()
           {
              var frm = document.getElementById("frame");
              frm.setAttribute("height",window.innerHeight-225);
              frm.setAttribute("width",window.innerWidth-25);
           }
        </script>
        <style type="text/css">
            #submenu
            {
                width: 175%;
                position:absolute;
                top: 32px;
                left: -21px;
                display : none;
                z-index: 2;
            }
            #submenu li{
                display: list-item;
                
            }
            #dropdown:hover #submenu{
                display: block;
                padding-bottom: 6px;
                padding-top: 6px;
                
            }
            
        </style>
    </head>
    <body>
       <header>
         <h1 align="center">E-Voting System</h1>
       </header>
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
        <img id="lbanner" src="image\\vote-election.png" alt="Image Not Found"/>
        <img id="rbanner" src="image\\vote-election.png" alt="Image Not Found"/>
        <div id = "top">
           <ul class="menu">
              <li>
                 <a href="home.html" target="frame">
                     <i class="fa fa-home"></i>
                     <strong>Home</strong>
                 </a>
              </li>
              <li>
                 <a href="AddCandidateForm.jsp" target="frame">
                     <i class="fa fa-users"></i>
                    <strong>Add Candidate</strong>
                 </a>
              </li>
              <li>
                 <a href="ViewCandidate.jsp" target="frame">
                     <i class="fa fa-address-book-o"></i>
                    <strong>View Candidate</strong>
                 </a>
              </li>
              <li>
                 <a href="RemoveCandidateForm.jsp" target="frame">
                     <i class="fa fa-user-times"></i>
                    <strong>Remove Candidate</strong>
                 </a>
              </li>
              <li>
                 <a href="UpdateAll.jsp" target="frame">
                    <i class="fa fa-user-plus"></i>
                    <strong>Update Profile</strong>
                 </a>
              </li>
              <li>
                 <a href="ViewResult.jsp" target="frame">
                    <i class="fa fa-desktop"></i>
                    <strong>View Result</strong>
                 </a>
              </li>
              <li>
                 <a href="Reset.jsp" target="frame">
                    <i class="fa fa-wrench"></i>
                    <strong>Reset Voting</strong>
                 </a>
              </li>
              <li id = "dropdown" class="liRight">
                <a href="home.html" target="frame">
                    <i class="fa fa-user-circle-o"></i>
                    <strong>
                        <%= User%>&#9662;
                    </strong>
                </a>
                <ul class ="menu" id="submenu">
                    <li>
                        <a href="UserProfile.jsp" target="frame">
                            <i class="fa fa-photo"></i>
                            <strong>
                                Profile
                            </strong>
                        </a>
                    </li>
                    <li>
                        <a href="ChangePassword.jsp" target="frame">
                            <i class="fa fa-pencil-square-o"></i>
                            <strong>
                                Change Password
                            </strong>
                        </a>
                    </li>
                    <li>
                        <a href="Logout.jsp" target="_parent">
                            <i class="fa fa-sign-out"></i>
                            <strong>
                                Logout
                            </strong>
                        </a>
                    </li>
                </ul>
              </li>
           </ul>
        </div>
        <iframe id="frame" name="frame" src="home.html" style="border:none" 
                 onload="linkTop()"></iframe>
        <footer id = "footer">
           Electronic Voting<br/>
           Copy Right<sup>&copy;</sup> to N. Guru Manikandan.
           Created on January 23, 2017.
        </footer>
    </body>
</html>

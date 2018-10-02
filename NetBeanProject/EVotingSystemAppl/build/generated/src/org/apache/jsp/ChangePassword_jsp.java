package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class ChangePassword_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final JspFactory _jspxFactory = JspFactory.getDefaultFactory();

  private static java.util.List<String> _jspx_dependants;

  private org.glassfish.jsp.api.ResourceInjector _jspx_resourceInjector;

  public java.util.List<String> getDependants() {
    return _jspx_dependants;
  }

  public void _jspService(HttpServletRequest request, HttpServletResponse response)
        throws java.io.IOException, ServletException {

    PageContext pageContext = null;
    HttpSession session = null;
    ServletContext application = null;
    ServletConfig config = null;
    JspWriter out = null;
    Object page = this;
    JspWriter _jspx_out = null;
    PageContext _jspx_page_context = null;

    try {
      response.setContentType("text/html;charset=UTF-8");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;
      _jspx_resourceInjector = (org.glassfish.jsp.api.ResourceInjector) application.getAttribute("com.sun.appserv.jsp.resource.injector");

      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("<!DOCTYPE html>\n");
      out.write("<html>\n");
      out.write("    <head>\n");
      out.write("        <meta charset=\"UTF-8\">\n");
      out.write("        <title>Candidate Registration</title>\n");
      out.write("        <link rel=\"icon\" type=\"image/png\" href=\"image\\Vote-icon.png\"/>\n");
      out.write("        <link href=\"css/background.css\" type=\"text/css\" rel=\"stylesheet\"/>\n");
      out.write("        <script type=\"text/javascript\">\n");
      out.write("            function newPassword(e)\n");
      out.write("            {\n");
      out.write("                if(e.value.length<6)\n");
      out.write("                {\n");
      out.write("                    e.setCustomValidity(\"Give Atleast 6 character\");\n");
      out.write("                    alert(\"Give Atleast 6 character\");\n");
      out.write("                }\n");
      out.write("                else\n");
      out.write("                    e.setCustomValidity(\"\");\n");
      out.write("            }\n");
      out.write("            function confirmNewPass(e)\n");
      out.write("            {\n");
      out.write("                var newPassword = document.getElementById(\"passwd\");\n");
      out.write("                if(e.value !== newPassword.value)\n");
      out.write("                {\n");
      out.write("                    e.setCustomValidity(\"Password Mismatch\");\n");
      out.write("                    alert(\"Password Mismatch\");\n");
      out.write("                }\n");
      out.write("                else\n");
      out.write("                    e.setCustomValidity(\"\");\n");
      out.write("            }\n");
      out.write("        </script>\n");
      out.write("        <style>\n");
      out.write("            span{\n");
      out.write("                color: red;\n");
      out.write("            }\n");
      out.write("           #Div{\n");
      out.write("                font-size:20px;\n");
      out.write("                -webkit-transition: 2s;\n");
      out.write("                transition: 2s;\n");
      out.write("           }\n");
      out.write("           a{\n");
      out.write("                text-decoration:none;\n");
      out.write("                color:black;\n");
      out.write("                font-weight:bold;\n");
      out.write("           }\n");
      out.write("           #submit,#reset{\n");
      out.write("                background-color: rgba(66,118,208,1);\n");
      out.write("                padding: 2px 2px 2px 2px;\n");
      out.write("                color: white;\n");
      out.write("                font-style:bold;\n");
      out.write("           }\n");
      out.write("           #submit:hover,#reset:hover{\n");
      out.write("                cursor: pointer;\n");
      out.write("                background-color: white;\n");
      out.write("                padding: 2px 2px 2px 2px;\n");
      out.write("                color: rgba(66,118,208,1);\n");
      out.write("                font-style:bold;\n");
      out.write("            }\n");
      out.write("            p{\n");
      out.write("                display:table-row;\n");
      out.write("            }\n");
      out.write("            label,span{\n");
      out.write("                display:table-cell;\n");
      out.write("            }\n");
      out.write("            input{\n");
      out.write("                display:table-cell;\n");
      out.write("            }\n");
      out.write("\n");
      out.write("            i{\n");
      out.write("                -webkit-transition: all 0.50s ease-in-out;\n");
      out.write("                -moz-transition: all 0.50s ease-in-out;\n");
      out.write("                transition: all 0.50s ease-in-out;\n");
      out.write("                display:inline;\n");
      out.write("            }\n");
      out.write("            form{\n");
      out.write("                display: table;\n");
      out.write("            }\n");
      out.write("        </style>\n");
      out.write("    </head>\n");
      out.write("    <body>\n");
      out.write("        <div id=\"Div\" align=\"center\" >\n");
      out.write("            <h3 align=\"center\">Change Your Password</h3>\n");
      out.write("            <form id=\"login\" method=\"POST\"\n");
      out.write("                  action=\"\">\n");
      out.write("                <p>\n");
      out.write("                  <label for=\"oldpassword\">Old Password</label>\n");
      out.write("                  <input type=\"password\" id=\"oldpassword\" name=\"oldpassword\" \n");
      out.write("                                 minlength=6 autocomplete=\"on\" autofocus required/>\n");
      out.write("                     <br/><br/>\n");
      out.write("                </p>\n");
      out.write("                <p>\n");
      out.write("                  <label for=\"passwd\">New Password</label> \n");
      out.write("                  <input type=\"password\" id=\"passwd\" name=\"passwd\"\n");
      out.write("                          title=\"Password\" onblur=\"newPassword(this)\" \n");
      out.write("                           minlength=6 required/>&nbsp;\n");
      out.write("                  <span style=\"color:red;\" id=\"errorPasswd\"></span>\n");
      out.write("                  <br/><br/>\n");
      out.write("                   \n");
      out.write("               </p>\n");
      out.write("               <p>\n");
      out.write("                  <label for=\"passwd\">Confirm Password</label> \n");
      out.write("                  <input type=\"password\" id=\"cpasswd\" name=\"cpasswd\"\n");
      out.write("                          title=\"Confirm Password\" onblur=\"confirmNewPass(this)\" \n");
      out.write("                           minlength=6 required/>&nbsp;\n");
      out.write("                  <span style=\"color:red;\" id=\"errorCPasswd\"></span> \n");
      out.write("                  <br/><br/>\n");
      out.write("                  \n");
      out.write("               </p> \n");
      out.write("               <p>\n");
      out.write("                  <input id=\"submit\" type=\"submit\" name=\"sumbit\" value=\"Submit\"/>\n");
      out.write("                  <input id=\"reset\" type=\"reset\" name=\"reset\" value=\"Clear\"/>\n");
      out.write("                     <br/><br/>\n");
      out.write("               </p>\n");
      out.write("            </form>\n");
      out.write("            <div align=\"center\">\n");
      out.write("                <a target = \"_parent\" href=\"Loading.jsp\">&lArr;Home</a>\n");
      out.write("            </div>\n");
      out.write("        </div>\n");
      out.write("    </body>\n");
      out.write("</html>\n");
    } catch (Throwable t) {
      if (!(t instanceof SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          out.clearBuffer();
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}

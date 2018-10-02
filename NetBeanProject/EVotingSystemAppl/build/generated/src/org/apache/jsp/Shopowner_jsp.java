package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class Shopowner_jsp extends org.apache.jasper.runtime.HttpJspBase
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

      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("<!DOCTYPE html>\r\n");
      out.write("<html>\r\n");
      out.write("    <head>\r\n");
      out.write("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\r\n");
      out.write("        <title>Shop owner Page</title>\r\n");
      out.write("        \r\n");
      out.write("<script>\r\n");
      out.write("    function loadToday()\r\n");
      out.write("    {\r\n");
      out.write("                  var today = new Date();\r\n");
      out.write("var dd = today.getDate();\r\n");
      out.write("var mm = today.getMonth()+1; //January is 0!\r\n");
      out.write("var yyyy = today.getFullYear();\r\n");
      out.write("\r\n");
      out.write("if(dd<10) {\r\n");
      out.write("    dd = '0'+dd;\r\n");
      out.write("} \r\n");
      out.write("\r\n");
      out.write("if(mm<10) {\r\n");
      out.write("    mm = '0'+mm;\r\n");
      out.write("} \r\n");
      out.write("\r\n");
      out.write("today =  yyyy+ '-' + mm+ '-' +dd  ;\r\n");
      out.write("    document.getElementById('sdate').value = today;\r\n");
      out.write("    }\r\n");
      out.write("/*function dateDiff(dateform) {\r\n");
      out.write("date1 = new Date();\r\n");
      out.write("date2 = new Date();\r\n");
      out.write("diff  = new Date();\r\n");
      out.write("\r\n");
      out.write("date1temp = new Date(dateform.firstdate.value);\r\n");
      out.write("date1.setTime(date1temp.getTime());\r\n");
      out.write("\r\n");
      out.write("date2temp = new Date(dateform.seconddate.value);\r\n");
      out.write("date1.setTime(date2temp.getTime());\r\n");
      out.write("\r\n");
      out.write("/*date2temp = new Date(Date.parse(document.getElementById(\"seconddate\").value));\r\n");
      out.write("date2.setTime(date2temp.getTime());*/\r\n");
      out.write("\r\n");
      out.write("/*diff.setTime(Math.abs(date1.getTime() - date2.getTime()));\r\n");
      out.write("\r\n");
      out.write("timediff = diff.getTime();\r\n");
      out.write("days = Math.floor(timediff / (1000 * 60 * 60 * 24)); \r\n");
      out.write("document.getElementById(\"difference\").value = days;\r\n");
      out.write("//year=Math.ceil(days/365);\r\n");
      out.write("//location.href=\"eval.jsp?year=\"+year;\r\n");
      out.write("return false; \r\n");
      out.write("\r\n");
      out.write("}*/\r\n");
      out.write("function dateDiff(dateform) {\r\n");
      out.write("date1 = new Date(dateform.firstdate.value);\r\n");
      out.write("date2 = new Date(dateform.seconddate.value);\r\n");
      out.write("diff  = new Date();\r\n");
      out.write("alert(date1);\r\n");
      out.write("alert(date2);\r\n");
      out.write("//date1temp = new Date(dateform.firstdate.value);\r\n");
      out.write("//date1.setTime(date1temp.getTime());\r\n");
      out.write("//\r\n");
      out.write("//date2temp = new Date(dateform.seconddate.value);\r\n");
      out.write("//date2.setTime(date2temp.getTime());\r\n");
      out.write("diff.setTime(Math.abs(date1.getTime() - date2.getTime()));\r\n");
      out.write("\r\n");
      out.write("timediff = diff.getTime();\r\n");
      out.write("days = Math.floor(timediff / (1000 * 60 * 60 * 24)); \r\n");
      out.write("dateform.difference.value = days;\r\n");
      out.write("year=Math.ceil(days/365);\r\n");
      out.write("location.href=\"eval.jsp?year=\"+year;\r\n");
      out.write("return false; \r\n");
      out.write("\r\n");
      out.write("}\r\n");
      out.write("</script>\r\n");
      out.write("</head>\r\n");
      out.write("<body onload=loadToday()>\r\n");
      out.write("<form onSubmit=\"return dateDiff(this);\">\r\n");
      out.write("<pre>\r\n");
      out.write("First Date(MM/DD/YYYY):     <input type=date name=firstdate>   \r\n");
      out.write("\r\n");
      out.write("Second Date(MM/DD/YYYY):   <input  type=text name=seconddate id=sdate> \r\n");
      out.write("                             <!--<input  type=date name=seconddate id=sdate> -->\r\n");
      out.write("\r\n");
      out.write("Date Difference (in days):  <input type=text id=difference name=difference>\r\n");
      out.write("\r\n");
      out.write("                            <input type=submit value=\"Calculate Difference!\" >\r\n");
      out.write("\r\n");
      out.write("</pre>\r\n");
      out.write("</form>\r\n");
      out.write("</body>\r\n");
      out.write("</html>");
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

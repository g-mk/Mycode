package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.ResultSet;
import java.sql.PreparedStatement;
import evoting.DbConnect;
import java.sql.Connection;

public final class RemoveCandidate_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {


           String User;
           Connection conn;
        
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
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("<!DOCTYPE html>\n");
      out.write("<html>\n");
      out.write("    <head>\n");
      out.write("        <meta charset=\"UTF-8\">\n");
      out.write("        <title>Remove Candidate</title>\n");
      out.write("        <link rel=\"icon\" type=\"image/png\" href=\"image\\Vote-icon.png\"/>\n");
      out.write("        <link href=\"css/background.css\" type=\"text/css\" rel=\"stylesheet\"/>\n");
      out.write("        <meta http-equiv=\"refresh\" content=\"3;url=RemoveCandidateForm.jsp\">\n");
      out.write("    </head>\n");
      out.write("        ");
      out.write("\n");
      out.write("        ");

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
        
      out.write("\n");
      out.write("    <body>\n");
      out.write("        ");

            try
            {
                conn = DbConnect.Connect();
                String sql = "DELETE FROM 14bcs068_candidate WHERE candid=?";
                PreparedStatement stmt = conn.prepareStatement(sql);
                stmt.setString(1, request.getParameter("CandidateID"));
                int stat = stmt.executeUpdate();
                if(stat>0)
                {
                    out.println("<h2 align=center>Candidate Removed Successfully</h2>");
                }
                else
                    out.println("<h2 align=center>Candidate Removal Faild due to some error.!!"
                            + "<br/>Try Again Some Time!!!!</h2>");
            }
            catch(SQLException exp)
            {
                out.println("Error"+exp.getMessage());
            }
            finally{
                conn.close();
            }
        
      out.write("\n");
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

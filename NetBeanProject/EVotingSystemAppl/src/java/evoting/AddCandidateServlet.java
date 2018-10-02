/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package evoting;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Part;

/**
 *
 * @author Guru Manikandan
 */
public class AddCandidateServlet extends HttpServlet {

    private Connection conn;
    boolean isVoter(Connection conn,String voterid){
                String sql = "SELECT * FROM 14bcs068_candidate WHERE voterid = ?";
                try {
                    PreparedStatement stmt = conn.prepareStatement(sql);
                    stmt.setString(1, voterid);
                    ResultSet rs = stmt.executeQuery();
                    return rs.next();
                } catch (SQLException ex) {
                    Logger.getLogger(AddCandidateServlet.class.getName()).log(Level.SEVERE, null, ex);
                }
                return false;
            }
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        String voterid;
        Part symbol;
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<meta charset=\"UTF-8\">\n" +
    "<title>Candidate Registration</title>\n" +
    "<link rel=\"icon\" type=\"image/png\" href=\"image\\Vote-icon.png\"/>\n" +
    "<link href=\"css/background.css\" type=\"text/css\" rel=\"stylesheet\"/>\n" +
    "<meta http-equiv=\"refresh\" content=\"3; URL=AddCandidateForm.jsp\" />");            
            out.println("</head>");
            out.println("<body>");
            voterid=request.getParameter("VoterID");
            if(!isVoter(conn, voterid))
            {
                String sql = "INSERT INTO 14bcs068_candidate VALUES (?,?,?,?,?)";
                PreparedStatement stmt = conn.prepareStatement(sql);
                stmt.setString(1, voterid+"C");
                stmt.setString(2, voterid);
                stmt.setString(3, request.getParameter("SymbolName"));
                symbol = request.getPart("Symbol");
                stmt.setDouble(4, symbol.getSize());
                stmt.setBlob(5, symbol.getInputStream());
                int result = stmt.executeUpdate();
                if(result>0)
                {
                    out.println("<h2 align=center>Candidate Registration Successfull</h2>");
                }
                else
                    out.println("<h2 align=center>Candidate Registration Failed</h2>");
                    
            }
            else
                out.println("<h2 align=center>Candidate Alredy Registered</h2>");
            out.println("</body>");
            out.println("</html>");
        } catch (SQLException ex) {
            Logger.getLogger(AddCandidateServlet.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    @Override
    public void init(ServletConfig sc) throws ServletException{
        super.init(sc);
        try {
                conn = DbConnect.Connect();
            } catch (SQLException | ClassNotFoundException ex) {
            Logger.getLogger(AddCandidateServlet.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
    }
    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }
    @Override
    public void destroy()
    {
        try {
            conn.close();
        } catch (SQLException ex) {
            Logger.getLogger(AddCandidateServlet.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}

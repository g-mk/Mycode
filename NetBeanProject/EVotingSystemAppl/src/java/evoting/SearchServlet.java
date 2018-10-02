/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package evoting;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.*;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Guru Manikandan
 */
public class SearchServlet extends HttpServlet {

    private Connection conn;
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
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet SearchServlet</title>");
            out.println("<link href='css/background.css' type='text/css'"
                    + " rel='stylesheet'/>");
            out.println("<style type='text/css'> "
                    + "a{text-decoration: none;"
                    + "color:black;"
                    + "font-size:20px;"
                    + "text-shadow: .5px 1px blue;}"
                    + "</style>");
            out.println("</head>");
            out.println("<body>");
            String sql = "SELECT * FROM 14bcs068_voterinfo WHERE voterid = ?";
            PreparedStatement stmt = conn.prepareStatement(sql);
            stmt.setString(1, request.getParameter("query"));
            ResultSet rs = stmt.executeQuery();
            if(rs.next())
            {
                out.println("<div align=center><h2>Voter List Available</h2>");
                out.println("<p align=center>Name: "+rs.getString("fname")+" "+ 
                        rs.getString("lname"));
                out.println("<br/>Gender: "+rs.getString("gender"));
                out.println("<br/>Mobile:"+rs.getString("mobile"));
                out.println("<br/>Email:"+rs.getString("email"));
                out.println("<br/><br/><a href='login.html'>Login</a> "
                        + "to Vote");
                out.println("<br/><br/><a href = 'VotersList.html'>"
                        + "&lAarr; Back</a></p></div>");
                
            }
            else
            {
                out.println("<div align=center><h2>Voter List Not Available</h2>");
                out.println("<p align = center>No Data Found");
                out.println("<br/><br/><a href='VotersRegForm.html'>"
                        + "Register Here!!!</a> to Vote");
                out.println("<br/><br/><a href = 'VotersList.html'>"
                        + "&lAarr; Back</a></p></div>");
            }
                
            out.println("</body>");
            out.println("</html>");
        } catch (SQLException ex) {
            Logger.getLogger(SearchServlet.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
    @Override
    public void init(ServletConfig sc) throws ServletException{
        super.init(sc);
        try {
                conn = DbConnect.Connect();
            } catch (SQLException | ClassNotFoundException ex) {
            Logger.getLogger(SearchServlet.class.getName()).log(Level.SEVERE, null, ex);
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
            Logger.getLogger(SearchServlet.class.getName()).log(Level.SEVERE, null, ex);
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

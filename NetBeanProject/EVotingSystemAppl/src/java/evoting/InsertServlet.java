/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package evoting;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import javax.servlet.*;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.http.Part;

/**
 *
 * @author Guru Manikandan
 */
public class InsertServlet extends HttpServlet {

    private Connection conn;
    private static final String IDSUFFIX = "INDVTR";
    private int voterid;
    
    public boolean isVoter(String name, String fathername,String dob){
        String sql = "SELECT * FROM 14bcs068_voterinfo WHERE "
                + "UPPER(fname) = UPPER(?) "
                + "AND dob = ? AND UPPER(fathername) = UPPER(?)";
        try {
            PreparedStatement stmt = conn.prepareStatement(sql);
            stmt.setString(1, name);
            stmt.setString(2, dob);
            stmt.setString(3, fathername);
            ResultSet rs = stmt.executeQuery();
            return rs.next();
            
        } catch (SQLException ex) {
            Logger.getLogger(InsertServlet.class.getName()).
                    log(Level.SEVERE, null, ex);
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
    protected void processRequest(HttpServletRequest request, 
            HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out= response.getWriter();
        try{
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet InsertServlet</title>");
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
            String fName = request.getParameter("voterFName");
            String DOB = request.getParameter("voterDOB");
            String fatherName = request.getParameter("vFatherName");
            if(!isVoter(fName, fatherName,DOB))
            {
                Part photo,idproof,addproof;
                photo = request.getPart("photo");
                idproof = request.getPart("idProof");
                addproof = request.getPart("addProof");
                String id = IDSUFFIX + voterid;
                String mName = request.getParameter("voterMName");
                String lName = request.getParameter("voterLName");
                int age = Integer.parseInt(request.getParameter("age"));
                String gender = request.getParameter("Gender");
                String mobile = request.getParameter("mobile");
                String email = request.getParameter("email");
                String doorNo = request.getParameter("doorNo");
                String state = request.getParameter("voterState");
                String city = request.getParameter("voterCity");
                String street = request.getParameter("voterStreet");
                String user = request.getParameter("usrid");
                String password = request.getParameter("passwd");
                String sqlInfo = "INSERT INTO 14bcs068_voterinfo "
                        + "VALUES(?,?,?,?,?,?,?,?,"
                        + "?,?,?,?,?,?)";
                String sqlLogin = "INSERT INTO 14bcs068_login VALUES(?,?,?)";
                String sqlProof = "INSERT INTO 14bcs068_voterproof "
                        + "VALUES(?,?,?,?,?,"
                        + "?,?,?,?,?)";
                PreparedStatement stmt = conn.prepareStatement(sqlInfo);
                //Set Statement for Voter Info
                stmt.setString(1, id);
                stmt.setString(2, fName);
                stmt.setString(3, mName);
                stmt.setString(4, lName);
                stmt.setString(5, fatherName);
                stmt.setString(6, DOB);
                stmt.setInt(7, age);
                stmt.setString(8, gender);
                stmt.setString(9, mobile);
                stmt.setString(10, email);
                stmt.setString(11, doorNo);
                stmt.setString(12, state);
                stmt.setString(13, city);
                stmt.setString(14, street);
                int stat1 = stmt.executeUpdate();
                //Set Statement for Login 
                PreparedStatement stmtLogin = conn.prepareStatement(sqlLogin);
                stmtLogin.setString(1, user);
                stmtLogin.setString(2, password);
                stmtLogin.setString(3, id);
                int stat2 = stmtLogin.executeUpdate();
                //Set Statement for Proof
                PreparedStatement stmtProof = conn.prepareStatement(sqlProof);
                stmtProof.setString(1, id);
                stmtProof.setString(2, photo.getSubmittedFileName());
                stmtProof.setDouble(3, photo.getSize());
                stmtProof.setBlob(4, photo.getInputStream());
                stmtProof.setString(5, idproof.getSubmittedFileName());
                stmtProof.setDouble(6, idproof.getSize());
                stmtProof.setBlob(7, idproof.getInputStream());
                stmtProof.setString(8, addproof.getSubmittedFileName());
                stmtProof.setDouble(9, addproof.getSize());
                stmtProof.setBlob(10, addproof.getInputStream());
                int stat3 = stmtProof.executeUpdate();
                if((stat1>0) && (stat2>0) && (stat3>0))
                {
                    voterid++;
                    FileWriter fw = new FileWriter("F:\\Studies\\VI SEM\\LAB\\"
                        + "NetBeanProject\\EVotingSystemAppl\\web\\IdDetails\\"
                        + "voterID.txt");
                    fw.write(""+voterid);
                    fw.close();
                    out.println("<h2 align=center>Registration Successfull</h2>"
                            + "<div align = 'center'>"
                            + "<p>Your Voter Id is <b>"+id+"</b></p>");
                    out.println("<br/><br/><a href='Login.jsp'>Login</a> "
                            + "to Vote");
                    out.println("<br/><br/><a href = 'VotersRegForm.html'>"
                            + "&lt;&ltBack&gt&gt</a></div>");
                }
                else
                {
                    out.println("<div align = 'center'><h2>Registration "
                            + "Not Succeeded"
                            + "</h2><p>Try Again Sometime other Time</p>");
                    out.println("<br/><br/><a href = 'VotersRegForm.html'>"
                            + "&lt;&ltBack&gt&gt</a></div>");
                }
            }
            else{
                out.println("<div align = 'center'><h2>Voter Details already "
                        + "exist </h2><p>Check in the Voters List Tab</p>");
                    out.println("<br/><br/><a href = 'VotersList.html'>"
                            + "&lt;&ltCheck It&gt&gt</a></div>");
            }
            
            out.println("</body>");
            out.println("</html>");
        } catch (SQLException ex) {
            Logger.getLogger(InsertServlet.class.getName()).
                    log(Level.SEVERE, null, ex);
            out.println("<div align = 'center'><h2>Registration Not Succeeded"
                        + "</h2><p>Try Again Sometime other Time</p></p>");
                out.println("<br/><br/><a href = 'VotersRegForm.html'>"
                        + "&lt;&ltBack&gt&gt</a></div>");
                out.println(ex);
            
        }
    }
    @Override
    public void init(ServletConfig sc) throws ServletException{
        super.init(sc);
        BufferedReader in;
        try {
            conn = DbConnect.Connect();
            FileReader fr = new FileReader("F:\\Studies\\VI SEM\\LAB\\"
                    + "NetBeanProject\\EVotingSystemAppl\\web\\IdDetails"
                    + "\\voterID.txt");
            in = new BufferedReader(fr);
            String inputID = in.readLine().toString();
            voterid = Integer.parseInt(inputID);
            in.close();
            } catch (SQLException | ClassNotFoundException ex) {
            Logger.getLogger(SearchServlet.class.getName()).
                    log(Level.SEVERE, null, ex);
        } catch (FileNotFoundException ex) {
            Logger.getLogger(InsertServlet.class.getName()).
                    log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(InsertServlet.class.getName()).
                    log(Level.SEVERE, null, ex);
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
            Logger.getLogger(SearchServlet.class.getName()).
                    log(Level.SEVERE, null, ex);
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

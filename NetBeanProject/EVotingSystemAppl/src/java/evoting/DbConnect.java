/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package evoting;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 *
 * @author Guru Manikandan
 */
public class DbConnect {
    private static final String URL = "jdbc:mysql://localhost:3306/14bsec1";
    private static final String USER = "root";
    private static final String PASSWORD = "root";
    public static Connection Connect()throws ClassNotFoundException, SQLException{
        Class.forName("com.mysql.jdbc.Driver");
        Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
        return conn;
    }
    
}

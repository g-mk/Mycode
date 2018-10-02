/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mims;

import java.sql.Date;
import java.sql.*;

/**
 *
 * @author Guru Manikandan
 */
public class Medicine {
    private String mId;
    private String mName;
    private float price;
    private Date mgfDate;
    private Date expDate;
    private int qty;
    private String desc;
    public Medicine()
    {
        mId = "";
        mName = "";
        price = 0;
        mgfDate = null;
        expDate = null;
        qty = 0;
        desc = "";
    }
    public Medicine(String id){
        mId = id;
        mName = "";
        price = 0;
        mgfDate = null;
        expDate = null;
        qty = 0;
        desc = "";
    }
    public void getMedicineDetails() throws SQLException, ClassNotFoundException
    {
        Connection conn;
        conn = DbConnect.Connect();
        String sql = "SELECT * FROM medicine WHERE mid = ?";
        PreparedStatement stmt = conn.prepareStatement(sql);
        stmt.setString(1, mId);
        ResultSet rs = stmt.executeQuery();
        if(rs.next())
        {
            mName = rs.getString("mname");
            price = rs.getFloat("price");
            mgfDate = rs.getDate("mgfdate");
            expDate = rs.getDate("expdate");
            qty = rs.getInt("qty");
            desc = rs.getString("desc");
        }
        conn.close();
    }
    public boolean updateMedicine() throws SQLException, ClassNotFoundException
    {
        Connection conn;
        conn = DbConnect.Connect();
        String sql = "UPDATE medicine SET qty = ? WHERE mid = ?";
        PreparedStatement stmt = conn.prepareStatement(sql);
        stmt.setInt(1, qty);
        stmt.setString(2, mId);
        int rs = stmt.executeUpdate();
        conn.close();
        return (rs>0);
    }
    public boolean updateAll() throws SQLException, ClassNotFoundException
    {
        Connection conn;
        conn = DbConnect.Connect();
        String sql = "UPDATE medicine SET qty = ?, mname =?, price=?, `desc`=?, mgfdate=?, expdate=? WHERE mid = ?;";
        PreparedStatement stmt = conn.prepareStatement(sql);
        stmt.setInt(1, qty);
        stmt.setString(2,mName);
        stmt.setFloat(3,price);
        stmt.setString(4,desc);
        stmt.setString(5,mgfDate.toString());
        stmt.setString(6, mgfDate.toString());
        stmt.setString(7, mId);
        int rs = stmt.executeUpdate();
        conn.close();
        return (rs>0);
    }
    public String getId()
    {
        return mId;
    }
    public String getName()
    {
        return mName;
    }
    public void setName(String name)
    {
        mName=name;
    }
    public float getPrice()
    {
        return price;
    }
    public void setPrice(float price)
    {
        this.price = price;
    }
    public Date getMgfDate()
    {
        return mgfDate;
    }
    public void setMgfDate(Date mdate)
    {
        mgfDate=mdate;
    }
    public Date getExpDate()
    {
        return expDate;
    }
    public void setExpDate(Date edate)
    {
        expDate=edate;
    }
    public int getQuantity()
    {
        return qty;
    }
    public void setQuantity(int quantity)
    {
        qty=quantity;
    }
    public String getDesc()
    {
        return desc;
    }
    public void setDesc(String description)
    {
        desc=description;
    }
}

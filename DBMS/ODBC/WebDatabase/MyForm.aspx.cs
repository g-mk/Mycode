﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using MySql.Data.MySqlClient;
using System.Data;


public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        MySqlConnection con = new MySqlConnection("server=localhost;database=guru;uid=root");
        String Gen;
        if (Male.Checked)
            Gen = "M";
        else
            Gen = "F";
        MySqlCommand cmd = new MySqlCommand("INSERT INTO employee VALUES ('" + TextBox1.Text + "','" + TextBox2.Text + "','" + Gen + "'," + TextBox3.Text + "," + TextBox4.Text + ")");
        Label6.Text = "";
        cmd.Connection = con;
        try
        {
            con.Open();
            int result = cmd.ExecuteNonQuery();

            if (result > 0)
            {
                Label6.Text = "Insert Success!";
                Label6.Visible = true;
            }
            else
            {
                Label6.Text = "Insert Failed!";
                Label6.Visible = true;
            }
            TextBox1.Text = "";
            TextBox2.Text = "";
            Male.Checked = false;
            TextBox3.Text = "";
            TextBox4.Text = "";
            con.Close();
            MySqlConnection con1 = new MySqlConnection("server=localhost;database=guru;uid=root");
            MySqlCommand cmd1 = new MySqlCommand("SELECT * FROM employee");
            con1.Open();
            cmd1.Connection = con1;
            MySqlDataReader dr = cmd1.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            GridView1.DataSource = dt;
            GridView1.DataBind();
            con1.Close();
            }
        catch (MySqlException ex)
        {
            Label6.Text = "Insert Failed!";
            Label6.Visible = true;
        }
        finally
        {
            con.Close();
        }
     }
    protected void Button4_Click(object sender, EventArgs e)
    {
        MySqlConnection con = new MySqlConnection("server=localhost;database=guru;uid=root");
        MySqlCommand cmd = new MySqlCommand("SELECT * FROM employee");
        cmd.Connection = con;
        try
        {
            TextBox1.Text = "";
            TextBox2.Text = "";
            TextBox3.Text = "";
            TextBox4.Text = "";
            con.Open();
            MySqlDataReader dr = cmd.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            GridView1.DataSource = dt;
            GridView1.DataBind();

        }
        catch (MySqlException ex)
        {
            
        }
        finally
        {
            con.Close();
        }
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        MySqlConnection con = new MySqlConnection("server=localhost;database=guru;uid=root");
        MySqlCommand cmd = new MySqlCommand("Delete from employee WHERE emp_id='" + TextBox1.Text + "'");
        cmd.Connection = con;
        try
        {
            Label6.Text = "";
            con.Open();
            int result = cmd.ExecuteNonQuery();

            if (result > 0)
            {
                Label6.Text = "Deletion Success!";
                Label6.Visible = true;
            }
            else
            {
                Label6.Text = "Deletion Failed!";
                Label6.Visible = true;
            }
            TextBox1.Text = "";
            TextBox2.Text = "";
            Male.Checked = false;
            Female.Checked = false;
            TextBox3.Text = "";
            TextBox4.Text = "";
            con.Close();
            MySqlConnection con1 = new MySqlConnection("server=localhost;database=guru;uid=root");
            MySqlCommand cmd1 = new MySqlCommand("SELECT * FROM employee");
            con1.Open();
            cmd1.Connection = con1;
            MySqlDataReader dr = cmd1.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            GridView1.DataSource = dt;
            GridView1.DataBind();
            con1.Close();

        }
        catch (MySqlException ex)
        {
            Label6.Text = "Deletion Failed!";
            Label6.Visible = true;

        }
        finally
        {
            con.Close();
        }
    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        try
        {
            MySqlConnection con = new MySqlConnection("server=localhost;database=guru;uid=root");
            String Gen;
            if (Male.Checked)
                Gen = "M";
            else
                Gen = "F";
            MySqlCommand cmd = new MySqlCommand("UPDATE employee SET emp_name='" + TextBox2.Text + "',Gender='" + Gen + "',Mobile='" + TextBox3.Text + "',salary=" + TextBox4.Text+" WHERE emp_id='" + TextBox1.Text + "'");
            cmd.Connection = con;
            con.Open();
            int result = cmd.ExecuteNonQuery();

            if (result > 0)
            {
                Label6.Text = "Update Success!";
                Label6.Visible = true;
            }
            else
            {
                Label6.Text = "Update Failed!";
                Label6.Visible = true;
            }
           
            TextBox1.Text = "";
            TextBox2.Text = "";
            Male.Checked = false;
            Female.Checked = false;
            TextBox3.Text = "";
            TextBox4.Text = "";
            con.Close();
            MySqlConnection con1 = new MySqlConnection("server=localhost;database=guru;uid=root");
            MySqlCommand cmd1 = new MySqlCommand("SELECT * FROM employee");
            con1.Open();
            cmd1.Connection = con1;
            MySqlDataReader dr = cmd1.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            GridView1.DataSource = dt;
            GridView1.DataBind();
            con1.Close();
        }
        catch (MySqlException ex)
        {
            Label6.Text = "Update Failed!";
            Label6.Visible = true;
        }
    }
}
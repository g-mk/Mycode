using System;
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
    protected void Button2_Click(object sender, EventArgs e)
    {
        try
        {
            MySqlConnection con = new MySqlConnection("server=localhost;database=student;uid=root");
            MySqlCommand cmd = new MySqlCommand("UPDATE student SET name='" + TextBox2.Text + "',gender='" + TextBox3.Text + "',degree='" + TextBox4.Text + "',deptno='" + TextBox5.Text + "',totcredit='" + TextBox6.Text + "' WHERE rollno='" + TextBox1.Text + "'");
            cmd.Connection = con;
            con.Open();
            int result = cmd.ExecuteNonQuery();

            if (result > 0)
                Label7.Text = "Update Success!";
            else
                Label7.Text = "Update Failed!";
            TextBox1.Text = "";
            TextBox2.Text = "";
            TextBox3.Text = "";
            TextBox4.Text = "";
            TextBox5.Text = "";
            TextBox6.Text = "";
            con.Close();
            MySqlConnection con1 = new MySqlConnection("server=localhost;database=student;uid=root");
            MySqlCommand cmd1 = new MySqlCommand("SELECT ROLLNO,NAME,GENDER,DEGREE,DEPTNO,TOTCREDIT FROM student");
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

        }

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        MySqlConnection con = new MySqlConnection("server=localhost;database=STUDENT;uid=root");

        MySqlCommand cmd = new MySqlCommand("INSERT INTO student VALUES ('" + TextBox1.Text + "','" + TextBox2.Text + "','" + TextBox3.Text + "','" + TextBox4.Text + "','" + TextBox5.Text + "','" + TextBox6.Text + "')");
        Label7.Text = "";
        cmd.Connection = con;
        try
        {
            con.Open();
            int result = cmd.ExecuteNonQuery();

            if (result > 0)
                Label7.Text = "Insert Success!";
            else
                Label7.Text = "Insert Failed!";
            TextBox1.Text = "";
            TextBox2.Text = "";
            TextBox3.Text = "";
            TextBox4.Text = "";
            TextBox5.Text = "";
            TextBox6.Text = "";
            con.Close();
            MySqlConnection con1 = new MySqlConnection("server=localhost;database=student;uid=root");
            MySqlCommand cmd1 = new MySqlCommand("SELECT ROLLNO,NAME,GENDER,DEGREE,DEPTNO,TOTCREDIT FROM student");
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
            
        }
        finally
        {
            con.Close();
        }

    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        MySqlConnection con = new MySqlConnection("server=localhost;database=student;uid=root");
        MySqlCommand cmd = new MySqlCommand("Delete from student WHERE rollno='"+TextBox1.Text+"'");
        cmd.Connection = con;
        try
        {
            Label7.Text = "";
            con.Open();
            int result = cmd.ExecuteNonQuery();

            if (result > 0)
                Label7.Text = "Delete Success!";
            else
                Label7.Text = "Delete Failed!";
            TextBox1.Text = "";
            TextBox2.Text = "";
            TextBox3.Text = "";
            TextBox4.Text = "";
            TextBox5.Text = "";
            TextBox6.Text = "";
            con.Close();
            MySqlConnection con1 = new MySqlConnection("server=localhost;database=student;uid=root");
            MySqlCommand cmd1 = new MySqlCommand("SELECT ROLLNO,NAME,GENDER,DEGREE,DEPTNO,TOTCREDIT FROM student");
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

        }
        finally
        {
            con.Close();
        }

    }
    protected void Button4_Click(object sender, EventArgs e)
    {
        MySqlConnection con = new MySqlConnection("server=localhost;database=student;uid=root");
        MySqlCommand cmd = new MySqlCommand("SELECT ROLLNO,NAME,GENDER,DEGREE,DEPTNO,TOTCREDIT FROM student");
        cmd.Connection = con;
        try
        {
            TextBox1.Text = "";
            TextBox2.Text = "";
            TextBox3.Text = "";
            TextBox4.Text = "";
            TextBox5.Text = "";
            TextBox6.Text = "";
            con.Open();
            MySqlDataReader dr = cmd.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            GridView1.DataSource = dt;
            GridView1.DataBind();

        }
        catch (MySqlException ex)
        {
            //MessageBox.Show(ex.Message);
        }
        finally
        {
            con.Close();
        }


    }
}
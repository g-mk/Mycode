﻿<%@ Page Language="C#" AutoEventWireup="true" CodeFile="MyForm.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:Button ID="Button1" runat="server" Text="Insert" style="position: absolute; top: 383px; left: 281px; height: 26px; right: 639px;" OnClick="Button1_Click" />
        <asp:Button ID="Button2" runat="server" Text="Delete" style="position: absolute; top: 383px; left: 361px;" OnClick="Button2_Click" />
        <asp:Button ID="Button3" runat="server" Text="Update" style="position: absolute; top: 383px; left: 445px;" OnClick="Button3_Click" />    
        <asp:Button ID="Button4" runat="server" Text="Select" style="position: absolute; top: 383px; left: 533px;" OnClick="Button4_Click" />    

    </div>
            <asp:Label ID="Label1" runat="server" style="z-index: 1; left: 278px; top: 146px; position: absolute; width: 53px;" Text="Id     :"></asp:Label>
            <asp:Label ID="Label2" runat="server" style="z-index: 1; left: 260px; top: 183px; position: absolute" Text="Name:"></asp:Label>
            <asp:Label ID="Label3" runat="server" style="z-index: 1; left: 254px; top: 220px; position: absolute; margin-bottom: 0px;" Text="Gender:"></asp:Label>
            <asp:Label ID="Label4" runat="server" style="z-index: 1; left: 256px; top: 258px; position: absolute" Text="Mobile:"></asp:Label>
            <asp:Label ID="Label5" runat="server" style="z-index: 1; left: 259px; top: 296px; position: absolute" Text="Salary:"></asp:Label>
            <asp:TextBox ID="TextBox1" runat="server" style="position: absolute; top: 145px; left: 356px;"></asp:TextBox>
            <asp:Label ID="Label6" runat="server" Text="Label" style="position:absolute; top: 340px; left: 387px;" Visible="False"></asp:Label>
            <asp:TextBox ID="TextBox2" runat="server" style="position: absolute; top: 183px; left: 354px;" ></asp:TextBox>
            <asp:TextBox ID="TextBox3" runat="server" style="position: absolute; top: 252px; left: 353px;"></asp:TextBox>
            <asp:TextBox ID="TextBox4" runat="server" style="position: absolute; top: 291px; left: 353px;"></asp:TextBox>
            <asp:RadioButton ID="Male" runat="server" Text="Male" style="position: absolute; top: 220px; left: 361px; right: 546px;" GroupName="Gender" />
            <asp:RadioButton ID="Female" runat="server" Text ="Female" style="position: absolute; top: 221px; left: 444px;" GroupName="Gender" />
        <asp:GridView ID="GridView1" runat="server" style="position: absolute; top: 145px; left: 619px;">
        </asp:GridView>
    </form>
</body>
</html>


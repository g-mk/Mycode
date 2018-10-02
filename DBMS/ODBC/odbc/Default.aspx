<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:Label ID="Label1" runat="server" style="z-index: 1; left: 131px; top: 150px; position: absolute" Text="Student Id"></asp:Label>
        <asp:Label ID="Label2" runat="server" style="z-index: 1; left: 131px; top: 200px; position: absolute" Text="Student Name"></asp:Label>
        <asp:Label ID="Label3" runat="server" style="z-index: 1; left: 131px; top: 250px; position: absolute" Text="Gender"></asp:Label>
        <asp:Label ID="Label4" runat="server" style="z-index: 1; left: 131px; top: 300px; position: absolute" Text="Degree"></asp:Label>
        <asp:Label ID="Label5" runat="server" style="z-index: 1; left: 131px; top: 350px; position: absolute" Text="Department No"></asp:Label>
        <asp:Label ID="Label6" runat="server" style="z-index: 1; left: 131px; top: 400px; position: absolute" Text="Total Credit"></asp:Label>
         <asp:TextBox ID="TextBox1" runat="server" style="z-index: 1; left: 270px; top: 150px; position: absolute"></asp:TextBox>
        <asp:TextBox ID="TextBox2" runat="server" style="z-index: 1; left: 270px; top: 200px; position: absolute"></asp:TextBox>
        <asp:TextBox ID="TextBox3" runat="server" style="z-index: 1; left: 270px; top: 250px; position: absolute"></asp:TextBox>
        <asp:TextBox ID="TextBox4" runat="server" style="z-index: 1; left: 270px; top: 300px; position: absolute"></asp:TextBox>
        <asp:TextBox ID="TextBox5" runat="server" style="z-index: 1; left: 270px; top: 350px; position: absolute"></asp:TextBox>
        <asp:TextBox ID="TextBox6" runat="server" style="z-index: 1; left: 270px; top: 400px; position: absolute"></asp:TextBox>
        <asp:Button ID="Button2" runat="server"  style="z-index: 1; left: 363px; top: 449px; position: absolute; right: 339px" Text="Update" OnClick="Button2_Click" />
        <asp:Button ID="Button1" runat="server"  style="z-index: 1; left: 275px; top: 449px; position: absolute; right: 453px" Text="Insert" OnClick="Button1_Click" />
        <asp:Button ID="Button3" runat="server"  style="z-index: 1; left: 451px; top: 449px; position: absolute; right: 567px" Text="Delete" OnClick="Button3_Click" />
        <asp:Button ID="Button4" runat="server"  style="z-index: 1; left: 539px; top: 449px; position: absolute; right: 567px" Text="Select" OnClick="Button4_Click" />
        <asp:GridView ID="GridView1" runat="server" style="z-index: 1; left: 436px; top: 145px; position: absolute; height: 276px; width: 320px; margin-top: 0px;" BorderStyle="Groove">
        </asp:GridView>    
    </div>
        <p>
            &nbsp;</p>
        <asp:Label ID="Label7" runat="server" style="z-index: 1; left: 133px; top: 452px; position: absolute"></asp:Label>
    </form>
</body>
</html>

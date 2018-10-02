<?xml version="1.0" encoding="UTF-8"?>
<!--
    Document   : VoterXSLT.xsl
    Created on : 1 April, 2017, 6:01 PM
    Author     : Guru Manikandan
    Description:
        Purpose of transformation follows.
-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="html"/>
    <xsl:template match="/">
        <html>
            <head>
                <title>Voter List</title>
                <style type="text/css">
                    tr:hover {
                        background-color: powderblue;
                        color: black;
                        font-style:bold;
                        transition: .5s;
                    }
                </style>
            </head>
            <body>
                <h2 align="center">Senior Citiens</h2>
                <table align="center" border="1" cellspacing="6px" cellpadding="6px">
                    <header>
                        <th>Name</th>
                        <th>Age</th>
                        <th>Mobile</th>
                        <th>E-Mail</th>
                    </header>
                    <xsl:for-each select = "voters/voter">
                        <xsl:if test="age >= 20">
                            <tr>
                                <td>
                                    <xsl:value-of select ="fname"/>
                                    <xsl:value-of select ="mname"/>
                                    <xsl:value-of select ="lname"/>
                                </td>
                                <td>
                                    <xsl:value-of select ="age"/>
                                </td>
                                <td>
                                    <xsl:value-of select ="mobile"/>
                                </td>
                                <td>
                                    <xsl:value-of select ="email"/>
                                </td>
                            </tr>
                        </xsl:if>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>

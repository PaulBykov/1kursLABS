<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
  <head><title>Задание 2</title></head>
  <body>
    <center>
      <h3>Аттестация</h3> 
      <table border="3">
        <tr>
          <td align="center">Имя</td>
          <td align="center">Отметка</td>
        </tr>
        <xsl:for-each select="info/att">
          <tr>
            <td><xsl:value-of select="student"/></td>
          <xsl:choose>
            <xsl:when test="note &gt; 8">
            <td bgcolor="green"><xsl:value-of select="note"/></td>
            </xsl:when>
            <xsl:when test="note &lt; 4">
            <td bgcolor="red"><xsl:value-of select="note"/></td>
            </xsl:when>
            <xsl:otherwise>
            <td><xsl:value-of select="note"/></td>
            </xsl:otherwise>
          </xsl:choose>
          </tr>
        </xsl:for-each>
      </table>
    </center>
  </body>
</html>
</xsl:template>
</xsl:stylesheet>
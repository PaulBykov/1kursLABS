<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
  <head>
  <title>Задание 1</title>
  </head>
  <body>
    <center>
      <table>
        <tr bgcolor="aqua">
          <td align="center">Исполнитель</td>
          <td align="center">Песня</td>
          <td align="center">Год выхода</td>
        </tr>
      <xsl:for-each select="music/info">
      <xsl:sort select="artist" order="descending"/>
        <tr>
          <td border="3" bgcolor="green"><xsl:value-of select="artist"/></td>
          <td border="3" bgcolor="green"><xsl:value-of select="song"/></td>
          <td border="3" bgcolor="green"><xsl:value-of select="year"/></td>
        </tr>
      </xsl:for-each>
      </table>
    </center>
  </body>
</html>
</xsl:template>
</xsl:stylesheet>

<?xml version="1.0" encoding="iso-8859-9"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
   
 <html>
      <body>
        <h2>My CD Collection</h2>
        <table border="1">
          <tr bgcolor="#9acd32">
            <th>Title</th>
            <th>Artist</th>
          </tr>
          <tr>
            <td>
              <xsl:value-of select="shiporder/shipto"/>
            </td>
            <td>
              <xsl:value-of select="shiporder/item/note"/>
            </td>
          </tr>
          <xsl:for-each select="shiporder/item">
            <tr>
              <td>
                <xsl:value-of select="price"/>
              </td>
              <td>
                <xsl:value-of select="quantity"/>
              </td>
            </tr>
          </xsl:for-each>

          <xsl:for-each select="shiporder/item">
            <xsl:if test="price &gt; 10">
              <tr>
                <td>
                  <xsl:value-of select="title"/>
                </td>
                <td>
                  <xsl:value-of select="artist"/>
                </td>
              </tr>
            </xsl:if>
            </xsl:for-each>
        </table>
        <xsl:for-each select="catalog/cd">
          <xsl:if test="price &gt; 10">
            <tr>
              <td>
                <xsl:value-of select="title"/>
              </td>
              <td>
                <xsl:value-of select="note"/>
              </td>
            </tr>
          </xsl:if>
        </xsl:for-each>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>

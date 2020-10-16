<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/">
	<html>
	<body bgcolor="cyan">
	
	<h1> First name</h1>
	
	
	<xsl:for-each select="empList/emp">
	<xsl:if test="salary>30000">
	<b> <xsl:value-of select="fname"/> </b>
	<br/>
	</xsl:if>
	</xsl:for-each>
	
	<xsl:for-each select="empList/emp">
	
	<xsl:if test="salary &lt; 40000">
	 <font color='green'> <b>  <xsl:value-of select="fname"/> </b> 
	</font>
	<br/>
	
	</xsl:if>
	
	
	</xsl:for-each>
	
	<br/> <h3> Last name</h3>
		<xsl:for-each select="empList/emp">
		
	<xsl:choose>
	
	<xsl:when test="salary>40000">
	
	<b> <xsl:value-of select="lname"/> </b>
	
	<br/>
	
	</xsl:when>
	
	<xsl:otherwise>
	
	<font color='green'> <b>  
	<xsl:value-of select="lname"/> </b> 
	</font>
	<br/>
		</xsl:otherwise>
	</xsl:choose>
	</xsl:for-each>
	
	
	<br/> <h3> SALARY SORT</h3>
	
	<table border="5">
	
	<xsl:for-each select="empList/emp">
		<xsl:sort select="salary" order="ascending"/>
		<tr>
		<td> <font color='red'>
		<xsl:value-of select="fname" />
		</font>		
		</td>
		
		<td><xsl:value-of select="salary" /></td>
		</tr>
		
		</xsl:for-each>
		
	
	</table>
	
	
	</body>
	
	
	
	</html>
	
	
		<!-- TODO: Auto-generated template -->
	</xsl:template>
</xsl:stylesheet>
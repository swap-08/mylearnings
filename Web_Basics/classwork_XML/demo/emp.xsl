<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/">
		<!-- TODO: Auto-generated template -->
		<html>
			<body bgcolor="red">
			<table border='5'>
			<xsl:for-each select="emplist/emp">
			<xsl:sort select="salary" order="descending"/>
				<xsl:if test="salary>50">
					<td><h1>First name</h1></td>
			   		<td><b><xsl:value-of select="firstname"/></b></td>
			   		<br/>
			   	</xsl:if>
			</xsl:for-each>		
			</table>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>
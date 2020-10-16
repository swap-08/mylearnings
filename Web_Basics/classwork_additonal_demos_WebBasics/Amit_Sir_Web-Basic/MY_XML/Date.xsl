<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/">
		<html>
			<head>
				<title>Display Date</title>
			</head>
			<body bgcolor="#FFFFFF">
				<xsl:for-each select="BDate/date">
					<xsl:if test="day &gt; 20">
						<xsl:apply-templates select="day"/> /
						<xsl:apply-templates select="month"/> / 
						<xsl:apply-templates select="year"/> 
						<br/>
					</xsl:if>
				</xsl:for-each>				
			</body>
		</html>
	</xsl:template>
	
		<xsl:template match="day">
			day: <span style="color:#00ff00">
			<xsl:value-of select="."/></span>		
		</xsl:template>	
		
		<xsl:template match="month">
			month: <span style="color:#00ff00">
			<xsl:value-of select="."/></span>			 
		</xsl:template>	
		
		<xsl:template match="year">
			year: <span style="color:#00ff00">
			<xsl:value-of select="."/></span>			
	</xsl:template>
	
</xsl:stylesheet>
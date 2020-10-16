<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/TR/WD-xsl">
	<xsl:template match="/">
		<html><head><title>Address Book XML Example</title></head>
			<body bgcolor="#FFFFFF">
				<xsl:for-each select="addressbook/contact">
					<xsl:apply-templates select="name"/>
					<xsl:apply-templates select="address"/>
					<xsl:apply-templates select="city"/>
					<xsl:apply-templates select="state"/>
					<xsl:apply-templates select="zip"/>
				</xsl:for-each>
			</body>
		</html>
	</xsl:template>
	<xsl:template match="name">
		<h2><xsl:value-of/></h2>
	</xsl:template>
	<xsl:template match="address">
		<xsl:value-of/><br/>
	</xsl:template>
	<xsl:template match="city">
		<xsl:value-of/>,
	</xsl:template>
	<xsl:template match="state">
		<xsl:value-of/> 
            </xsl:template>
	<xsl:template match="zip">
		<xsl:value-of/><br/>
	</xsl:template>
       </xsl:stylesheet>


<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/">
	<html>
		<!-- TODO: Auto-generated template -->
		<xsl:for-each select="movies/movie">
		
		<br/>
		<xsl:value-of select="."/>
		</xsl:for-each>
		
	</html>
	</xsl:template>
</xsl:stylesheet>
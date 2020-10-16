<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="/">
		<html>
	<body bgcolor="cyan">
	
	<h1> Actors </h1>
		
		<table border="5">
			<xsl:for-each select="movies/movie/actor">
			
				<xsl:sort select="." order="ascending"/> 
						
			<tr>	
			<td> 	
			<xsl:value-of select="."/>	
			</td>
			
		</tr>
		
	 	</xsl:for-each> 
				
 		</table>
	</body>	
	</html>
	</xsl:template>
</xsl:stylesheet>
<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">	
<xsl:template match="solar">
<html>
<head>
<title>Лабораторная 3.3 (1)</title>
</head>
<body>
<table cellspacing="2" cellpadding="5" border="1">
<caption><h1>Планеты</h1></caption>
	<tr bgcolor="#CCCCCC">
		<th>#</th>
		<th>Название</th>
		<th>Расстояние от солнца (a.e)</th>
		<th>Период обращения (г.)</th>
		<th>Период вращения вокруг своей оси (ч.)</th>
		<th >Масса относительно Земли</th>
		<th>Диаметр (км.)</th>
		<th>Количество спутников</th>
	</tr>
<xsl:for-each select="planet">
<xsl:sort order="ascending" select="number(distance)" data-type="number"/>
<xsl:sort order="ascending" select="@caption"/>
<tr align="center">
<xsl:if test="number(diametr) div 2 &lt; 10000">
	<xsl:attribute name="bgcolor">#99FF99</xsl:attribute>
</xsl:if>
<xsl:if test="number(diametr) div 2 &gt; 10000">
	<xsl:attribute name="bgcolor">#66CCFF</xsl:attribute>
</xsl:if>
	<xsl:if test="number(diametr) div 2 &gt; 30000">
		<xsl:attribute name="bgcolor">#FFCCCC</xsl:attribute>
	</xsl:if>
	<th bgcolor="#CCCCCC"><xsl:value-of select="position()"/></th>
	<td><xsl:value-of select="@caption"/></td>
	<td><xsl:value-of select="distance"/></td>
	<td><xsl:value-of select="circulation_period"/></td>
	<td><xsl:value-of select="revolution_period"/></td>
	<td bgcolor="yellow"><xsl:value-of select="weight"/></td>
	<td><xsl:value-of select="diametr"/></td>
	<td><xsl:value-of select="satellite_number"/></td>
	</tr>
	</xsl:for-each>    
</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>
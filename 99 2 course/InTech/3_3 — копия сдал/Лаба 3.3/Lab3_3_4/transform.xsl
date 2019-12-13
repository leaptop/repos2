<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">	
<xsl:template match="solar">
<html>
<head>
<title>Лабораторная 3.3 (4)</title>
</head>
<body>
				<table cellspacing="2" cellpadding="5" border="1">
					<caption><h1>Планеты</h1></caption>
					<tr bgcolor="#CCCCCC">
						<th bgcolor="#FFF">Свойства</th>
						<xsl:for-each select="planet">
							<th><xsl:value-of select="@caption"/></th>
						</xsl:for-each> 
					</tr>

					<tr align="center">
						<td>Расстояние от солнца (a.e)</td>
						<xsl:for-each select="planet">
							<td><xsl:value-of select="distance"/></td>
						</xsl:for-each> 
					</tr>

					<tr align="center">
						<td>Период обращения (г.)</td>
						<xsl:for-each select="planet">
							<td><xsl:value-of select="circulation_period"/></td>
						</xsl:for-each> 
					</tr>

					<tr align="center">
						<td>Период вращения вокруг своей оси (ч.)</td>
						<xsl:for-each select="planet">
							<td><xsl:value-of select="revolution_period"/></td>
						</xsl:for-each> 
					</tr>

					<tr align="center">
						<td>Масса относительно Земли</td>
						<xsl:for-each select="planet">
							<td><xsl:value-of select="weight"/></td>
						</xsl:for-each> 
					</tr>

					<tr align="center">
						<td>Диаметр (км.)</td>
						<xsl:for-each select="planet">
							<td><xsl:value-of select="diametr"/></td>
						</xsl:for-each> 
					</tr>

					<tr align="center">
						<td>Количество спутников</td>
						<xsl:for-each select="planet">
							<td><xsl:value-of select="satellite_number"/></td>
						</xsl:for-each> 
					</tr>

				</table>
			</body>
	 	</html>
	</xsl:template>
</xsl:stylesheet>
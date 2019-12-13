<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">	
	<xsl:template match="solar">
		<html>
			<head>
				<title>Лабораторная #3.3 (3)</title>
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
						<th>Масса относительно Земли</th>
						<th>Диаметр (км.)</th>
						<th>Количество спутников</th>
					</tr>
					<xsl:for-each select="planet">
						<xsl:sort order="ascending" select="number(satellite_number)" data-type="number"/>
						<xsl:if test="number(satellite_number) >= 1">
							<tr align="center">
								<xsl:if test="position() mod 2 = 0">
									<xsl:attribute name="bgcolor">#CCCCCC</xsl:attribute>
								</xsl:if>
								<th bgcolor="#CCCCCC"><xsl:value-of select="position()"/></th>
								<td><xsl:value-of select="@caption"/></td>
								<td><xsl:value-of select="distance"/></td>
								<td><xsl:value-of select="circulation_period"/></td>
								<td><xsl:value-of select="revolution_period"/></td>
								<td><xsl:value-of select="weight"/></td>
								<td><xsl:value-of select="diametr"/></td>
								<td><xsl:value-of select="satellite_number"/></td>
							</tr>
						</xsl:if>
					</xsl:for-each>    
				</table>

				<dl>
					<xsl:for-each select="planet">
						<xsl:sort order="ascending" select="number(satellite_number)" data-type="number"/>
						<xsl:if test="number(satellite_number) = 0">
							<dt><xsl:value-of select="@caption"/></dt>
	    						<dd>Расстояние от солнца (a.e): <xsl:value-of select="distance"/></dd>
								<dd>Период обращения (г.): <xsl:value-of select="circulation_period"/></dd>
								<dd>Период вращения вокруг своей оси (ч.): <xsl:value-of select="revolution_period"/></dd>
								<dd>Масса относительно Земли: <xsl:value-of select="weight"/></dd>
								<dd>Диаметр (км.): <xsl:value-of select="diametr"/></dd>
								<dd>Количество спутников: <xsl:value-of select="satellite_number"/></dd>
	    				</xsl:if>
	    			</xsl:for-each>
    			</dl>
			</body>
	 	</html>
	</xsl:template>
</xsl:stylesheet>
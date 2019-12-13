<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="/">
		<table cellpadding="2" border="1" align="center" width="60%">
			<tr align="center">
				<td><b>№</b></td>
				<td><b>Название</b></td>
				<td><b>Расстояние от Солнца (а. е.)</b></td>
				<td><b>Период обращения (г)</b></td>
				<td><b>Период вращения вокруг своей оси (ч)</b></td>
				<td><b>Масса относительно Земли</b></td>
				<td><b>Диаметр (км)</b></td>
				<td><b>Количество спутников</b></td>
			</tr>
			<xsl:for-each select="solar/planet">
			<xsl:sort select="revolution_period" data-type="number"/>
				<tr align="center">
					<xsl:choose>
						<xsl:when test="diameter > 10000">
							<xsl:attribute name="bgcolor">#F0F000</xsl:attribute>
						</xsl:when>
						<xsl:otherwise>
							<xsl:attribute name="bgcolor">#A0EEFF</xsl:attribute>
						</xsl:otherwise>
					</xsl:choose>
					<td><xsl:value-of select="position()"/></td>
					<td><b><xsl:value-of select="@caption"/></b></td>
					<td><xsl:value-of select="distance"/></td>
					<td><xsl:value-of select="circulation_period"/></td>
					<td><xsl:value-of select="revolution_period"/></td>
					<td><xsl:value-of select="weight"/></td>
					<td><xsl:value-of select="diameter"/></td>
					<td><xsl:value-of select="satellite_number"/></td>
				</tr>
			</xsl:for-each>
		</table>
	</xsl:template>
</xsl:stylesheet>
package trig_interpolation.tests;

import com.panayotis.gnuplot.JavaPlot;

public class TrigTest {
	public static void main(String[] args) {
		JavaPlot p = new JavaPlot();
		p.addPlot("sin(x)");
		p.plot();
	}
}

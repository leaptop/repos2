package trig;

import com.panayotis.gnuplot.*;
import com.panayotis.gnuplot.JavaPlot;
import com.panayotis.gnuplot.plot.DataSetPlot;
import com.panayotis.gnuplot.style.PlotStyle;
import com.panayotis.gnuplot.style.Style;

/**
 * author: bartosz
 * date: 20.01.16
 */
public class Trig {
    private Points points;
    private int pointsNumber;
    private int degree;
    private double[] a;
    private double[] b;
    private Points valuesPoints;

    public Trig(String pointsPath) {
        points = new Points(pointsPath);
        pointsNumber = points.getPointsNumber();
        setPolynomialDegree();
        calculateFactors();
    }

    public void printFactors() {
        for(int i = 0; i < a.length; i++) {
            System.out.println("a[" + i + "]=" + a[i] + ", b[" + i + "]=" + b[i]);
        }
    }

    public void calculateValuesPoints(int valuesNumber) {
        if(points == null) return ;
        valuesPoints = new Points(valuesNumber);
        double begin = points.getPoints()[0].getX();
        double end = points.getPoints()[points.getPointsNumber()-1].getX();


        double x = 0;
        double y = 0;
        double jump = (end - begin) / (valuesNumber - 1);
        for(int i = 0; i < valuesNumber; i++) {
            x = begin + i * jump;
            y = calculateValue(x);
            valuesPoints.setPoint(i, new Point(x, y));
            // System.out.println("x=" + x + ", y=" + y);
        }
    }

    public void calculateFactors() {
        a = new double[degree+1];
        b = new double[degree+1];

        double cosinusSum = 0;
        double sinusSum = 0;

        double x = 0;
        double y = 0;

        for(int j = 0; j <= degree; j++) {
            for(int k = 0; k < pointsNumber; k++) {
                y = points.getPoints()[k].getY();
                x = points.getPoints()[k].getX();
                cosinusSum += y * Math.cos(j * x);
                sinusSum += y * Math.sin(j * x);
            }
            a[j] = 2.0 / pointsNumber * cosinusSum;
            b[j] = 2.0 / pointsNumber * sinusSum;

            cosinusSum = 0;
            sinusSum = 0;
        }
    }

    private void setPolynomialDegree() {// что-то вроде проверки на четность
        if(pointsNumber == 0) {
            degree = 0;
        } else {
            if(pointsNumber % 2 == 0) {
                degree = pointsNumber / 2;
            } else {
                degree = (pointsNumber - 1) / 2;
            }
        }
    }

    public double calculateValue(double x) {
        double value = 0;
        double sum = 0;

        if(degree % 2 == 0) {
            value = a[0] / 2;

            for(int k = 1; k < degree; k++) {
                sum += a[k] * Math.cos(k * x) + b[k] * Math.sin(k * x);
            }

            value += a[degree] / 2 * Math.cos(degree * x);
        } else {
            value = a[0] / 2;

            for(int k = 1; k <= degree; k++) {
                sum += a[k] * Math.cos(k * x) + b[k] * Math.sin(k * x);
            }
        }

        return value + sum;
    }
public void visualize(){

}
    public void visualize0() {
        JavaPlot p = new JavaPlot();
        p.setTitle("Trigonometric interpolation");

        // measurement points
        DataSetPlot pointsSet = null;
        if(points != null)
            pointsSet = new DataSetPlot(points.getPointsInArray());
        if(pointsSet != null)
            pointsSet.setTitle("Measurement points");

        // interpolation function
        DataSetPlot interpolationSet = null;
        if(valuesPoints != null)
            interpolationSet = new DataSetPlot(valuesPoints.getPointsInArray());
        if(interpolationSet != null)
            interpolationSet.setTitle("Interpolation");

        // plotting measurement points
        PlotStyle style = new PlotStyle(Style.POINTS);
        style.setPointType(7);
        style.setPointSize(2);
        if(pointsSet != null) pointsSet.setPlotStyle(style);
        p.addPlot(pointsSet);

        // plotting interpolation function points
        style = new PlotStyle(Style.POINTS);
        style.setPointType(5);
        style.setPointSize(1);
        if(interpolationSet != null) interpolationSet.setPlotStyle(style);
        p.addPlot(interpolationSet);

        p.plot();
    }
}

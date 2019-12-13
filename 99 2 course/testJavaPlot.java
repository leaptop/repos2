import com.panayotis.gnuplot.JavaPlot;

 

public class testJavaPlot {

    public static void main(String[] args) {

        JavaPlot p = new JavaPlot();

        p.addPlot("sin(x)");

        p.plot();

    }

}
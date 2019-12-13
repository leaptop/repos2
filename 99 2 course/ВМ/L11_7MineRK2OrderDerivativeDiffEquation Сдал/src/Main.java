import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

import java.text.DecimalFormat;

//какие значения надо сравнивать? Если, например, правая граница(xn = 1),
// то это значение (y(1)) и надо сравнивать для разных h?
//Math.pow(x, 4)/12 + C - это интеграл взятый два раза от x^2
//Какую часть массива сравнивать? Ведь получатся наборы, отличающиеся в два раза по количеству(при H и при h)
//y(x0)=y0, y'(x0)=y0' должны быть даны для решения.
public class Main extends Application {
    //решение системы дифференциальных уравнений методом Рунге-Кутты(Runge-Kutta-Nystrom)
    //(точнее решение диффура второго порядка, приведнием его к системе из диффуров первого порядка)
    //как здесь применить интегрирование для представления g через z?
    //смогу ли я применить здесь интегрирование из 10-й лабы? Там то определённый интеграл...
    // ответы - это игреки?
    public double fDer(double x, double y) {
        return x + y;
    }
    // int range = (int) ((xn - x0) / h);
    //  double yy[] = new double[range + 1];
    // double xx[] = new double[range];

    int k = 2, numD = 11;
    double x0, xn, y0, y1, z0, z1, h, H, xx[], yy[], YY[], eps = 10E-10;
    double k1, k2, k4, k3;
    double k11, k22, k44, k33;

    double x0F = 0, y0F = 1, z0F = 1, xnF = 1, hF = 0.1;

    public void start(Stage stage) {
        System.out.println("X\t\t\t\tY\t\t\t\tY'");
        x0 = x0F;//зн-ие аргумента
        xn = xnF;
        y0 = y0F;//зн-ие ф-ции в точке x0
        z0 = z0F;
        h = hF; // шаг
        H = 2 * h;

        int i = 0;
        int range = (int) ((xn - x0) / H);
        int RANGE = (int) ((xn - x0) / h);
        xx = new double[RANGE];
        yy = new double[RANGE];
        System.out.println("RK4 launch with h = " + h);
        RK4(h, RANGE, yy);
        x0 = x0F;//зн-ие аргумента
        xn = xnF;
        y0 = y0F;//зн-ие ф-ции в точке x0
        z0 = z0F;
        xx = new double[range];
        YY = new double[range];
        System.out.println("RK4 launch with H = " + H);
        RK4(H, range, YY);
        System.out.println("i = " + i + " h = " + h);

        while (Math.abs(yy[RANGE - 1] - YY[range - 1]) > eps) {
            System.out.println("\nInside of while");
            System.out.println("i = " + ++i);
            h *= 0.5;
            H = 2 * h;

            y0 = y0F;
            z0 = z0F;
            RANGE = (int) ((xn - x0) / h);
            range = (int) ((xn - x0) / H);

            xx = new double[range];
            YY = new double[range];
            System.out.println("RK4 launch with H = " + H);
            RK4(H, range, YY);


            xx = new double[RANGE];
            yy = new double[RANGE];
            y0 = y0F;
            z0 = z0F;
            System.out.println("RK4 launch with h = " + h);
            RK4(h, RANGE, yy);

            for (int j = 0; j < range; j++) {

            }
        }
    }
    public static void main(String[] args) {
        launch(args);
    }

    public double f(double x, double y, double z) {
        double result = (Math.exp(x)+y)/2;
        return result;  //return Math.pow(x, 4) / 7;
    }

    //функция, являющаяся y' ... может быть если сюда таки подставить реальную производную, то график нарисуется...
    //(как я и представлял, т.е. если y'' = x^4/12, то нарисуется парабола...)
    //вообще в примере на википедии сюда тупо задаётся известное численное значение первой производной
    public double g(double x, double y, double z) {
        return (z);
    }

    public void RK4(double h, int range, double[] yy) {
        double yc = y0;
        double xc = x0;
        //for (double xc = x0; xc < xn; xc += h) {
        // проблема в том, что точки должны и увеличиться на h  и пройти от 0 до 1 за 10 шагов...
        //это не надо скорее всего(10 шагов увеличатся и это окей)
        // какую переменную увеличивать на 0.1?
        for (int i = 0; i < range; i++) {
            // xx[i] = xc;
            k1 = h * f(xc, yc, z0);
            k11 = h * g(xc, yc, z0);

            k2 = h * f(xc + h / 2.0, yc + k11 / 2.0, z0 + k1 / 2.0);
            k22 = h * g(xc + h / 2.0, yc + k11 / 2.0, z0 + k1 / 2.0);

            k3 = h * f(xc + h / 2.0, yc + k22 / 2.0, z0 + k2 / 2.0);
            k33 = h * g(xc + h / 2.0, yc + k22 / 2.0, z0 + k2 / 2.0);

            k4 = h * f(xc + h, yc + k33, z0 + k3);
            k44 = h * g(xc + h, yc + k33, z0 + k3);

            z1 = z0 + (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;//первые коэффициенты (k1, k2, k3, k4) - это именно для
            //подсчета значения первой производной
            yy[i] = y1 = yc + (k11 + 2.0 * k22 + 2.0 * k33 + k44) / 6.0;
            //System.out.println("\t" + r(x0 + h, k) + "\t\t" + r(y1 ,k) + "\t\t" + r(z1 ,k));


            yc = y1;
            xc += h;
            z0 = z1;
            //yy[i] = yc;
        }
        String x00 = new DecimalFormat("#0.0000000000000").format(xc);
        String y11 = new DecimalFormat("#0.0000000000000").format(y1);
        String z11 = new DecimalFormat("#0.0000000000000").format(z1);

        System.out.println(x00 + "\t" + y11 + "\t" + z1);
    }
    public double f1(double x, double y, double z) {
        return (Math.cos(3 * x) - 4 * y);
    }
    public double f2(double x, double y, double z) {
        double result = x * x * x * x / 7;
        return result;  //return Math.pow(x, 4) / 7;
    }
}

/* public void Euhler6() {
        yy[0] = y0;
        xx[0] = x0;
        double yc = y0, xc = x0;
        //for (double xc = x0; i<range; xc += h) {
        for (int i = 0; i < range; i++) {
            if (i > 0) xc = xx[i] = xx[i - 1] + h;
            y0 =  yy[i]  = y0 + h * f(xc, yc, z0);
            System.out.println("xx[" + i + "] = " + xx[i]);
            System.out.println("yy[" + i + "] = " + yy[i]);
        }
    }*/
    /*public void Euhler() {
        double yc = y0;
        for (double xc = x0; xc < xn; xc += h) {
            y1 = y0 + h * f(xc, yc, z0);
        }
    }*/
   /* public void Euhler2(double h, int range, double[] yy){
        double yc = y0;
        double xc = x0;
        for (int i = 0; i < range; i++) {
            k1 = h * f(xc, yc, z0);
            k11 = h * g(xc, yc, z0);

            k2 = h * f(xc + h / 2.0, yc + k11 / 2.0, z0 + k1 / 2.0);
            k22 = h * g(xc + h / 2.0, yc + k11 / 2.0, z0 + k1 / 2.0);

            k3 = h * f(xc + h / 2.0, yc + k22 / 2.0, z0 + k2 / 2.0);
            k33 = h * g(xc + h / 2.0, yc + k22 / 2.0, z0 + k2 / 2.0);

            k4 = h * f(xc + h, yc + k33, z0 + k3);
            k44 = h * g(xc + h, yc + k33, z0 + k3);

            z1 = z0 + (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
            yy[i] = y1 = yc + (k11 + 2.0 * k22 + 2.0 * k33 + k44) / 6.0;
            //System.out.println("\t" + r(x0 + h, k) + "\t\t" + r(y1 ,k) + "\t\t" + r(z1 ,k));

            String x00 = new DecimalFormat("#0.0000000000000").format(xc);
            String y11 = new DecimalFormat("#0.0000000000000").format(y1);
            String z11 = new DecimalFormat("#0.0000000").format(z1);

            System.out.println(x00 + "\t" + y11 + "\t");
            yc = y1;
            xc += h;
            z0 = z1;
        }

    }*/

    /*stage.setTitle("Сравнение методов Рунге-Кутты и Эйлера");
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        yAxis.setLabel("Y");
        final LineChart<Number, Number> lineChart = new LineChart<Number, Number>(xAxis, yAxis);
        lineChart.setCreateSymbols(false);//убирает кружочки из узлов

        XYChart.Series seriesb = new XYChart.Series();
        // for (int i = 0; i < numD; i++) {            seriesb.getData().add(new XYChart.Data(0, 0));        }
        seriesb.setName("Runge-Kutta4");

        XYChart.Series seriesRK4 = new XYChart.Series();
        // for (int i = 0; i < numD; i++) {            seriesRK4.getData().add(new XYChart.Data(xx[i], yy[i]));        }
        seriesRK4.setName("Runge-Kutta4");

        lineChart.setAnimated(false);
        lineChart.setCreateSymbols(true);

        lineChart.getData().addAll(seriesb, seriesRK4);
        Scene scene = new Scene(lineChart, 800, 600);
        scene.getStylesheets().add(getClass().getResource("Style.css").toExternalForm());
        stage.setScene(scene);
        //stage.show();*/
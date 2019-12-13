import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

// метод Эйлера с пересчетом - то же, что метод Рунге-Кутта 2-го порядка(имеется ввиду порядок точности)
public class Main extends Application {
    //взято с http://www.simumath.net/library/book.html?code=Dif_Ur_example
    //Вычислить методом Рунге-Кутта интеграл дифференциального уравнения y' = x + y при начальном
    // условии y(0) = 1  на отрезке [0, 0.5] с шагом интегрирования h = 0.1
    //производная первого порядка:
    public double fDer(double x, double y) {
        return x * x * x / 3;
    }

    double h = 0.1;
    double x0 = 0.0;
    double xn = 1;
    double y0 = 0, y1;
    double k1, k2, k3, k4, delta_y0;

    int range = (int) ((xn - x0) / h);
    int numD = range;
    double yy[] = new double[range + 1];

    double xx[] = new double[range];

    public void Euhler() {
        yy[0] = y0;
        xx[0] = x0;
        double yc = y0, xc = x0;
        //for (double xc = x0; i<range; xc += h) {
        for (int i = 0; i < range; i++) {
            if (i > 0) xc = xx[i] = xx[i - 1] + h;
            //xx[i] = xc;

            yy[i] = y1 = y0 + h * fDer(xc, yc);
            y0 = yy[i];
            System.out.println("xx[" + i + "] = " + xx[i]);
            System.out.println("yy[" + i + "] = " + yy[i]);
        }
    }
    //здесь каждый раз считается конечное значение у в точке х. Т.о. это подсчёт 10 значений функции.
// Рунге-Кутта так работает(достаточно одного создания к1 и остальных
    public double integrateRK4OrderClassical() {
        System.out.println("range = " + range);
        yy[0] = y0;
        xx[0] = x0;
        for (int i = 0; i < range; i++) {
            if (i > 0) xx[i] = xx[i - 1] + h;
            System.out.println("xx[" + i + "] = " + xx[i]);
            System.out.println("yy[" + i + "] = " + yy[i]);
            k1 = fDer(xx[i], yy[i]);
            k2 = fDer(xx[i] + h / 2, yy[i] + h / 2 * k1);
            k3 = fDer(xx[i] + h / 2, yy[i] + h / 2 * k2);
            k4 = fDer(xx[i] + h, yy[i] + h * k3);
            delta_y0 = h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
            yy[i + 1] = yy[i] + delta_y0;
        }
        System.out.println("yy[" + range + "] = y(" + (xx[range - 1] + h) + ") = " + yy[range]);
        return yy[range];
    }

    public void start(Stage stage) {
        //Вычислим y1. Для этого сначала последовательно вычисляем kj:
        /*k1 = x0 + y0;
        k2 = x0 + h / 2 + y0 + h * k1 / 2;
        k3 = x0 + h / 2 + y0 + h * k2 / 2;
        k4 = x0 + h + y0 + h * k3;

        delta_y0 = h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
        y1 = y0 + delta_y0;*/
        integrateRK4OrderClassical();

        // xx = new double[numD];
        // yy = new double[numD];
        x0 = 0;
        xn = 1;
        y0 = 0;
        h = 0.1; // шаг

        stage.setTitle("Сравнение методов Рунге-Кутты и Эйлера");
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        yAxis.setLabel("Y");
        final LineChart<Number, Number> lineChart = new LineChart<Number, Number>(xAxis, yAxis);
        lineChart.setCreateSymbols(false);//убирает кружочки из узлов

        XYChart.Series seriesb = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesb.getData().add(new XYChart.Data(0, 0));
        }
        seriesb.setName("Rings");

        XYChart.Series seriesRK4 = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesRK4.getData().add(new XYChart.Data(xx[i], yy[i]));
        }
        seriesRK4.setName("Runge-Kutta4");

        Euhler();
        XYChart.Series seriesEuh = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesEuh.getData().add(new XYChart.Data(xx[i], yy[i]));
        }
        seriesEuh.setName("Euhler");


        lineChart.setAnimated(false);
        lineChart.setCreateSymbols(true);

        lineChart.getData().addAll(seriesb, seriesRK4, seriesEuh);
        Scene scene = new Scene(lineChart, 800, 600);
        scene.getStylesheets().add(getClass().getResource("Style.css").toExternalForm());
        stage.setScene(scene);
        stage.show();


    }

    public static void main(String[] args) {
        launch(args);

    }

}


import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

import java.lang.*;

public class Aitken extends Application {
    public double ait(double x, double xx[], double yy[]) {
        System.out.println("\nait is starting with x = " + x);
        for (int i = 0; i < xx.length - 1; i++) {
            for (int k = 1; k < xx.length - i; k++) {//после каждого прохода расстояние между иксами должно увеличиваться на 1. Для этого можно использовать i,
                yy[k - 1] = (yy[k - 1] * (x - xx[k + i]) - yy[k] * (x - xx[k - 1 + i])) / (xx[k - 1 + i] - xx[k + i]);//для этого добавляю i в каждый вызов xx[] ниже
                System.out.println("ait counting yy[k-1] = " + yy[k - 1]);//Последний k при этом не должен использоваться.
            }//Поэтому внутренний цикл укорачивается на i каждый раз.
        }
        System.out.println("ait is over,   yy[0] = " + yy[0]);
        return yy[0];
    }

    double[] xx = {1, 1.2, 1.4, 1.6};
    double[] yy = {1, 1.0954451, 1.1832159, 1.264911};
    int z = 25;// z - кол-во шагов по 0.2 по иксам
    double[] xg = new double[z];//array for x-es
    double[] yg = new double[z];//array for y-s

    public void renewBase() {
        xx[0] = 1;
        xx[1] = 1.2;
        xx[2] = 1.4;
        xx[3] = 1.6;
        yy[0] = 1;
        yy[1] = 1.0954451;
        yy[2] = 1.1832159;
        yy[3] = 1.264911;
    }

    public void renewCoords() {
        for (int i = 0; i < xg.length; i++) {
            xg[i] = 0;
            yg[i] = 0;
        }
    }
    public  double aitken(double x, double []xi,  double []fi) {
        int n = xi.length - 1;
        double []ft =  fi.clone();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                ft[j] = (x - xi[j]) / (xi[i + j + 1] - xi[j]) * ft[j + 1]
                        + (x - xi[i + j + 1]) / (xi[j] - xi[i + j + 1]) * ft[j];
                System.out.println("i = " + i + "; j = " + j + "; Интерполированное значение: " + ft[j]);
            }
        }
        return ft[0];
    }

    public static void main(String[] argv) {
        launch(argv);
    }

    @Override
    public void start(Stage stage) {
        stage.setTitle("Интерполяция по схеме Эйткена");
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        //создаю график
        final LineChart<Number, Number> lineChart =
                new LineChart<Number, Number>(xAxis, yAxis);
        lineChart.setCreateSymbols(false);//убирает кружочки из узлов
        lineChart.setTitle("Title");
        XYChart.Series series1 = new XYChart.Series();
        double x = 1.44;
        ait(x, xx, yy);

        renewCoords();
        //xg[0] = 1.0;
        for (int m = 0; m < z; m++) {//"raskoment"  (m=0)
            if (m == 0) xg[0] = 1.2;
            else
                xg[m] += (xg[m - 1] + 0.01);
            yg[m] = aitken(xg[m], xx, yy);
            renewBase();
            System.out.println("Если x = " + xg[m] + ", то" + " y = " + yg[m]);

        }//can't build a chart, because the function works relatively good only near x = 1.2, to x = 1.49
        for (int i = 1; i < z; i++) {
            series1.getData().add(new XYChart.Data(xg[i], yg[i]));
        }
        Scene scene = new Scene(lineChart, 800, 600);
        lineChart.getData().addAll(series1);

        stage.setScene(scene);
        stage.show();//raskoment
    }
}
/*
* import java.lang.*;

public class Aitken {
    public static void main(String []argv) {
        double []xi = {1, 1.2, 1.4, 1.6};
        double []fi = {1, 1.0954, 1.1832, 1.2649};

        double x = 1.44;
        double f = aitken(x, xi, fi);
        System.out.println("Интерполированное значение: " + f);
    }

    public static double aitken(double x, double []xi,  double []fi) {
        int n = xi.length - 1;
        double []ft =  fi.clone();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                ft[j] = (x - xi[j]) / (xi[i + j + 1] - xi[j]) * ft[j + 1]
                        + (x - xi[i + j + 1]) / (xi[j] - xi[i + j + 1]) * ft[j];
                System.out.println("i = " + i + "; j = " + j + "; Интерполированное значение: " + ft[j]);
            }
        }
        return ft[0];
    }
}

* */
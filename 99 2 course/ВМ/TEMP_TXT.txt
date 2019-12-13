import javax.swing.*;
import java.awt.*;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

public class LagrInter extends Application {
    int n = 3, z = 50;// z - кол-во шагов по 0.2 по иксам// n = 3 - по трём точкам считаем
    double[] xx = new double[200];//array for counting
    double[] yy = new double[200];//array for counting
    double[] x = new double[z];//array for x-es
    double[] y = new double[z];//array for y-s
    double chisl;
    double znam;

    public void clear() {
        xx[0] = 0;
        xx[1] = 0;
        xx[2] = 0;
        yy[0] = 0;
        yy[1] = 0;
        yy[2] = 0;
        chisl = 0;
        znam = 0;
        for (int i = 0; i < z; i++) {
            x[i] = 0;
            y[i] = 0;
        }
    }

    public void lagr() {
        for (int m = 1; m < z; m++) {
            x[m] = x[m - 1] + 0.2;
            for (int i = 0; i < n; i++) {// здесь i - номер избегаемой переменной
                chisl = 1;
                znam = 1;
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        chisl *= (x[m] - xx[j]);
                        znam *= (xx[i] - xx[j]);
                    }
                }
                y[m] += (chisl *= (yy[i])) / znam;
            }
            System.out.println("Если x = " + x[m] + ", то" + " y = " + y[m]);
        }
    }

    @Override
    public void start(Stage stage) {
        stage.setTitle("Интерполяция по формуле Лагранжа");
        //defining the axes
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        //creating the chart
        final LineChart<Number, Number> lineChart =
                new LineChart<Number, Number>(xAxis, yAxis);

        lineChart.setCreateSymbols(false);//убирает кружочки из узлов

        lineChart.setTitle("Title");
        //defining a series


        XYChart.Series series1 = new XYChart.Series();
        series1.setName("(5, 12) (10, 25) (20, 18)");
        //populating the series with data
        x[0] = -5;
        xx[0] = 5;//Заданные точки
        xx[1] = 10;
        xx[2] = 20;
        yy[0] = 12;
        yy[1] = 25;
        yy[2] = 18;//Заданные точки
        lagr();
        for (int i = 1; i < z; i++) {
            series1.getData().add(new XYChart.Data(x[i], y[i]));
        }
        clear();
        XYChart.Series series2 = new XYChart.Series();
        series2.setName("(-1, 1) (0, 0) (1, 1)");
        x[0] = -5;
        xx[0] = -1;
        xx[1] = 0;
        xx[2] = 1;
        yy[0] = 1;
        yy[1] = 0;
        yy[2] = 1;

        lagr();
        for (int i = 1; i < z; i++) {
            series2.getData().add(new XYChart.Data(x[i], y[i]));
        }
        clear();

        XYChart.Series series3 = new XYChart.Series();
        series3.setName("(0, 1) (0.25, 0.707) (0.33, 0.5)");
        x[0] = -5;
        xx[0] = 0;
        xx[1] = 0.25;
        xx[2] = 0.33;

        yy[0] = 1;
        yy[1] = 0.707;
        yy[2] = 0.5;


        lagr();
        for (int i = 1; i < z; i++) {
            series3.getData().add(new XYChart.Data(x[i], y[i]));
        }
        clear();

        Scene scene = new Scene(lineChart, 800, 600);
        lineChart.getData().addAll(series1, series2, series3);

        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}

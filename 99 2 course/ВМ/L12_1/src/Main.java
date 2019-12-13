import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

public class Main extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    public double[] lsolve(double[][] A, double[] b) {
        int n = b.length;
        for (int p = 0; p < n; p++) {
            System.out.println();
            int max = p;
            for (int i = p + 1; i < n; i++) {
                if (Math.abs(A[i][p]) > Math.abs(A[max][p])) {
                    max = i;//каждый последующий сравнивается с максимальным
                }//при первом проходе основного цикла сравниваются первые элементы(р = 0), i меняется
            }
            double[] temp = A[p];
            A[p] = A[max];
            A[max] = temp;//меняю строки местами(первую с максимальной)
            double t = b[p];
            b[p] = b[max];
            b[max] = t;//здесь одномерный массив, так что просто числа переставляются
            for (int i = p + 1; i < n; i++) {
                double alpha = A[i][p] / A[p][p];//перв прох: alpha = х1(из второй строки)/х1(из первой строки)
                b[i] -= alpha * b[p];//сначала из х4 второй строки вычитаем alpha*x4(из первой строки)
                for (int j = p; j < n; j++) {//потом х1[вторая] = х1[вторая] - alpha* х1[первая]
                    A[i][j] -= alpha * A[p][j];//и так делаем для каждого столбца вышеуказанных строк
                }//в итоге первый элемент(х1 вторй строки) занулён
            }//в итоге все х1 занулены(кроме первой строки конечно)
        }//р увеличивается. Дальше всё повторяется для х2, начиная со второй строки. Причём строка с мксимальным
        double[] x = new double[n];
        for (int i = n - 1; i >= 0; i--) {
            double sum = 0.0;
            for (int j = i + 1; j < n; j++) {
                sum += A[i][j] * x[j];
            }//здесь в общем коэффициенты A[i][j] домножаются на решения(х[j]) и произведения складываются
            x[i] = (b[i] - sum) / A[i][i];//сначала sum = 0, в итоге переменная х3(не коэффициент при х3) = х4/х3
        }// в итоге из х4(константа или свободный член) вычитаются посчитанные числа, кроме неизвестной переменной
        return x;//потом разность делится на коэффициент при неизвестной переменной х
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        int n = 5, numD = 100;
        double xxS = 0, yyS = 0, xx2S = 0, xyS = 0, a = 0, b = 0, h = 0.1;
        double yy[] = new double[n];
        double xx[] = new double[n];
        double xx2[] = new double[n];
        double xy[] = new double[n];
        double xc[] = new double[numD];
        double yc[] = new double[numD];

        xx[0] = 1;
        yy[0] = 5.3;
        xx[1] = 2;
        yy[1] = 6.3;
        xx[2] = 3;
        yy[2] = 4.8;
        xx[3] = 4;
        yy[3] = 3.8;
        xx[4] = 5;
        yy[4] = 3.3;
        for (int i = 0; i < n; i++) {
            xx2[i] = xx[i] * xx[i];
            xy[i] = xx[i] * yy[i];
            xxS += xx[i];
            yyS += yy[i];
            xx2S += xx2[i];
            xyS += xy[i];
        }
        //{xx2S * a + xxS * b = xyS;// эту систему надо решить
        //{xxS * a + n * b = yyS;// Гауссом?
        double[][] A = {
                {xx2S, xxS},
                {xxS, n}
        };
        double[] B = {xyS, yyS};
        double[] x = lsolve(A, B);//с пом. м. Гаусса нашёл  корни системы
        a = x[0];
        b = x[1];

        System.out.println("a = " + x[0]);
        System.out.println("b = " + x[1]);

        primaryStage.setTitle("Метод Наименьших квадратов");
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        yAxis.setLabel("Y");
        final LineChart<Number, Number> lineChart = new LineChart<Number, Number>(xAxis, yAxis);
        lineChart.setCreateSymbols(false);//убирает кружочки из узлов

        XYChart.Series seriesInt = new XYChart.Series();
        for (int i = 0; i < n; i++) {
            seriesInt.getData().add(new XYChart.Data(xx[i], yy[i]));
        }
        seriesInt.setName("Точки аппроксимации");

        XYChart.Series seriesApproxim = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            xc[i] = xx[0] + i * h;
            yc[i] = a * xc[i] + b;
            seriesApproxim.getData().add(new XYChart.Data(xc[i], yc[i]));
        }
        // seriesApproxim.getData().add(new XYChart.Data(xc[n - 1], yc[n - 1]));
        seriesApproxim.setName("Аппроксимация");

        lineChart.setAnimated(false);
        lineChart.setCreateSymbols(true);

        lineChart.getData().addAll(seriesInt, seriesApproxim);
        Scene scene = new Scene(lineChart, 800, 600);
        scene.getStylesheets().add(getClass().getResource("Style.css").toExternalForm());
        primaryStage.setScene(scene);
        primaryStage.show();

    }
}

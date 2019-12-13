import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.io.*;

public class L9Graphics extends Application {
    int n = 4; // n - число точек, по которым интерполируем
    int numD = 300;// число точек для точного графика( для корня из икс и остальных )
    double[] xx = new double[n];//точки по которым интерполируем
    double[] yy = new double[n];//точки по которым интерполируем
    double[] xc = new double[numD];//массив точек для записи координат графиков
    double[] yc = new double[numD];//массив точек для записи координат графиков
    //double h = 1 / (double) n, hh = 1;
    double h = Math.PI/6;
    double pi = 3.1415926;
    public double a[] = new double[n];
    double b[] = new double[n];


    public void testA() {
        for (int i = 0; i < n; i++) {
            System.out.println("a[" + i + "] = " + a[i]);
            System.out.println("b[" + i + "] = " + b[i]);
        }
    }

    //ВЫЧИСЛИТЬ КОЭФФИЦИЕНТЫ ПЕРЕБОРОМ
    public double A0Krasno() {
        double sum = 0;
        for (int i = 0; i < n; i++) {//до N-1 написано. Проверить потом
            sum += yy[i];
        }
        sum = (sum / (double) n);
        return (sum);
    }

    //Можно для какой-нибудь одной точки синусоиды, например
    public double AkKrasno(int k) { // 1 д.б. -21.25; 2 д.б. -0.76 (до деления на n)// a[1] и a[2] не совпадают с конспектом
        double sum = 0;
        for (int i = 0; i < n; i++) {//до N-1 написано. Проверить потом
            double temp = Math.cos((double) k * xx[i]);
            //System.out.println("a[" + k + "] counting: " + yy[i] + " * " + temp);
            sum += yy[i] * temp;
        }
        //System.out.println("sum before division Ak = " + sum);
        sum = (sum * 2.0 / (double) n);
        return (sum);
    }

    double BkKrasno(int k) { // 1 д.б. -2.252; 2 д.б. 2.91 до деления на n//b[1] и b[2] совпадают с конспектом
        double sum = 0;
        for (int i = 0; i < n; i++) {//до N-1 написано. Проверить потом
            //double temp = Math.sin(1/(double) k * xx[i]);
            //System.out.println("b[" + k + "] counting: " + yy[i] + " * " + temp);
            sum += yy[i] * Math.sin((double) k * xx[i]);
        }
        // System.out.println("sum before division Bk = " + sum);
        sum = (sum * 2.0 / (double) n);
        return (sum);
    }

    public void cntCoefsKrasno() {
        a[0] = A0Krasno();
        //b[0] = BkKrasno()// здесь можно запутаться, ведь b имеет специфичные
        // коээфициенты и в методичке Красно это не совсем понятно пока. Потом ведь...
        for (int i = 1; i < n; i++) {
            a[i] = AkKrasno(i);
            b[i] = BkKrasno(i);
        }
    }

    public double c1 = 0, c2 = 0;

    public void breakTheCode() {// просто находить эти значения и домножать
        // соответственные коэффициенты а и b на них, идти дальше. Собрать график в конце
        // Так с коэффициентами не получится. Это не Лагрнаж. Надо считать и сразу записывать в xc, yc
        double start = -1, finish = 1, eps = 0.1;
        double h = 0.1;
        boolean coefChanged = false;
        for (int d = 0; d < n - 1; d++) {
            for (double c1 = start; c1 < finish; c1 += h) {
                //System.out.println("step = " + c1);
                for (double c2 = start; c2 < finish; c2 += h) {
                    double compare0 = PolynomeKrasnoBreaker(xx[d], c1, c2);
                    double compare1 = PolynomeKrasnoBreaker(xx[d + 1], c1, c2);
                    //double compare2 = PolynomeKrasnoBreaker(xx[2], c1, c2);
                    //double compare3 = PolynomeKrasnoBreaker(xx[3], c1, c2);

                    if (compare0 < (yy[d] + eps) && compare0 > (yy[d] - eps)
                            && compare1 < (yy[d + 1] + eps) && compare1 > (yy[d + 1] - eps)
                    ) {
                        System.out.println("if works");
                        // this.c1 = c1;
                        //this.c2 = c2;
                        System.out.println("For a[" + d + "] c1 = " + c1 + "for b[" + d + "] c2 = " + c2);
                        //return;
                        System.out.println("a before: " + a[d] + ", b before: " + b[d]);
                        a[d] *= c1;
                        b[d] *= c2;
                        System.out.println("a after: " + a[d] + ", b after: " + b[d]);
                        coefChanged = true;
                        break;
                    }
                }
                if (coefChanged) {
                    coefChanged = false;
                    break;
                }
            }
        }
    }

    // w = 2*pi/T...// почему в методичке коэффициенты посчитаны только до второго?
    double PolynomeKrasnoBreaker(double x, double c1, double c2) {
        double sum = a[0];
        for (int k = 1; k < n; k++) {
            sum += (a[k] * Math.cos((double) (k) //* c1
                    * x));
        }
        for (int k = 1; k < n; k++) {
            sum += (b[k] * Math.sin(((double) k - 1) //* c2
                    * x));
        }
        return sum;
    }

    double PolynomeKrasno(double x) {
        double sum = 0;
        for (int k = 0; k < n; k++) {
            sum += (a[k] * Math.cos((double) (k - 1)
                    * x));
        }
        for (int k = 1; k < n; k++) {
            sum += (b[k] * Math.sin((double) (k - 1)
                    * x));
        }
        return sum;
    }

    double PolynomeKrasnoConspect(double x) {
        double result = -0.12571 - 3.03571 * Math.cos(x) - 0.10857 *
                Math.sin(x) - 0.32171 * Math.cos(2.0 * x) + 0.41571 * Math.sin(2.0 * x);
        return result;
    }

    public void fillKrasnoBreaker(int begin, int end) {
        double range = xx[end] - xx[begin];
        double h = range / (double) numD;
        for (int i = 0; i < numD; i++) {
            xc[i] = xx[0] + (double) i * h;
            yc[i] = PolynomeKrasnoBreaker(xc[i], c1, c2);
        }
    }

    public void fillKrasno() {
        double range = xx[n - 1] - xx[0];
        double h = range / (double) numD;
        for (int i = 0; i < numD; i++) {
            xc[i] = xx[0] + (double) i * h;
            yc[i] = PolynomeKrasnoBreaker(xc[i], c1, c2);
        }
    }

    public void fillKrasno2() {
        double range = 10;
        double h = range / (double) numD;
        for (int i = 0; i < numD; i++) {
            //xc[i] = 0 + (double) i * h;// для корня из икс это раскоментить
            xc[i] = xx[0] + (double) i * h;
            yc[i] = PolynomeKrasnoBreaker(xc[i], c1, c2);
        }
    }

    //заполнение массивов x, y точными значениями, посчитанными по формуле y = sqrt(x);
    //x,y - ссылки; sh - шаг изменения x; n - число точек для заполнения; округление до 4-го знака;
    // здесь можно прописать любую функцию для интерполяции(кроме разрывных, их надо обрабатывать по-особенному,
    // например для 1/х надо исключить ноль и, похоже делать две серии XYChart.Series, т.к. я не знаю, есть ли
    // встроенная опция разрывов)
    public void preciseBuild(double x[], double y[], double start, double end, int nn, boolean isnumD) {
        if (isnumD) {//если строим уже точный график, то начинаем со start
            x[0] = start;//иначе строим точки интерполяции, начиная с заданной для этого точки... тоже start
        } else x[0] = xx[0] = start;//это излишне, ведь ссылки то на один и тот же объект
        double range = end - start;//чего я хотел избежать, так это переопределения xx[]...
        double h = (range / (double) nn);
        // x[0] = xx[0];
        y[0] = Math.sqrt(x[0]);//подставить любую функцию
        for (int i = 1; i < nn; ++i) {
            x[i] = x[i - 1] + h;
            //if (x[i] > -0.1 && x[i] < 0.1) continue;
            y[i] = Math.sqrt(x[i]);//подставить любую функцию
            //Math.sqrt(x[i]);//округление до 4-го знака
        }
    }

    //public void initXXYYSqrt(double hh, int n) {  preciseBuild(xx, yy, 0, hh, n);}

    //инициализация интерполяционных точек//sin{x):
    public void initXXYYsin() {
        xx[0] = -4;
        yy[0] = 0.7;
        xx[1] = 0.87;
        yy[1] = 0.76;
        xx[2] = 2.96;
        yy[2] = 0.17;
        xx[3] = 5.86;
        yy[3] = -0.4;
        //xx[4] = 7.85;
        //yy[4] = 1;
    }// 5 2

    public void initXXYYsin2() {
        xx[0] = Math.PI / 6;
        yy[0] = 0.5;
        xx[1] = 2 * Math.PI / 6;
        yy[1] = Math.sqrt(3) / 2;
        xx[2] = Math.PI / 2;
        yy[2] = 1;
        xx[3] = 4 * Math.PI / 6;
        yy[3] = Math.sqrt(3) / 2;
       /* xx[4] = 5 * Math.PI / 6;
        yy[4] = 0.5;
        xx[5] = Math.PI;
        yy[5] = 0;
        xx[6] = 7 * Math.PI / 6;
        yy[6] = -0.5;
        xx[7] = 8 * Math.PI / 6;
        yy[7] = -Math.sqrt(3) / 2;*/
    }


    //инициализация интерполяционных точек//ДОМАШКА:
    public void initXXYYDom() {
        xx[0] = 2;
        yy[0] = 1;
        xx[1] = 4;
        yy[1] = 0;
        xx[2] = 6;
        yy[2] = 1;
        xx[3] = 8;
        yy[3] = 4;
    }

    double AAConspect(double j) {
        double S = 0;
        for (int k = 0; k < n; k++) {

            S = S + yy[k] * Math.exp(-2 * Math.PI * (double) k *
                    (double) j / (double) n);
        }
        S /= (double) n;
        return S;
    }

    double interpolateConspectManually(double x) {
        double S = 0;
        //for (int j = -n / 2 - 1; j <= n / 2; j++) {     }
        S += a[0] * Math.exp(2 * Math.PI * (-1) * (x - xx[0]) / (n * h));
        System.out.println("1 показатель степени = " + (x - xx[0]) / (n * h));
        S += a[1] * Math.exp(2 * Math.PI * (0) * (x - xx[1]) / (n * h));
        System.out.println("2 показатель степени = " + (x - xx[1]) / (n * h));
        S += a[2] * Math.exp(2 * Math.PI * (1) * (x - xx[2]) / (n * h));
        System.out.println("3 показатель степени = " + (x - xx[2]) / (n * h));
        S += a[3] * Math.exp(2 * Math.PI * (2) * (x - xx[3]) / (n * h));
        System.out.println("4 показатель степени = " + (x - xx[3]) / (n * h));
        return S;
    }

    void countCfsConspectManually() {
        a = new double[n];
        //System.out.println(" A :");
        for (int j = 0; j < n; j++) {// попробовать здесь тоже от -1 до 2 пропихнуть j
            a[j] = AAConspect(j);
            System.out.println("a[" + j + "] = " + a[j]);
        }
    }

    public void fillConspectManually(double start, double finish) {
        xc[0] = start;
        xc[0] = interpolateConspectManually(xc[0]);
        double range = finish - start;
        double h = range / numD;
        for (int i = 1; i < numD; i++) {
            xc[i] += i * h;
            yc[i] = interpolateConspectManually(xc[i]);
        }
    }

    double InterpolateConspect(double x) {
        double S = 0;
        int c = 0, j = 0;
        while (x > xx[j + 1]) j++;// ищу нужный j
        h = 1 / (double) numD;// считаю шаг
        // if (j == 0) j = 1;
        for (double t = (double) n / 2; t > (double) -n / 2; t--) {// пытаюсь реализовать цикл от n/2 до -n/2
            //наверное число в скобках(степень экспоненты д.б. отрицательным)
            S = S + a[j] * Math.exp(2 * pi * t * (double) j * (x - xx[0]) / ((double) n * h));
        }
        return S;
    }

    public void launchConspectManually() {
        countCfsConspectManually();
        fillConspectManually(0, 5);
    }
    public void launchKrasno(){
        cntCoefsKrasno();
        fillKrasno();
    }
    public void launchKrasno2(){
        cntCoefsKrasno();
        fillKrasno2();
    }
    public void launchMachineLearning(){
        cntCoefsMachinelearning();
        fillMachineLearning();
    }

    public void countAllConspect() {
        {
            a = new double[n];
            //System.out.println(" A :");
            for (int j = 0; j < n; j++) {
                a[j] = AAConspect(j);
                System.out.println("a[" + j + "] = " + a[j]);
            }

            for (int jj = 0; jj < numD; jj++) {
                int j = 0;
                //if (j == 0) { xc[0] = xx[0]; } else
                // xc[j] = xc[j - 1] + ((xx[n - 1] - xx[0]) / numD);
                xc[jj] =
                        xx[0] +
                                (xx[n - 1] -
                                        xx[0]) / numD * jj;
                // System.out.println("X: "+xc[j]);
                yc[jj] = InterpolateConspect(xc[jj]);
            }
        }
    }

    //В конспекте написано, что точки д.б. равноотстоящими
    @Override
    public void start(Stage stage) {

        stage.setTitle("Тригонометрическая интерполяция");
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        yAxis.setLabel("Y");
        final LineChart<Number, Number> lineChart = new LineChart<Number, Number>(xAxis, yAxis);
        lineChart.setCreateSymbols(false);//убирает кружочки из узлов

        initXXYYsin2();
        //preciseBuild(xx, yy, 2, 8, n, false);
        XYChart.Series seriesInt = new XYChart.Series();
        for (int i = 0; i < n; i++) {
            seriesInt.getData().add(new XYChart.Data(xx[i], yy[i]));
        }
        seriesInt.setName("Точки интерполяции");

        preciseBuild(xc, yc, 0, 10, numD, true);
        XYChart.Series seriesSqrt = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesSqrt.getData().add(new XYChart.Data(xc[i], yc[i]));
        }
        seriesSqrt.setName("Корень из икс");

        //cntCoefsKrasno();
        //breakTheCode();
        //System.out.println("calculating finished");
        //fillKrasno2();
        //conspectLauncManually();
        launchKrasno();

        XYChart.Series seriesTrig = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesTrig.getData().add(new XYChart.Data(xc[i], yc[i]));
        }
        //seriesTrig.getData().add(new XYChart.Data(xx[n-1], yy[n-1]));
        seriesTrig.setName("Krasno");

        launchConspectManually();
        XYChart.Series seriesConspectManually = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesConspectManually.getData().add(new XYChart.Data(xc[i], yc[i]));
        }
        //seriesTrig.getData().add(new XYChart.Data(xx[n-1], yy[n-1]));
        seriesConspectManually.setName("ConspectManually");

        launchKrasno2();
        XYChart.Series seriesKrasno2 = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesKrasno2.getData().add(new XYChart.Data(xc[i], yc[i]));
        }
        //seriesTrig.getData().add(new XYChart.Data(xx[n-1], yy[n-1]));
        seriesKrasno2.setName("Krasno2");

        launchMachineLearning();
        XYChart.Series seriesMachineLearning = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesMachineLearning.getData().add(new XYChart.Data(xc[i], yc[i]));
        }
        //seriesTrig.getData().add(new XYChart.Data(xx[n-1], yy[n-1]));
        seriesMachineLearning.setName("MachineLearning");


        lineChart.setAnimated(false);
        lineChart.setCreateSymbols(true);

        lineChart.getData().addAll(seriesInt, seriesSqrt, seriesTrig,
                //seriesConspectManually,
                //seriesKrasno2,
                seriesMachineLearning);
        Scene scene = new Scene(lineChart, 800, 600);
        scene.getStylesheets().add(getClass().getResource("Style.css").toExternalForm());
        stage.setScene(scene);
        stage.show();
        //System.out.println("Int2(-2.7): " + Interpolate2(-2.7) + ", must be -0.4266");
        //System.out.println("Int2(-1): " + Interpolate2(-1) + ", must be -0.844");
        //System.out.println("Int2(2): " + Interpolate2(2) + ", must be 0.9");
    }

    public static void main(String[] args) {
        launch(args);

    }

    // попробую ка без цикла сделать
    double AMachinelearning(int m) {
        return (2 / (2 * (double) n + 1) *
                (yy[0] * Math.cos(2 * pi * (-1) * (double) m / (2 * (double) n + 1))) +
                yy[1] * Math.cos(2 * pi * (0)) * (double) m / (2 * (double) n + 1) +
                yy[2] * Math.cos(2 * pi * (1) * (double) m / (2 * (double) n + 1)) +
                yy[3] * Math.cos(2 * pi * (2) * (double) m / (2 * (double) n + 1))
                //yy[4] * Math.cos(2 * pi * (  4 ) * (double) m / (2 * (double) n + 1))
        );
    }

    double BMachinelearning(int m) {
        return (2 / (2 * (double) n + 1) *
                (yy[0] * Math.sin(2 * pi * (-1) * (double) m / (2 * (double) n + 1))) +
                yy[1] * Math.sin(2 * pi * (0) * (double) m / (2 * (double) n + 1)) +
                yy[2] * Math.sin(2 * pi * (1) * (double) m / (2 * (double) n + 1)) +
                yy[3] * Math.sin(2 * pi * (2) * (double) m / (2 * (double) n + 1))
                //yy[4] * Math.sin(2 * pi * (4) * (double) m / (2 * (double) n + 1))
        );
    }

    void cntCoefsMachinelearning() {
        for (int i = 0; i < n; i++) {
            a[i] = AMachinelearning(i);
            b[i] = BMachinelearning(i);
        }
    }

    double interpMachineLearning(double x) {
        return (a[0] + a[1] * Math.cos(x) + a[2] * Math.cos(2 * x) + a[3] * Math.cos(3 * x) + //a[4] * Math.cos(4*x)
                +b[1] * Math.sin(x) + b[2] * Math.sin(2 * x) + b[3] * Math.sin(3 * x)//+ b[4] * Math.sin(4*x)
        );
    }

    void fillMachineLearning() {
        cntCoefsMachinelearning();
        double range = xx[3] - xx[0];
        double h = range / numD;
        for (int i = 0; i < numD; i++) {
            xc[i] = xx[0] + i * h;
            yc[i] = interpMachineLearning(xc[i]);
        }
    }
    public void readF() {
        try (FileReader reader = new FileReader("result.txt")) {
            // читаем посимвольно
            int c;
            String str = new String();
            while ((c = reader.read()) != -1) {
                str += c;
                System.out.print((char) c);
            }
            System.out.println("after all " + str);
        } catch (IOException ex) {

            System.out.println(ex.getMessage());
        }
    }

    public void initXXYYKrasno() {
        xx[0] = 0;
        yy[0] = -2;
        xx[1] = pi / 3;
        yy[1] = -0.92;
        xx[2] = 2 * pi / 3;
        yy[2] = 0.83;
       /* xx[3] = pi;
        yy[3] = 2;
        xx[4] = 4 * pi / 3;
        yy[4] = 2.32;
        xx[5] = 5 * pi / 3;
        yy[5] = -1.11;
        xx[6] = 2 * pi;
        yy[6] = -2;*/
    }

    public void initXXYYT() {//инициализация интерполяционных точек
        xx[0] = 1;
        yy[0] = 2;
        xx[1] = 3;
        yy[1] = 6;
        xx[2] = 5;
        yy[2] = 2;
        xx[3] = 7;
        yy[3] = -2;
        xx[4] = 9;
        yy[4] = 2;
    }// 5 2
}
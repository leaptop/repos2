import javafx.application.Application;
import javafx.stage.Stage;

import java.text.DecimalFormat;

public class Main extends Application {
    public void start(Stage stage) {
        System.out.print("X\t\t\t\tY\t\t\t\tY'");
        double eps = 10E-12;
        double x0 = 0;
        double y0 = 1;
        double h = 0.2;
        double xn = 1;
        double yn = 2.718281828;
        //double yn = 3;
        double z0;
        double m1;
        double m2;
        double m3;
        double precY;
        double hit1;
        double hit2;
        double hitAvg;
        int p = 0;
        //System.out.print("\n  Введите x0,y0,xn,yn,h:");//тут мы угадываем значение первой производной  и подставляем в РК4
        // т.о. мы прикидываем y'(x) = m1, а это то,что было дано при решении РК4 первого порядка
        m1 = 0.7;// потом это подставляется как z0 в формулу РК4, т.е. как значение первой производной
        //при задании этой производной и происходит "выстрел"( рисуется график в сторону yn )
        //System.out.print("\n  Введите M1: " + m1);
        precY = yn;//Задаю сюда известное значение функции(заданное)
        z0 = m1;
        hit1 = shoot(x0, y0, z0, xn, h, p = 1);//типа первый игрек, найденный с помощью РК4(м1 вроде... хз... короче это
        //игрек для икс равного 1
        System.out.print("\n hit1 : " + hit1);
        if (Math.abs(hit1 - precY) < eps) {//сравниваю, отличается ли значение  игрека от известного на эпсилон
            System.out.print("\n  Значения x и соответствующего z :\n");//если попал случайно, значит это и сеть ответ
            shoot(x0, y0, z0, xn, h, p = 1);
            return;
        } else {//иначе стреляю ещё раз(прикидываю значение первой производной
            m2 = 1.2;
            // System.out.print("\nEnter the value of M2: " + m2);
            z0 = m2;
            hit2 = shoot(x0, y0, z0, xn, h, p = 1);//м2 передаётся в shoot как z0 ... хз чё это... xn нигде не меняется
            System.out.print("\nhit2 : " + hit2);
        }
        if (Math.abs(hit2 - precY) < eps) {//опять проверка "а вдруг попал"
            System.out.print("\n  Значения x и соответствующего z :\n");
            shoot(x0, y0, z0, xn, h, p = 1);
            return;
        } else {//иначе используем спец формулу для подсчета первой производной
            System.out.print("\nM2=" + m2 + "\t" + "M1=" + m1);//суть нижнего равенства в том, что три вектора коллинеарны,
            // а из этого вытекает, что их координаты пропорциональны
            m3 = m2 + (((m2 - m1) * (precY - hit2)) / (hit2 - hit1));//precY здесь с тем значением, которое я прописал в yn
            if (hit1 - hit2 == 0)//разобраться с формулой выше: оригинал    m3=m2+(((m2-m1)*(b-b2))/(1.0*(b2-b1)));
                System.exit(0);//дело в том, что векторы (m1, hit1), (m2, hit2), (m3, y0) должны быть коллинеарны
            //а у коллинеарных векторов координаты пропорциональны

            System.out.print("\nПересчитали M =" + m3);
            z0 = m3;//посчитали по формулке м3, запустили shoot с м3, как z0, р задали нулём на этот раз
            hitAvg = shoot(x0, y0, z0, xn, h, p = 0);//В итоге hitAvg - зн-ие ф-ции в точке с производной m3
        }
        if (Math.abs(hitAvg - precY) < eps) {
            System.out.print("\nРешение :");
            shoot(x0, y0, z0, xn, h, p = 1);
            System.exit(0);
        }
        do {
            m1 = m2;
            m2 = m3;
            hit1 = hit2;
            hit2 = hitAvg;
            m3 = m2 + (((m2 - m1) * (precY - hit2)) / (hit2 - hit1));
            z0 = m3;
            hitAvg = shoot(x0, y0, z0, xn, h, p = 0);

        } while (Math.abs(hitAvg - precY) < eps);
        z0 = m3;
        shoot(x0, y0, z0, xn, h, p = 1);
        return;
    }

    double f1(double x, double y, double z) {
        return (z);
    }

    double f2(double x, double y, double z) {
        return (Math.exp(x) + y) / 2;
        //return(x+y);//(initial task with 0 1 3 4 0.5, M1 = 0, M2 = 1) from https://www.codewithc.com/c-program-for-shooting-method/
    }

    double shoot(double x0, double y0, double z0, double xn, double h, int p) {
        double x;
        double y;
        double z;
        double k1;
        double k2;
        double k3;
        double k4;
        double l1;
        double l2;
        double l3;
        double l4;
        double k;
        double l;
        double x1;
        double y1;
        double z1;
        x = x0;
        y = y0;
        z = z0;
        do {
            k1 = h * f1(x, y, z);
            l1 = h * f2(x, y, z);
            k2 = h * f1(x + h / 2.0, y + k1 / 2.0, z + l1 / 2.0);
            l2 = h * f2(x + h / 2.0, y + k1 / 2.0, z + l1 / 2.0);
            k3 = h * f1(x + h / 2.0, y + k2 / 2.0, z + l2 / 2.0);
            l3 = h * f2(x + h / 2.0, y + k2 / 2.0, z + l2 / 2.0);
            k4 = h * f1(x + h, y + k3, z + l3);
            l4 = h * f2(x + h, y + k3, z + l3);
            l = 1 / 6.0 * (l1 + 2 * l2 + 2 * l3 + l4);
            k = 1 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
            y1 = y + k;//подсчёт игрека по РК4
            x1 = x + h;//инкремент икса
            z1 = z + l;//инкремент доп ф-ции?
            x = x1;
            y = y1;
            z = z1;

            if (p == 1) {
                String x00 = new DecimalFormat("#0.000").format(x1);
                String y11 = new DecimalFormat("#0.0000000000000").format(y1);
                String z11 = new DecimalFormat("#0.0000000000000").format(z1);
                System.out.print("\n" + x00 + "\t" + y11 + "\t\t" + z11);
            }
        } while (x < xn);
        return (y);
    }

    public static void main(String args) {
        launch(args);
    }
}

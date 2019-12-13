import javafx.application.Application;
import javafx.stage.Stage;

import java.text.DecimalFormat;

public class Main extends Application {
    public void start(Stage stage) {
        System.out.print("X\t\t\t\tY\t\t\t\tY'");
        double eps = 10E-8, x0 = 0, y0 = 1, h = 0.2, xn = 1, yn = 2.718281828, precY = yn, m1 = 0.7, z0 = m1,
                m2 = 1.2, m3,  hit1, hit2, hitAvg;
        int p = 0;
        hit1 = shoot(x0, y0, z0, xn, h, p = 1);// первый игрек, найденный с помощью РК4
        System.out.print("\n hit1 : " + hit1);
        if (Math.abs(hit1 - precY) < eps) {//сравниваю, отличается ли значение  игрека от известного нам эпсилон
            System.out.print("\n  Значения x и соответствующего z :\n");//если попал случайно, значит это и сеть ответ
            shoot(x0, y0, z0, xn, h, p = 1);
            return;
        } else {//иначе стреляю ещё раз(прикидываю значение первой производной
            // System.out.print("\nEnter the value of M2: " + m2);
            z0 = m2;
            hit2 = shoot(x0, y0, z0, xn, h, p = 1);//м2 передаётся в shoot как z0
            System.out.print("\nhit2 : " + hit2);
        }
        if (Math.abs(hit2 - precY) < eps) {//опять проверка "а вдруг попал"
            System.out.print("\n  Значения x и соответствующего z :\n");
            shoot(x0, y0, z0, xn, h, p = 1);
            return;
        } else {//иначе используем спец формулу для подсчета первой производной
            System.out.print("\nM2=" + m2 + "\t" + "M1=" + m1);
            m3 = m2 + (((m2 - m1) * (precY - hit2)) / ((hit2 - hit1)));
            if (hit1 - hit2 == 0)
                System.exit(0);//дело в том, что векторы (m1, hit1), (m2, hit2), (m3, y0) должны быть коллинеарны
            System.out.print("\nПересчитали M =" + m3);
            z0 = m3;
            hitAvg = shoot(x0, y0, z0, xn, h, p = 0);
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
            m3 = m2 + (((m2 - m1) * (precY - hit2)) / ((hit2 - hit1)));
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
    }
// получается shoot это и есть метод Рунге-кутты4 здесь
    double shoot(double x0, double y0, double z0, double xn, double h, int p) {
        double x = x0, y = y0, z = z0, k1, k2, k3, k4, l1, l2, l3, l4, k, l, x1, y1, z1;

        if (p == 1) {
            String x00 = new DecimalFormat("#0.000").format(x);
            String y11 = new DecimalFormat("#0.0000000000000").format(y);
            String z11 = new DecimalFormat("#0.0000000000000").format(z);
            System.out.print("\n" + x00 + "\t" + y11 + "\t\t" + z11);
        }
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
            y1 = y + k;
            x1 = x + h;
            z1 = z + l;
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

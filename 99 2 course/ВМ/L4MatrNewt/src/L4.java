import com.sun.xml.internal.bind.v2.schemagen.xmlschema.SimpleDerivation;

import java.util.function.DoubleFunction;

public class L4 {
    private static final double DX = 0.00000001;
    public static double x = 2, y = 1, e = 0.0000001, det;

    private static DoubleFunction<Double> derive(DoubleFunction<Double> f) {// здесь как-то считается производная
        return (x) -> (f.apply(x + DX) - f.apply(x)) / DX;
    }

    public static double[][] m = new double[2][2];

    public static void mCount() {//расчёт матрицы по производным и приближенным значениям икс и игрек
        m[0][0] = nm00(x, y);
        m[0][1] = nm01(x, y);
        m[1][0] = nm10(x, y);
        m[1][1] = nm11(x, y);
    }

    public static void determCount() {//расчёт определителя матрицы
        det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
    }

    public static void mAlgebrDopoln() {//построение матрицы алгебр. дополнений
        double temp = m[0][0];
        m[0][0] = m[1][1];
        m[1][1] = temp;

        temp = m[0][1];
        m[0][1] = m[1][0];
        m[1][0] = temp;
    }

    public static void mTranspon() {//транспонирование матрицы
        double temp = m[1][0];
        m[1][0] = m[0][1];
        m[0][1] = temp;

        m[0][1] = -1 * m[0][1];
        m[1][0] = -1 * m[1][0];
    }

    public static void mObratn() {//построение обратной матрицы
        m[0][0] = m[0][0] * (1 / det);
        m[0][1] = m[0][1] * (1 / det);
        m[1][0] = m[1][0] * (1 / det);
        m[1][1] = m[1][1] * (1 / det);
    }

    public static double f11, f22;

    public static void finalCount() {//расчёт икс и игрек
        f11 = x * x / y - 3;
        f22 = x * x + y * y * y - 5;

        x = x - (m[0][0] * f11 + m[0][1] * f22);
        y = y - (m[1][0] * f11 + m[1][1] * f22);
    }

    public static double nm00(double argX, double y) {//argX - отдельная переменная, т.к. лямбда по-другому не разрешает
        //f1(x) = x*x + y*y*y - 4
        DoubleFunction<Double> f1 = (x) -> (x * x / y - 3);//f11
        //f1'(x) = 2x( производная по икс)
        DoubleFunction<Double> f1Deriv = derive(f1);
        return f1Deriv.apply(argX);
    }

    public static double nm10(double argX, double y) {
        //f2(x) = x/y - 2
        DoubleFunction<Double> f2 = (x) -> (x * x + y * y * y - 5);//f22
        //f2'(x) = 1/y(производная по икс)
        DoubleFunction<Double> f2Deriv = derive(f2);
        return f2Deriv.apply(argX);
    }

    public static double nm01(double x, double argY) {
        //f1(x) = x*x + y*y*y - 4
        DoubleFunction<Double> f1 = (y) -> (x * x / y - 3);//f11
        //f1'(x) = 3*y*y( производная по игрек)
        DoubleFunction<Double> f1Deriv = derive(f1);
        return f1Deriv.apply(argY);
    }

    public static double nm11(double x, double argY) {
        //f2(x) = x/y - 2
        DoubleFunction<Double> f2 = (y) -> (x * x + y * y * y - 5);//f22
        //f2'(x) = -x/(y*y) (производная по игрек)
        DoubleFunction<Double> f2Deriv = derive(f2);
        return f2Deriv.apply(argY);
    }

    public static void main(String[] args) {
        double xt, yt;
        do {
            xt = x;
            yt = y;
            mCount();
            determCount();
            mAlgebrDopoln();
            mTranspon();
            mObratn();
            finalCount();
            System.out.println("F1(x) = " + f11 + "; F2(x) = " + f22);
            System.out.println("X = " + x + "; Y = " + y + "\n");
        } while (Math.abs((Math.abs(x) - Math.abs(xt))) > e && Math.abs((Math.abs(y) - Math.abs(yt))) > e);
    }
}
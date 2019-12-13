import org.apache.commons.math3.analysis.UnivariateFunction;
import org.apache.commons.math3.analysis.integration.*;

// ТАК РЕАЛИЗУЮТСЯ ФУНКЦИИ ВЫСШЕЙ МАТЕМАТИКИ

public class Main {
    public static void main(String[] args) {
       // SimpsonIntegratorTest st = new SimpsonIntegratorTest();
        //st.testSinFunction();
        SimpsonIntegrator stt = new SimpsonIntegrator();

        UnivariateFunction f = new UnivariateFunction() {
            @Override
            public double value(double v) {
                v = v*v;
                return v;
            }
        };
        System.out.println(stt.integrate(40, f, 2, 3));//MaxEval - число шагов?




    }
}

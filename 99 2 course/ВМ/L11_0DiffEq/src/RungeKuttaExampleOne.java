/*     Example One
         Example of the use of the class RungeKutta demonstrating the use of the
         static methods in solving a single ordinary differential equation:
                  dy/dx = a.x.sqrt(1.0 - y*y)

       Michael Thomas Flanagan
       m.flanagan@ee.ucl.ac.uk

       Updated  January 2010
*/

import flanagan.integration.*;

// Class to demonstrate the fourth order Runge-Kutta method in class RungeKutta.
public class RungeKuttaExampleOne{

    public static void main(String[ ] arg){

        // Create instance of the class holding the derivative evaluation method
        Deriv d1 = new Deriv();

        // Assign values to constants in the derivative function
        double a = 10.0D;
        d1.setA(a);

        // Variable declarations
        double x0 = 0.0D;      // initial value of x
        double y0 = 0.0D;      // initial value of y
        double xn = 1.0D;      // final value of x
        double yn = 0.0D;      // returned value of y at x = xn
        double h = 0.01D;      // step size

        // Call Fourth Order Runge-Kutta method
        yn = RungeKutta.fourthOrder(d1, x0, y0, xn, h);

        // Output the result
        System.out.println("The value of y at x = " + xn + " is " + yn);
    }
}


// Class to evaluate the derivative dy/dx = a.x.sqrt(1.0 + y*y) for given values of x and y.
class Deriv implements DerivFunction{

    private double a = 0.0D;

    public double deriv(double x, double y){
        double dydx = a*x*Math.sqrt(1.0 + y*y);
        return dydx;
    }

    public void setA(double a){
        this.a = a;
    }
}
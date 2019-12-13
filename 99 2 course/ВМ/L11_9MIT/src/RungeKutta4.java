/* Rachelle Villalon (c) 2011
 *
 *  RungeKutta.java uses Euler's method and the fourth order Runge-Kutta
 *  to compute the derivative of dx/dy + y = 0 for a simple harmonic oscillator.
 * */

public class RungeKutta4 {


    // The number of steps to use in the interval
    public static final double STEPS = 100 * Math.PI;

    // The derivative dy/dx at a given value of x and y.
    static double stiffness = 1;
    static double damping = -0.005;

    public static double deriv(double a, double x, double y)
    {
        return a = -stiffness * x - damping * y;
    }

    // The `main' method does the actual computations
    public static void main(String[] argv) {

        final double amplitude = 5.0; // Max. amplititude for the oscillator
        double h = 1.0 / STEPS; // timestep
        double k1x, k2x, k3x, k4x;  // Runge-Kutta coefficients for position.
        double k1y, k2y, k3y, k4y; // Runge-Kutta coefficients for velocity.
        double x, y; // position (x) and velocity (y) of the oscillator
        int i;
        double timeCurr; // time elapsed
        double sumError = 0;


        // Computation by Euler's method
        // Initialize y
        y = 0.0;
        for (i = 0; i < STEPS; i++)
        {
            // Step through, updating t and incrementing y
            x = i * h; // t= i * h;
            y += h * deriv(0.0, x, y);  //time. position, velocity
        }

        // Print out the result that we get.
        System.out.println("Using the Euler method " + "The value is:");
        System.out.println(y);

        // Computation by 4th order Runge-Kutta
        // Initialize y (initial conditions)
        y = 0.0;
        x = amplitude;
        timeCurr = 0.0;

        for (i = 0; i < STEPS; i++) {
            // Step through, updating x
            x= i * h;

            // Computing all of the trial values
            // calculating coefficients with the Runge-Kutte 4th order
            // algorithm:

            k1y = h * deriv(timeCurr, x, y);
            k1x = y * h;

            k2y = h * deriv(timeCurr, x + h / 2, y + k1x / 2);
            k2x = h * (y + k1y / 2);

            k3y = h * deriv(timeCurr, x + h / 2, y + k2x / 2);
            k3x = h * (k2y / 2);

            k4y = h * deriv(timeCurr, x + h, y + k3x);
            k4x = h * (y + k3x);

            // Incrementing x and y. Determine new values of position and
            // velocity:
            y += k1y / 6 + k2y / 3 + k3y / 3 + k4y / 6;
            x += k1x / 6 + k2x / 3 + k3x / 3 + k4x / 6;
            timeCurr += h;
            sumError += 0;
        }

        // Print out the result that we get.
        System.out.println();
        System.out.println("Using 4th order Runge-Kutta "
                + "The final slope value is:");
        System.out.println(y);

        // Print out the average error.
        System.out.println("The average error is: " + sumError / h);

        // Computation by closed form solution
        // Print out the result that we get.
        System.out.println();
        System.out.println("The final (error) value really is:");
        y = (Math.exp(0.5) - Math.exp(-0.5)) / 2;
        System.out.println(y);

    }
}
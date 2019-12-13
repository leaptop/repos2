import java.util.Scanner;

// © 2018 TheFlyingKeyboard and released under MIT License
// theflyingkeyboard.net
public class Main {
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        double intervalBegin;
        double intervalEnd;
        double x;
        double precision;
        System.out.print("Enter begining of interval: ");
        intervalBegin = reader.nextDouble();
        System.out.print("Enter end of interval: ");
        intervalEnd = reader.nextDouble();
        System.out.print("Enter precision of method: ");
        precision = reader.nextDouble();
        if (function(intervalBegin) * function(intervalEnd) > 0.0d) {
            System.out.println("Function has same signs at ends of interval");
            return;
        }
        x = (intervalBegin * function(intervalEnd) - intervalEnd * function(intervalBegin)) /
                (function(intervalEnd) - function(intervalBegin));
        while (Math.abs(function(x)) > precision) {
            System.out.println("X: " + x + " f(x): " + function(x));
            if (function(intervalBegin) * function(x) < 0) {
                x = (x * function(intervalBegin) - intervalBegin * function(x)) / (function(intervalBegin) - function(x));
            } else {
                x = (x * function(intervalEnd) - intervalEnd * function(x)) / (function(intervalEnd) - function(x));
            }
        }
    }

    static double function(double x) { //x^2 + 2x -1
        return x * x - 2;
    }
}
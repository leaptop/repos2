package trig;

/**
 * author: bartosz
 * date: 20.01.16
 */
public class Point {
    private double x;
    private double y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() { return x; }

    public double getY() { return y; }

    public void printPoint() { System.out.printf("(%5.2f, %5.2f)", x, y); }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}

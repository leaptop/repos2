package trig;

/**
 * author: bartosz
 * date: 20.01.16
 */
public class Points {
    Point[] points;

    public Points(int pointsNumber) {
        points = new Point[pointsNumber];
    }

    public Points(String filePath) {
        Point[] points = PointsIO.readPointsFromFile(filePath);
        this.points = points;
    }

    public Point[] getPoints() { return points; }

    public void setPoint(int index, Point point) {
        if(points == null || points.length <= index)
            points = new Point[index+1];
        points[index] = point;
    }

    public int getPointsNumber() {
        if(points == null)
            return 0;
        return points.length;
    }

    public double[][] getPointsInArray() {
        if(points == null || points.length == 0)
            return null;

        double[][] pointsArray = new double[points.length][];
        for(int i = 0; i < points.length; i++)
            pointsArray[i] = new double[2];

        int index = 0;
        for(Point point : points) {
            pointsArray[index][0] = point.getX();
            pointsArray[index][1] = point.getY();
            index++;
        }

        return pointsArray;
    }

    public void printPoints() {
        if(points == null) {
            System.out.println("Container for points is empty.");
            return ;
        }

        System.out.printf("Number of points: %d\n", points.length);
        for(int i = 0; i < points.length; i++) {
            System.out.printf("Point number %3d: ", i+1);
            if(points[i] != null) points[i].printPoint();
            System.out.println();
        }
        System.out.println();
    }
}

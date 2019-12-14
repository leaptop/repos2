package trig;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * author: bartosz
 * date: 20.01.16
 */
public class PointsIO {
    public static Point[] readPointsFromFile(String filePath) {
        Point[] points = null;
        if(filePath != null && !filePath.isEmpty()) {
            try {
                File file = new File(filePath);
                Scanner scanner = new Scanner(file);

                if(scanner.hasNextLine()) {
                    String[] firstLine = scanner.nextLine().trim().split("\\s+");

                    int pointsNumber = 0;

                    if(firstLine.length == 1) {
                        try {
                            pointsNumber = Integer.parseInt(firstLine[0]);
                        } catch(NumberFormatException e) {
                            System.out.println("Wrong point number format.");
                        }
                    } else {
                        return null;
                    }

                    if(pointsNumber == 0) return null;

                    points = new Point[pointsNumber];
                    double x = 0.0;
                    double y = 0.0;

                    for(int i = 0; i < pointsNumber; i++) {
                        x = i * 2 * Math.PI / pointsNumber;
                        if(scanner.hasNextLine()) {
                            String[] line = scanner.nextLine().trim().split("\\s+");

                            if(line.length != 1) return null;

                            try {
                                y = Double.parseDouble(line[0]);
                            } catch(NumberFormatException e) {
                                System.out.println("Wrong point number format.");
                            }

                            points[i] = new Point(x, y);
                        }
                    }
                } else {
                    return null;
                }
            } catch(FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        return points;
    }
}

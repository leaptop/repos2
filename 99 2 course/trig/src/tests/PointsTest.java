package tests;

import trig.Points;

/**
 * author: bartosz
 * date: 20.01.16
 */
public class PointsTest {
    public static void main(String[] args) {
        Points points = new Points("/home/bartosz/IdeaProjects/trig/src/tests/data/points3.txt");
        points.printPoints();
    }
}

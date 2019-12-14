package tests;

import trig.Trig;

/**
 * author: bartosz
 * date: 20.01.16
 */
public class TrigTest {
    public static void main(String[] args) {
        Trig trig = new Trig("C:/Users/Stepan/source/repos/trig/src/tests/data/points2.txt");
        trig.calculateValuesPoints(10000);
        trig.visualize();
    }
}

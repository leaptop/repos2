using System;

namespace DistanceTask
{
    public static class DistanceTask
    {
        // Расстояние от точки (x, y) до отрезка AB с координатами A(ax, ay), B(bx, by)
        public static double GetDistanceToSegment(double ax, double ay, double bx, double by, double x, double y)
        {
            double dToA = Math.Sqrt(Math.Pow((x - ax), 2) + Math.Pow((y - ay), 2));
            double dToB = Math.Sqrt(Math.Pow((x - bx), 2) + Math.Pow((y - by), 2));
            double ab = Math.Sqrt(Math.Pow((ax - bx), 2) + Math.Pow((ay - by), 2));

            if (ax == bx && ay == by) return dToA;
            if (((dToA + dToB) - ab)<=0.001) return 0;

            double dToLine = Math.Abs((by - ay) * x - (bx - ax) * y + bx * ay - by * ax)
                / Math.Sqrt((by - ay)* (by - ay) + ((bx - ax)* (bx - ax)));
            double e = Math.Sqrt(dToA * dToA - dToLine * dToLine);
            double f = Math.Sqrt(dToB * dToB - dToLine * dToLine);

            if (Math.Abs(e + f - ab) < 0.0001) return dToLine;
            if (f > e) return dToA; else return dToB;
           
            

        }
    }
}
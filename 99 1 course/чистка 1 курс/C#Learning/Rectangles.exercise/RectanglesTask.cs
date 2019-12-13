using System;

namespace Rectangles
{
    public static class RectanglesTask
    {
        // Пересекаются ли два прямоугольника (пересечение только по границе также считается пересечением)
        public static bool AreIntersected(Rectangle r1, Rectangle r2)
        {
            return ((r1.Left + r1.Width >= r2.Left && r1.Left <= r2.Left + r2.Width) &&
                ((r1.Top + r1.Height >= r2.Top && r1.Top <= r2.Top + r2.Height)));
        }

        // Площадь пересечения прямоугольников
        public static int IntersectionSquare(Rectangle r1, Rectangle r2)
        {
            int x1 = Math.Max(r1.Left, r2.Left);
            int x2 = Math.Min(r1.Left + r1.Width, r2.Left + r2.Width);
            int y1 = Math.Max(r1.Top, r2.Top);
            int y2 = Math.Min(r1.Top + r1.Height, r2.Top + r2.Height);

            if (x2 >= x1 && y2 >= y1) return (x2 - x1) * (y2 - y1);
            else return 0;
        }

        // Если один из прямоугольников целиком находится внутри другого — вернуть номер (с нуля) внутреннего.
        // Иначе вернуть -1
        // Если прямоугольники совпадают, можно вернуть номер любого из них.
        public static int IndexOfInnerRectangle(Rectangle r1, Rectangle r2)
        {
            if ((r1.Left <= r2.Left) &&
            ((r2.Left + r2.Width) <= (r1.Left + r1.Width)) &&
            (r1.Top <= r2.Top) &&
            ((r2.Top + r2.Height) <= (r1.Top + r1.Height)))
                return 1;
            else if ((r2.Left <= r1.Left) &&
            ((r1.Left + r1.Width) <= (r2.Left + r2.Width)) &&
            (r2.Top <= r1.Top) &&
            ((r1.Top + r1.Height) <= (r2.Top + r2.Height)))
                return 0;
            else return -1;
        }
    }
}
// В этом пространстве имен содержатся средства для работы с изображениями. Чтобы оно стало доступно, в проект был подключен Reference на сборку System.Drawing.dll
using System;
using System.Drawing;


namespace Fractals
{
	internal static class DragonFractalTask
	{
		public static void DrawDragonFractal(Pixels pixels, int iterationsCount, int seed)
		{
            var point = new Point(1,0); 
            //Начните с точки (1, 0)
            //Создайте генератор рандомных чисел с сидом seed
            var random = new Random(seed);

            //На каждой итерации:
            for (int i = 0; i < iterationsCount; i++)
            {
                double x1, y1;
                var nextNumber = random.Next(10);
                if (nextNumber % 2 == 1)
                {
                   x1 = (int)((point.X * Math.Cos(Math.PI / 4) - point.Y * Math.Sin(Math.PI / 4)) / Math.Sqrt(2));
                   y1 = (int)((point.X * Math.Sin(Math.PI / 4) + point.Y * Math.Cos(Math.PI / 4)) / Math.Sqrt(2));
                }else
                {
                    x1 =(int)((point.X * Math.Cos(3*Math.PI / 4) - point.Y * Math.Sin(3*Math.PI / 4)) / Math.Sqrt(2))+1;
                    y1 = (int)((point.X * Math.Sin(3*Math.PI / 4) + point.Y * Math.Cos(3*Math.PI / 4)) / Math.Sqrt(2));
                }
                pixels.SetPixel(x1,y1);

            }
            //1. Выберите случайно одно из следующих преобразований и примените его к текущей точке:

            //	Преобразование 1. (поворот на 45° и сжатие в sqrt(2) раз):
            //	x' = (x · cos(45°) - y · sin(45°)) / sqrt(2)
            //	y' = (x · sin(45°) + y · cos(45°)) / sqrt(2)

            //	Преобразование 2. (поворот на 135°, сжатие в sqrt(2) раз, сдвиг по X на единицу):
            //	x' = (x · cos(135°) - y · sin(135°)) / sqrt(2) + 1
            //	y' = (x · sin(135°) + y · cos(135°)) / sqrt(2)

            //2. Нарисуйте текущую точку методом pixels.SetPixel(x, y)


        }
	}
}
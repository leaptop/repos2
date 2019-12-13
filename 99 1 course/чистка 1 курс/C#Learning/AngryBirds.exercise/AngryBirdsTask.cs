using System;

namespace AngryBirds
{
	public static class AngryBirdsTask
	{
		//  Ниже — это XML документация, её использует ваша среда разработки, 
		// чтобы показывать подсказки по использованию методов. 
		// Но писать её естественно не обязательно.
		/// <param name="v">Начальная скорость</param>
		/// <param name="distance">Расстояние до цели</param>
		/// <returns>Угол прицеливания в радианах от 0 до Pi/2</returns>
		public static double FindSightAngle(double v, double distance)
		{// L = v*v*sin(2a)/g
         //sin(2a)=L*g/(v*v)
         //2*sin(a)*cos(a)=...
         //
         //return Math.PI / 4;
            return (Math.Asin((distance * 9.8) / (v * v)))/2;
		}
	}
}
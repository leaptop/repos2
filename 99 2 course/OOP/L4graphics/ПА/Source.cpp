#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <time.h>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace sf;
using namespace std;

class pix
{
protected:
	int c;
	int x = 0;
	int dx = 1;
public:
	pix()
	{
		c = 0;
	}
	void pixel(RenderWindow &app, int n)
	{
		int posx = x + 50;
		if (n == 2) move1(posx, x, dx);
		else if (n == 1) movecir(c);
		else
		{
			move1(posx, x, dx);
			movecir(c);
		}
		const Vector2f pixelRadius = { 2.f, 2.f };
		int pointCount = 4;
		ConvexShape pixel;
		pixel.setPosition(posx, 50);
		pixel.setRotation(c);
		pixel.setFillColor(Color(0x0, 0x0, 0xEE, 255));

		pixel.setPointCount(pointCount);
		for (int pointNo = 0; pointNo < pointCount; ++pointNo)
		{
			float angle = float(2 * 3.14 * pointNo) / float(pointCount);
			Vector2f point = {
				pixelRadius.x * std::sin(angle), pixelRadius.y * std::cos(angle)
			};
			pixel.setPoint(pointNo, point);
		}
		app.draw(pixel);
	}
	void movecir(int &c)
	{
		if (c < 360) c++;
		else c = 0;
	}
	void move1(int& pos, int &x, int &dx)
	{
		int tmp;
		if (pos >= 1024) {
			dx = -1;
		}
		if (pos <= 0) {
			dx = 1;
		}
		pos += dx;
		x += dx;

	}

};

class ellips : public pix
{
private:
	int x = 0;
	int dx = 1;
public:
	ellips() :pix()
	{}
	void ellip(RenderWindow &app, int n)
	{
		pix Pix;
		int posx = x + 150;
		if (n == 2) Pix.move1(posx, x, dx);
		else if (n == 1) Pix.movecir(c);
		else
		{
			Pix.move1(posx, x, dx);
			Pix.movecir(c);
		}
		const Vector2f ellipsRadius = { 40.f, 20.f };
		int pointCount = 200;
		ConvexShape ellip;
		ellip.setPosition(posx, 50);
		ellip.setRotation(c);
		ellip.setFillColor(Color(0xFF, 0x0, 0x99, 255));

		ellip.setPointCount(pointCount);
		for (int pointNo = 0; pointNo < pointCount; ++pointNo)
		{
			float angle = float(2 * 3.14 * pointNo) / float(pointCount);
			Vector2f point = {
				ellipsRadius.x * std::sin(angle), ellipsRadius.y * std::cos(angle)
			};
			ellip.setPoint(pointNo, point);
		}
		app.draw(ellip);
	}
};
class rhombic :
	public pix
{
private:
	int x = 0;
	int dx = 1;
public:
	rhombic() :pix()
	{}
	void rhomb(RenderWindow &app, int n)
	{
		pix Pix;
		int posx = x + 250;
		if (n == 2) Pix.move1(posx, x, dx);
		else if (n == 1) Pix.movecir(c);
		else
		{
			Pix.move1(posx, x, dx);
			Pix.movecir(c);
		}
		const Vector2f rhombRadius = { 40.f, 20.f };
		int pointCount = 4;
		ConvexShape rhomb;
		rhomb.setPosition(posx, 50);
		rhomb.setRotation(90 + c);
		rhomb.setFillColor(Color(0xFF, 0xDD, 0x99, 255));

		rhomb.setPointCount(pointCount);
		for (int pointNo = 0; pointNo < pointCount; ++pointNo)
		{
			float angle = float(2 * 3.14 * pointNo) / float(pointCount);
			Vector2f point = {
				rhombRadius.x * std::sin(angle), rhombRadius.y * std::cos(angle)
			};
			rhomb.setPoint(pointNo, point);
		}
		app.draw(rhomb);
	}
};

class square : public pix
{
private:
	int x = 0;
	int dx = 1;
public:
	square() :pix()
	{}
	void squ(RenderWindow &app, int n)
	{
		int posx = x + 350;
		pix Pix;
		if (n == 2) Pix.move1(posx, x, dx);
		else if (n == 1) Pix.movecir(c);
		else
		{
			Pix.move1(posx, x, dx);
			Pix.movecir(c);
		}
		const Vector2f squRadius = { 40.f, 40.f };
		int pointCount = 4;
		ConvexShape squ;
		squ.setPosition(x + 350, 50);
		squ.setRotation(45 + c);
		squ.setFillColor(Color(0x0, 0xCC, 0xEE, 255));

		squ.setPointCount(pointCount);
		for (int pointNo = 0; pointNo < pointCount; ++pointNo)
		{
			float angle = float(2 * 3.14 * pointNo) / float(pointCount);
			Vector2f point = {
				squRadius.x * std::sin(angle), squRadius.y * std::cos(angle)
			};
			squ.setPoint(pointNo, point);
		}
		app.draw(squ);
	}
};

class trigle : public pix
{
private:
	int x = 0;
	int dx = 1;
public:
	trigle() :pix()
	{}
	void trig(RenderWindow &app, int n)
	{
		pix Pix;
		int posx = x + 450;
		if (n == 2) Pix.move1(posx, x, dx);
		else if (n == 1) Pix.movecir(c);
		else
		{
			Pix.move1(posx, x, dx);
			Pix.movecir(c);
		}
		const Vector2f trigRadius = { 40.f, 40.f };
		int pointCount = 3;
		ConvexShape trig;
		trig.setPosition(x + 450, 50);
		trig.setRotation(180 + c);
		trig.setFillColor(Color(0x0, 0xEE, 0x88, 255));

		trig.setPointCount(pointCount);
		for (int pointNo = 0; pointNo < pointCount; ++pointNo)
		{
			float angle = float(2 * 3.14 * pointNo) / float(pointCount);
			Vector2f point = {
				trigRadius.x * std::sin(angle), trigRadius.y * std::cos(angle)
			};
			trig.setPoint(pointNo, point);
		}
		app.draw(trig);
	}
};
class circle : public pix
{
private:
	int x = 0;
	int dx = 1;
public:
	circle() :pix()
	{}
	void circ(RenderWindow &app, int n)
	{
		pix Pix;
		int posx = 550 + x;
		if (n == 2) Pix.move1(posx, x, dx);
		else if (n == 1) Pix.movecir(c);
		else
		{
			Pix.move1(posx, x, dx);
			Pix.movecir(c);
		}
		const Vector2f circRadius = { 40.f, 41.f };
		int pointCount = 60;
		ConvexShape circ;
		circ.setPosition(posx, 50);
		circ.setRotation(c);
		circ.setFillColor(Color(0x88, 0xEE, 0x88, 255));

		circ.setPointCount(pointCount);
		for (int pointNo = 0; pointNo < pointCount; ++pointNo)
		{
			float angle = float(2 * 3.14 * pointNo) / float(pointCount);
			Vector2f point = {
				circRadius.x * std::sin(angle), circRadius.y * std::cos(angle)
			};
			circ.setPoint(pointNo, point);
		}
		app.draw(circ);
	}
};
class section : public pix
{
private:
	int x = 0;
	int dx = 1;
public:
	section() :pix()
	{}
	void sect(RenderWindow &app, int n)
	{
		pix Pix;
		int posx = x + 650;
		if (n == 2) Pix.move1(posx, x, dx);
		else if (n == 1) Pix.movecir(c);
		else
		{
			Pix.move1(posx, x, dx);
			Pix.movecir(c);
		}
		const Vector2f sectRadius = { 40.f, 1.f };
		int pointCount = 4;
		ConvexShape sect;
		sect.setPosition(x + 650, 50);
		sect.setRotation(c);
		sect.setFillColor(Color(0x0, 0xEE, 0x88, 255));

		sect.setPointCount(pointCount);
		for (int pointNo = 0; pointNo < pointCount; ++pointNo)
		{
			float angle = float(2 * 3.14 * pointNo) / float(pointCount);
			Vector2f point = {
				sectRadius.x * std::sin(angle), sectRadius.y * std::cos(angle)
			};
			sect.setPoint(pointNo, point);
		}
		app.draw(sect);
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	pix Pix;
	rhombic Rhombic;
	ellips Ellips;
	square Square;
	trigle Trigle;
	section Section;
	circle Circle;

	Font font;
	font.loadFromFile("BuxtonSketch.ttf");
	RenderWindow app(VideoMode(1024, 512), "OOP");
	app.setFramerateLimit(60);
	int n;
	cout << "Выберите нужный пункт: \n1.Вращение вокруг центра фигуры \n2.Прямолинейное движение \n3.Ехать и крутиться\n";
	cin >> n; cout << endl;

	while (app.isOpen())
	{
		Event e;

		while (app.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				app.close();
		}

		app.clear(sf::Color::Black);
		Pix.pixel(app, n);
		Square.squ(app, n);
		Circle.circ(app, n);
		Section.sect(app, n);
		Trigle.trig(app, n);
		Rhombic.rhomb(app, n);
		Ellips.ellip(app, n);
		app.display();
	}
	system("pause");
	return 0;
}

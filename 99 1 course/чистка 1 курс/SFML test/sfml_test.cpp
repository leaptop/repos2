#include<SFML\Graphics.hpp>

int main() {
	using namespace sf;

	RenderWindow window(VideoMode(200, 200), "SFML test 2", Style::Close);
	CircleShape shape(100.f);
	shape.setFillColor(Color::Yellow);

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}
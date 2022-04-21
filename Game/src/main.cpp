#include "SFML/Graphics.hpp"
#include "Engine/src/Test.h"

int main()
{
	engine::hello();

	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Engine");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
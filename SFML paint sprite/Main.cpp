#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	sf::Texture	tex;
	if (!tex.create(window.getSize().x, window.getSize().y))
	{
		cout << "Cannot create texture" << endl;
	}

	sf::Uint8* pixels = new sf::Uint8[window.getSize().x * window.getSize().y * 4];

	srand(time(NULL));

	for (unsigned long i = 0; i < window.getSize().x * window.getSize().y * 4; i += 4)
	{
		pixels[i + 0] = rand() % 255 + 1;
		pixels[i + 1] = rand() % 255 + 1;
		pixels[i + 2] = rand() % 255 + 1;
		pixels[i + 3] = 255;
	}

	
	tex.update(pixels);

	sf::Sprite sprite;
	sprite.setTexture(tex);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.display();

		for (unsigned long i = 0; i < window.getSize().x * window.getSize().y * 4; i += 4)
		{
			pixels[i + 0] = rand() % 255 + 1;
			pixels[i + 1] = rand() % 255 + 1;
			pixels[i + 2] = rand() % 255 + 1;
			pixels[i + 3] = 255;
		}
		tex.update(pixels);
	}

	delete pixels;

	return 0;
}
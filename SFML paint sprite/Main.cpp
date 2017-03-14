#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "HSL.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	sf::Texture	tex;
	if (!tex.create(window.getSize().x, window.getSize().y))
	{
		cout << "Cannot create texture" << endl;
	}

	unsigned long long pixelsSize = window.getSize().x * window.getSize().y * 4;
	sf::Uint8* pixels = new sf::Uint8[pixelsSize];

	srand(time(NULL));

	sf::Sprite sprite;
	sprite.setTexture(tex);

	HSL hsl;

	hsl = TurnToHSL(sprite.getColor());
	hsl.Saturation = 1;

	sprite.setColor(hsl.TurnToRGB());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		for (unsigned long i = 0; i <pixelsSize; i += 4)
		{
			pixels[i + 0] = rand() % 255 + 1;
			pixels[i + 1] = rand() % 255 + 1;
			pixels[i + 2] = rand() % 255 + 1;
			pixels[i + 3] = 255;
		}


		tex.update(pixels);

		window.clear();
		window.draw(sprite);
		window.display();
	}

	delete pixels;

	return 0;
}
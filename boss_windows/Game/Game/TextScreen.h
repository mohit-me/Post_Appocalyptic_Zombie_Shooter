#pragma once;
#include "SFML/Graphics.hpp"

class TextScreen : public sf::Drawable
{
private:
	static int counter;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Texture texture2;
	sf::Sprite sprite2;

	sf::Text text;

public:

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void initialise(sf::Image _image, int foo);
	void display(sf::RenderWindow &window);
};
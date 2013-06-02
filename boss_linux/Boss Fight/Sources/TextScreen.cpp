#include "TextScreen.h"

int TextScreen::counter = 0;

void TextScreen::initialise(sf::Image _image, int foo)
{
	image = _image;
	texture.loadFromImage(image);
	sprite.setTexture(texture);

	texture2.loadFromFile("Resources/Transparent.png");
	sprite2.setTexture(texture2);


	switch(foo)
	{
	case 0:
		text.setString("This is your final hour.");
		text.setPosition(380,300);
		break;

	case 1:
		text.setString("Why do I have a sword?");
		text.setPosition(380,300);
		break;

	case 2:
		text.setString("The Zombie is too strong...");
		text.setPosition(350,300);
		break;

	case 3:
		text.setString("Could this be the end?... I'm too young to die");
		text.setPosition(270,300);
		break;


	case 10:
		text.setString("And so humanity perished");
		text.setPosition(320,300);
		break;

	case 11:
		text.setString("or so it seemed");
		text.setPosition(320,340);
		break;

	case 12:
		text.setString("To be continued");
		text.setPosition(320,380);
		break;

	}

	counter++;
	text.setCharacterSize(24);


}




void TextScreen::display(sf::RenderWindow &window)
{
	sf::Event current_event;

	while(true)
	{
		while(window.pollEvent(current_event))
		{
			switch(current_event.type)
			{
			case sf::Event::Closed:
			case sf::Event::KeyPressed:
			case sf::Event::MouseButtonPressed:
				return;
			}
		}

		window.clear();
		window.draw(*this);
		window.display();

	}
}



void TextScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite);
	target.draw(sprite2);
	target.draw(text);

}
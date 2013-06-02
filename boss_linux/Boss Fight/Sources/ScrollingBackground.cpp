#include "ScrollingBackground.h"
#include <iostream>


void ScrollingBackground::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite1);
	target.draw(sprite2);
}


void ScrollingBackground::update()
{
	
	switch(scrolling_type)
	{
	case Horizontal:
		{
			if(counter > size.x)
				counter = 0;

			sprite1.setPosition(0,0);
			sprite1.setTextureRect(sf::Rect<int>(counter, 0, size.x, size.y));
			sprite2.setPosition((float)(window_size.x - counter), 0);
			sprite2.setTextureRect(sf::Rect<int>(0, 0, counter, size.y));
			break;
		}

	case Vertical:
		{
			if(counter > size.y)
				counter = 0;
			sprite1.setPosition(0,700);
			sprite1.setTextureRect(sf::Rect<int>(0, counter, size.x, size.y));
			sprite2.setPosition(0,700 + (float)window_size.y-counter);
			sprite2.setTextureRect(sf::Rect<int>(0, 0, size.x, counter));
			break;
		}
	}
	//std::cout<<"P"<<scrolling_type<<"p";
	counter++;
}


void ScrollingBackground::initialise(const std::string &filename, sf::RenderWindow &window, float _period)
{
	counter = 0;
	texture.loadFromFile(filename);
	period = _period;
	size = texture.getSize();
	window_size = window.getSize();

	sprite1.setTexture(texture);
	sprite2.setTexture(texture);

	sprite1.setPosition(sf::Vector2<float>(0,0));
	sprite2.setPosition(sf::Vector2<float>(0,0));

	scrolling_type = Horizontal;
}


void ScrollingBackground::setScrollingType(ScrollingBackground::Scrolling_Type _type)
{
	scrolling_type = _type;
}


void ScrollingBackground::setPeriod(float _period)
{
	period = _period;
}
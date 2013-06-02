#include "AnimatedTexture.h"
#include<iostream>

//This function is never called explicitly
void Animation::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite,states);
}

void Animation::setScale(float factor_x, float factor_y)
{
	sprite.setScale(factor_x, factor_y);
}

sf::Rect<float> Animation::getBoundingRectangle()
{
	sf::FloatRect a = sprite.getGlobalBounds();
	a.width /= dimension.x;
	a.height /= dimension.y;
	return a;
}


void Animation::update(int row_to_be_drawn)
{
	//static float time = 0;	//Time is synced for all animations
	//static int counter = 0;

	if(time > period)
		time = clock.restart().asSeconds();
	else
		time = clock.getElapsedTime().asSeconds();

	counter = frame_size.x * (int)(time * dimension.x / period);
	//std::cout<<counter<<std::endl;
	//std::cout<<counter<<","<<(row_to_be_drawn - 1) * frame_size.y<<","<<frame_size.x + counter-1<<","<<row_to_be_drawn * frame_size.y-1<<std::endl;
	
	sprite.setTextureRect(
		sf::Rect<int>
			(
				sf::Vector2<int>(counter,(row_to_be_drawn - 1) * frame_size.y), 
				frame_size
			)			
						);
}


void Animation::initialise(const std::string &filename, sf::Vector2<float> _position, float _period, int row, int column)
{
	
	texture.loadFromFile(filename);
	sprite.setTexture(texture);
	period = _period;
	dimension = sf::Vector2<int>(column, row);
	frame_size = sf::Vector2<int>(texture.getSize().x / dimension.x, texture.getSize().y / dimension.y);
	
	//std::cout<<frame_size.x<<std::endl<<frame_size.y;
	//std::cout<<std::endl<<std::endl<<dimension.x<<std::endl<<dimension.y;

	time = 0;
	counter =0;

	position = _position;
	setPosition(position);
	//sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
}


void Animation::setAnimationDuration(float _period)
{
	period = _period;
}


void Animation::setPosition(sf::Vector2<float> _position)
{
	sprite.setPosition(_position);
}
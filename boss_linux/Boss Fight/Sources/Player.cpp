#include "Player.h"
#include <iostream>

void Player::initialise()
{
	position = sf::Vector2<float>(200,500);
	animation.initialise("Resources/Player.png", position, 0.7f, 4, 6);
	attack.initialise("Resources/Attack.png", position, 0.5f, 1, 5);

	bounding_rect = animation.getBoundingRectangle();

		/*sf::FloatRect a=bounding_rect;
#undef left
	std::cout<<(a.left)<<std::endl<<a.top<<std::endl<<a.width<<std::endl<<a.height;
#define left true*/

	health = 2500;
	damage = 26.7f;
	movement_speed = 20;
	facing = right;

	player_state = Nothing;
}

void Player::update(sf::Vector2<float> _target, sf::Rect<float> target_rect, float &target_health)
{
	facing = (position.x > _target.x) ? left : right;


	if(bounding_rect.intersects(target_rect))
		if(facing == left)
			setRelativePosition(sf::Vector2<float>(+getMovementSpeed(),0));
		else	
			setRelativePosition(sf::Vector2<float>(-getMovementSpeed(),0));

	if(player_state != Attacking)
		animation.update(player_state);
	else
	{attack.update();target_health--;}

	if(facing == left)
		animation.setScale(1.0f,1.0f);
	else	
		animation.setScale(1.0f,1.0f);

	animation.setPosition(position);
	attack.setPosition(position);
}


void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if(player_state != Attacking)
		target.draw(animation);
	else
		target.draw(attack);
};


sf::Vector2<float> Player::getPosition()
{
	return position;
}

float Player::getMovementSpeed()
{
	return movement_speed;
}

void Player::setPosition(sf::Vector2<float> _position)
{
	position = _position;
}

void Player::setRelativePosition(sf::Vector2<float> _position)
{
	position += _position;
}

void Player::setState(PlayerState state)
{
	player_state = state;
}

float Player::getHealth()
{
	return health;
}
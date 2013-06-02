#include "Boss.h"
#include "HelperFunctions.h"
#include <iostream>

void Boss::initialise()
{
	position = sf::Vector2<float>(600, 470);
	animation.initialise("Resources/Boss.png", position, 0.75f, 5, 5);
	
	facing = left;
	health = 1000;
	melee_damage = 26.7f;
	jump_damage = 50;
	//attack_speed = 0.5f;
	movement_speed = 0.6f;

	bounding_rect = animation.getBoundingRectangle();
/*	sf::FloatRect a=bounding_rect;
#undef left
	std::cout<<(a.left)<<std::endl<<a.top<<std::endl<<a.width<<std::endl<<a.height;
#define left true*/
	boss_state = Moving;
}

void Boss::update(sf::Vector2<float> _target, sf::Rect<float> target_rect, float &target_health)
{

	facing = (position.x > _target.x) ? left : right;
	float diff = distance(position, _target);
	//std::cout<<diff<<std::endl<<boss_state<<std::endl;

	switch(boss_state)
	{
	case Nothing: 
		{
			static int counter = 0;counter++;
			if(counter == 1000)
			{
				boss_state = Moving;
				counter=0;
			}
			break;
		}

	case Jumping: 
		{
			if(diff > 140 && diff < 200)
				if (facing == left)
					position.x -= movement_speed;
				else
					position.x += movement_speed;
			else if(diff <= 140)
				boss_state = Moving;

			break;
		}

	case Dying:
		break;

	case Moving:
		{
			if(bounding_rect.intersects(target_rect))
				if(facing == left)
					position.x += movement_speed;
				else
					position.x -= movement_speed;
			else 
			 if (diff >= 200)
				if (facing == left)
					position.x -= movement_speed;
				else
					position.x += movement_speed;
			else if (diff >= 140 && diff < 200)
				boss_state = Jumping;
			else 
				boss_state = Attacking;
			
			break;
		}
	
	case Attacking: 
		{
			target_health--;
			static int counter = 0;
			counter++;
			if(counter == 1000)
			{
				boss_state = Moving;
				counter = 0;
			}
			break;
		}


	} //End of switch case

	if(facing == left)
		animation.setScale(1.0f,1.0f);
	else	
		animation.setScale(1.0f,1.0f);

	animation.update(boss_state);
	animation.setPosition(position);
}


void Boss::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(animation);
};


sf::Vector2<float> Boss::getPosition()
{
	return position;
}


void Boss::setPosition(sf::Vector2<float> _position)
{
	position = _position;
}

void Boss::setState(BossState state)
{
	boss_state = state;
}
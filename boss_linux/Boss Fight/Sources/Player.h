#pragma once;
#include "SFML/Graphics.hpp"
#include "AnimatedTexture.h"

#define left true
#define right false

class Player : public sf::Drawable
{
public:
	enum PlayerState 
	{Moving = 1, Nothing, Jumping, Dead, Attacking};

	bool facing;

	//Member Functions
	void initialise();
	void update(sf::Vector2<float> _target, sf::Rect<float> target_rect, float &target_health);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::Vector2<float> getPosition();
	float getMovementSpeed();
	float getHealth();
	void changeHealth(float a)
	{health += a;}

	void setState(PlayerState state);
	void setPosition(sf::Vector2<float> _position);
	void setRelativePosition(sf::Vector2<float> _position);

	//Variables

	PlayerState player_state;
	//PlayerState old_state;
	sf::Vector2<float> position;
	sf::Rect<float> bounding_rect;

	float health;

private:
	//Attributes and Stats
	
	float damage;
	//float attack_speed;
	float movement_speed;
	Animation animation;
	Animation attack;
	


};
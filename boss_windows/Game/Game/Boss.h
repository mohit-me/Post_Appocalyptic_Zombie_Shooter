#pragma once;
#include "SFML/Graphics.hpp"
#include "AnimatedTexture.h"

#define left true
#define right false

class Boss : public sf::Drawable
{
public:
	enum BossState 
	{Nothing = 1, Moving, Jumping, Dying, Attacking};

	bool facing;

	//Member Functions
	void initialise();
	void update(sf::Vector2<float> _target, sf::Rect<float> target_rect, float &target_health);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::Vector2<float> getPosition();
	void setPosition(sf::Vector2<float> _position);
	void setState(BossState state);
	float getHealth()
	{return health;}
	void changeHealth(float a)
	{health += a;}


	//Variables
	BossState boss_state;
	sf::Vector2<float> position;
	sf::Rect<float> bounding_rect;
	float health;

private:
	//Attributes and Stats

	float melee_damage;
	float jump_damage;
	//float attack_speed;
	float movement_speed;
	Animation animation;

};
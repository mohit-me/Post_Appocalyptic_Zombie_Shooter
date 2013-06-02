#pragma once;
#include "SFML/Graphics.hpp"

class Animation : public sf::Drawable
{
private:

	//Sprites, Textures and Images
	sf::Texture texture;
	sf::Sprite sprite;	

	//Timing
	sf::Clock clock;
	float period;
	float time;
	int counter;

	//Attributes of the sprite sheet
	sf::Vector2<int> frame_size; //Size of each frame
	sf::Vector2<int> dimension;  //It's complicated
	sf::Vector2<float> position; //Could be merged with sf::Sprites inherent position

public:

	//This function is never called explicitly
	//It is called whenever an object of the Animation class is passed to the
	//main windows draw function
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	//These functions must always be called	
	void update(int row_to_be_drawn = 1);
	void initialise(const std::string &filename, sf::Vector2<float> _position, float period, int row, int column);
	
	//Other useful functions
	void setAnimationDuration(float _period);
	void setPosition(sf::Vector2<float> _position);
	void setScale(float factor_x, float factor_y);
	sf::Rect<float> getBoundingRectangle();

};
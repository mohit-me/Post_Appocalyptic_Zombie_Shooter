#pragma once;
#include "SFML/Graphics.hpp"

class ScrollingBackground : public sf::Drawable
{
public:

	enum Scrolling_Type {Horizontal, Vertical};

private:
	int counter;
	sf::Texture texture;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	Scrolling_Type scrolling_type;
	sf::Vector2<unsigned int> size;
	sf::Vector2<unsigned int> window_size;
	float period;

public:
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update();
	void initialise(const std::string &filename, sf::RenderWindow &window, float period);
	void setScrollingType(Scrolling_Type type);
	void setPeriod(float _period);

};

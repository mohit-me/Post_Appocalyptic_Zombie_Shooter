#pragma once;
#include "SFML/Graphics.hpp"
#include <list>

class PauseMenu : public sf::Drawable
{
public:

	enum Menu_Result {Resume, Exit};

	//Functions
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void initialise(sf::Image _image);
	Menu_Result display(sf::RenderWindow &window);

private:
	
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Texture texture2;
	sf::Sprite sprite2;

	sf::Texture texture3;
	sf::Sprite sprite3;

	struct Menu_Item
	{
		sf::Rect<int> rect;
		Menu_Result action;
	};

	std::list<Menu_Item> menu_items;

	Menu_Result handleClick(int x, int y);

};
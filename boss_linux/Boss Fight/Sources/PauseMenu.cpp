#include "PauseMenu.h"
#include "AnimatedTexture.h"
#include <iostream>

void PauseMenu::initialise(sf::Image _image)
{
	image = _image;
	texture.loadFromImage(image);
	sprite.setTexture(texture);

	texture2.loadFromFile("Resources/Transparent.png");
	sprite2.setTexture(texture2);

	texture3.loadFromFile("Resources/PauseMenu.png");
	sprite3.setTexture(texture3);
	sprite3.setPosition(128,96);

	Menu_Item resume_button;
	resume_button.rect.left = 128;
	resume_button.rect.top= 96;
	resume_button.rect.width = 786;
	resume_button.rect.height = 288;
	resume_button.action = Resume;

	//Exit menu item coordinates
	Menu_Item exit_button;
	exit_button.rect.left = 128;
	exit_button.rect.top = 384;
	exit_button.rect.width = 786;
	exit_button.rect.height = 288;
	exit_button.action = Exit;

	menu_items.push_back(resume_button);
	menu_items.push_back(exit_button);

}

void PauseMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite);
	target.draw(sprite2);
	target.draw(sprite3);
}

PauseMenu::Menu_Result PauseMenu::display(sf::RenderWindow &window)
{
	sf::Event current_event;

	while(true)
	{
		while(window.pollEvent(current_event))
		{
			switch(current_event.type)
			{
			case sf::Event::Closed:
				return Exit;
				break;
			case sf::Event::MouseButtonPressed:
				if(current_event.mouseButton.x >= 128 
					&& current_event.mouseButton.x < 896
					&& current_event.mouseButton.y >= 96
					&& current_event.mouseButton.y < 672)
				return handleClick(current_event.mouseButton.x, current_event.mouseButton.y);
				break;
			}
		}

		window.clear();
		window.draw(*this);
		window.display();

	}
}

PauseMenu::Menu_Result PauseMenu::handleClick(int x, int y)
{
	std::list<Menu_Item>::iterator it;
	
	//std::cout<<","<<x<<","<<y<<",";
    for(it = menu_items.begin(); it != menu_items.end(); it++)
	{
		if((*it).rect.contains(x,y))
       {
         return (*it).action;
       }
	}
}
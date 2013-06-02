#include "Game.h"
#include "TextScreen.h"
#include "PauseMenu.h"
#include <iostream>

sf::RenderWindow Game::main_window;
Game::Game_State Game::game_state = Uninitialised;
Player Game::player;
Boss Game::boss;
ScrollingBackground Game::sewer;
ScrollingBackground Game::water;

sf::Texture Game::bgtexture;
sf::Sprite Game::background;

sf::Music Game::music;


void Game::start()
{
	while(true)
	{
		gameLoop();
	}
}


void Game::initialise()
{	
	main_window.create(sf::VideoMode(1024,768,32),"Zodiark");
	//main_window.setFramerateLimit(60);
	game_state = Game::Playing;   //Menu and Splashscreen disabled for now

	player.initialise();
	boss.initialise();

	bgtexture.loadFromFile("Resources/bg2.png");
	background.setTexture(bgtexture);

	sewer.initialise("Resources/bg.png", main_window, 5.0f);
	water.initialise("Resources/water.png", main_window, 5.0f);
	water.setScrollingType(ScrollingBackground::Vertical);

	music.openFromFile("Resources/UT.ogg");
	music.setLoop(true);
	music.play();


}

void Game::gameStateManager()
{
	switch(game_state)
	{
	case Uninitialised:
		initialise();
		break;

	case ShowingText:
		//showTextScreen();
		break;

	case Paused:
		showPauseMenu();
		break;

	case Playing:
		if(player.getHealth() == 2499)
					{showTextScreen(0);player.changeHealth(-1);}
		else if(player.getHealth() == 2199)
					{showTextScreen(1);player.changeHealth(-1);}
		else if(player.getHealth() == 1799)
					{showTextScreen(2);player.changeHealth(-1);}
		else if(player.getHealth() == 1099)
					{showTextScreen(3);player.changeHealth(-1);}
		else if(player.getHealth() == 35)
					{player.setState(Player::Dead);}

		eventHandler();
		draw();
		break;

	case Exiting:
		showTextScreen(10);
		showTextScreen(11);
		showTextScreen(12);
		music.stop();
		main_window.close();
		break;
	
	}
}

void Game::eventHandler()
{
	if(player.health <= 0 ||boss.health <= 0)
		game_state = Exiting;

	static sf::Event current_event;

	while(main_window.pollEvent(current_event))
	{
		switch(current_event.type)
		{
		case sf::Event::Closed:
			game_state = Exiting;
			break;

		case sf::Event::LostFocus:
			game_state = Paused;
			break;

		case sf::Event::KeyReleased:
			if(player.player_state != Player::Dead)
				player.setState(Player::Nothing);
			break;

		case sf::Event::KeyPressed:
			{
				switch(current_event.key.code)
				{
				case sf::Keyboard::Escape:
					game_state = Paused;
					break;

				case sf::Keyboard::D:
					player.setRelativePosition(sf::Vector2<float>(player.getMovementSpeed(),0));
					player.setState(Player::Moving);
					break;

				case sf::Keyboard::A:
					player.setRelativePosition(sf::Vector2<float>(-player.getMovementSpeed(),0));
					player.setState(Player::Moving);
					break;

				case sf::Keyboard::Return:
					player.setState(Player::Attacking);
					break;

				case sf::Keyboard::W:
					player.setState(Player::Jumping);
					break;

				case sf::Keyboard::Space:
					player.setState(Player::Jumping);
					break;
				}//Inner switch ends here
				break;
			}
		}//Outer switch ends here
	}//End of while loop
}

void Game::gameLoop()
{
	gameStateManager();
}


void Game::draw()
{
	main_window.clear();

	player.update(boss.position, boss.bounding_rect, boss.health);
	boss.update(player.position, player.bounding_rect, player.health);
	sewer.update();
	water.update();

	main_window.draw(sewer);
	main_window.draw(background);
	main_window.draw(water);

	main_window.draw(player);
	main_window.draw(boss);

	main_window.display();
}

void Game::showTextScreen(int foo)
{
	//music.pause();
	TextScreen text;
	text.initialise(main_window.capture(), foo);
	text.display(main_window);
	//music.play();
	game_state = Playing;
}


void Game::showPauseMenu()
{
	PauseMenu menu;
	menu.initialise(main_window.capture());
	PauseMenu::Menu_Result result = menu.display(main_window);

	switch(result)
	{
	case PauseMenu::Exit:
		game_state = Exiting;
		std::cout<<"2";
		break;

	case PauseMenu::Resume:
		game_state = Playing;
		std::cout<<"1";
		break;
	}
}
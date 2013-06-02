#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Player.h"
#include "Boss.h"
#include "ScrollingBackground.h"

class Game
{
public:
	static void start();
	static Player player;
	static Boss boss;
	static ScrollingBackground sewer;
	static ScrollingBackground water;
	static sf::Texture bgtexture;
	static sf::Sprite background;
	static sf::Music music;

private:
	static void gameLoop();

	static void showPauseMenu();
	static void showTextScreen(int foo);
	//static void playGame();
	//Possibly needs a screen manager -> (1)

	static void initialise();
	//static void update();
	static void eventHandler();
	static void gameStateManager(); //Even Better //From (1)
	static void draw();

	enum Game_State
	{
		Uninitialised, ShowingText, Paused, Playing, Exiting
	};

	static Game_State game_state;
	static sf::RenderWindow main_window;
};
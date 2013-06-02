#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include "AIHandler.h"
#include "CollisionManager.h"
#include "DrawEngine.h"
#include "enemies/Zombie.h"
#include "enemies/HeadEater.h"
#include "InputEngine.h"
#include "KeyAction.h"
#include "MovableObject.h"
#include "Text.h"
#include "WorldObject.h"
#include "Map.h"
#include "Projectile.h"
#include "enemies/SpawnHandler.h"

#ifndef GAME_H_
#define GAME_H_

/* Main game class*/
class Game {
public:
	/* Constructor*/
	Game();

	/* Destructor*/
	~Game();

	/* The main game loop to run the game*/
	void run();
private:
	vector<Zombie*> enemies;
	vector<Projectile*> projectiles;

	int points;
};

#endif /* GAME_H_ */

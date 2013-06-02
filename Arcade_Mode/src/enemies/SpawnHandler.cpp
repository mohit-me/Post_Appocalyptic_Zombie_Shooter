#include "SpawnHandler.h"

SpawnHandler::SpawnHandler(DrawEngine* draw_engine, CollisionManager* collision) {
	this->draw_engine = draw_engine;
	this->collision = collision;
}

SpawnHandler::~SpawnHandler() {
	//delete this->draw_engine;
	this->draw_engine = 0;

	//delete this->collision;
	this->collision = 0;
}

Zombie* SpawnHandler::spawn_enemy() {
	KeyAction* enemy_collision = new KeyAction();
	bool free_position = false;
	int x = 0, y = 0;
	int screen_width = DrawEngine::get_screen_width();
	int screen_height = DrawEngine::get_screen_height();
	int zombie_type = rand() % 2;
	Zombie* zombie;

	switch (zombie_type) {
	case 0:
		zombie = new Zombie();
		zombie->settexture("Resources/braineater.png");
		break;
	case 1:
		zombie = new HeadEater();
		zombie->settexture("Resources/headeater.png");
		break;
	}

	SDL_Surface* crack = draw_engine->load_image("Resources/crack.png");
	zombie->setcrack(crack);

	SDL_Surface* surf_zombie = draw_engine->load_image(zombie->gettexture());
	zombie->setsurface(surf_zombie);

	zombie->setmovable(true);
	zombie->setcollisionable(true);

	while (!free_position) {
		x = rand() % screen_width;
		y = rand() % screen_height;

		zombie->setx(x);
		zombie->sety(y);

		enemy_collision->player_direction |= KeyAction::LEFT;
		enemy_collision->player_direction |= KeyAction::RIGHT;
		enemy_collision->player_direction |= KeyAction::UP;
		enemy_collision->player_direction |= KeyAction::DOWN;

		enemy_collision = collision->perform_collision_detection(Map::getmap(),
				zombie, enemy_collision);

		if (((KeyAction::LEFT & enemy_collision->player_direction) == KeyAction::LEFT) &&
				((KeyAction::RIGHT & enemy_collision->player_direction) == KeyAction::RIGHT) &&
				((KeyAction::UP & enemy_collision->player_direction) == KeyAction::UP) &&
				((KeyAction::DOWN & enemy_collision->player_direction) == KeyAction::DOWN)) {
			free_position = true;
			break;
		}
	}

	free_position = false;

	delete enemy_collision;
	enemy_collision = 0;

	crack = 0;
	surf_zombie = 0;

	return zombie;
}

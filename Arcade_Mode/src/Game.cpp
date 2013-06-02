#include "Game.h"
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

const int FRAMES_PER_SECOND = 20;
const int TICKS_STOP = (1000 / FRAMES_PER_SECOND);

Game::Game() {
	this->points = 0;
}

Game::~Game() {
}

void Game::run() {
	bool running = true;

	CollisionManager* collision = new CollisionManager();
	DrawEngine* draw_engine = new DrawEngine(SCREEN_WIDTH, SCREEN_HEIGHT, 16);
	InputEngine* input_engine = new InputEngine();
	AIHandler* ai_handler = new AIHandler(collision);
	KeyAction* key_action = new KeyAction();
	SpawnHandler* spawn_handler = new SpawnHandler(draw_engine, collision);

	if (0 == draw_engine) {
		return;
	}

	Map* map = new Map(draw_engine);
	map->loadmap("test");

	MovableObject* player = new MovableObject();
	player->setx(155);
	player->sety(70);
	player->settexture("Resources/alien.png");
	player->setmovable(true);
	SDL_Surface* surf_stone = draw_engine->load_image(player->gettexture());
	player->setsurface(surf_stone);

	// points text
	std::stringstream points_out;
	std::stringstream life_out;

	Text* life_text = new Text("Life: 100", 24);
	Text* life_shaded = new Text("Life: 100", 24, 0, 0, 0);
	Text* points_text = new Text("Score: ", 24);
	Text* points_shaded = new Text("Score: ", 24, 0, 0, 0);
	Text* you_die = new Text("You die! Zombies are quite powerful, ay?", 30);
	Text* you_die_black = new Text("You die! Zombies are quite powerful, ay?", 30, 0, 0, 0);

	for (int i = 0; i < 10; i++) {
		// create enemies
		enemies.push_back(spawn_handler->spawn_enemy());
	}

	while (running) {
				//
		// Key events
		//
		key_action = input_engine->handle_event(key_action);

		if ((KeyAction::QUIT & key_action->key_event) == KeyAction::QUIT) {
			running = false;
		}
		if ((KeyAction::MOVE & key_action->key_event) == KeyAction::MOVE) {
			key_action = collision->perform_collision_detection(Map::getmap(),
					player, key_action);
			player->move(key_action);
		}
		if ((KeyAction::SHOOT & key_action->key_event) == KeyAction::SHOOT) {
			Projectile* bullet = new Projectile();
			bullet->setx(player->getx() + (player->getsurface()->w / 2));
			bullet->sety(player->gety());
			bullet->setdamage(10);
			bullet->setdirection(key_action->shoot_direction);

			projectiles.push_back(bullet);
		}

		if ((KeyAction::DEAD & key_action->key_event) != KeyAction::DEAD) {
			//
			// Remove bullets that hit world objects or got out of range
			// Also, if we killed an enemy, lets add our points
			//
			collision->perform_collision_bullet(Map::getmap(), projectiles);
			GarbageCollector::execute_collector(projectiles, enemies);

			collision->perform_bullet_hit(enemies, projectiles);

			//
			// Generate two new enemies for each enemy that is killed
			//
			int gen_enemies = GarbageCollector::get_zombie_size();

			for (int i = 0; i < gen_enemies; i++) {
				Zombie* new_zombie = spawn_handler->spawn_enemy();
				enemies.push_back(new_zombie);

				new_zombie = 0;
			}

			int points_gained = GarbageCollector::execute_collector(projectiles, enemies);
			this->points += points_gained;

			//
			// Render objects
			//
			draw_engine->draw(Map::getmap());

			vector<Zombie*>::iterator it;
			for (it = enemies.begin(); it != enemies.end(); it++) {
				ai_handler->move_object(*it, player);
				(*it)->setmovement(collision->perform_collision_detection(Map::getmap(), (*it), (*it)->getmovement()));
				(*it)->move((*it)->getmovement());
				ai_handler->clear_movement((*it));

				draw_engine->draw(*it);
			}

			draw_engine->draw(player);
			draw_engine->draw(projectiles);

			//
			// Check if an enemy touches the player
			//
			bool hit = collision->check_player_collision(enemies, player);

			if (hit) {
				player->sethealth(5);

				if (player->gethealth() <= 0) {
					// dead
					key_action->key_event |= KeyAction::DEAD;
				}
			}

			//
			// Text rendering
			//
			points_out.str(std::string());
			points_out << "Highscore: " << this->points;
			points_text->settext(points_out.str());
			points_shaded->settext(points_out.str());

			draw_engine->draw_text(points_shaded, 10, 10);
			draw_engine->draw_text(points_text, 12, 12);

			life_out.str(std::string());
			life_out << "Life: " << player->gethealth();
			life_text->settext(life_out.str());
			life_shaded->settext(life_out.str());

			draw_engine->draw_text(life_shaded, DrawEngine::get_screen_width() - 150, 10);
			draw_engine->draw_text(life_text, DrawEngine::get_screen_width() - 148, 12);
		} else {
			draw_engine->draw_text(you_die_black, 210, DrawEngine::get_screen_height() / 2 - 20);
			draw_engine->draw_text(you_die, 213, DrawEngine::get_screen_height() / 2 - 18);
		}

		draw_engine->push_screen();

	}

	SDL_Quit();

	// Clean up before we quit
	delete collision;
	delete ai_handler;
	delete draw_engine;
	delete input_engine;
	delete key_action;
	delete map;
	delete spawn_handler;

	delete life_text;
	delete life_shaded;
	delete points_text;
	delete points_shaded;
	delete you_die;
	delete you_die_black;

	life_text = 0;
	life_shaded = 0;
	points_text = 0;
	points_shaded = 0;
	you_die = 0;
	you_die_black = 0;

	collision = 0;
	draw_engine = 0;
	input_engine = 0;
	ai_handler = 0;
	key_action = 0;
	map = 0;
	spawn_handler = 0;
}

#include "CollisionManager.h"

CollisionManager::CollisionManager() :
	MAX_DISTANCE_FOR_COLLISION(30) {
	// TODO Auto-generated constructor stub
}

CollisionManager::~CollisionManager() {
	// TODO Auto-generated destructor stub
}

void CollisionManager::perform_collision_bullet(vector<WorldObject*> victims,
		vector<Projectile*> bullets) {
	vector<WorldObject*>::iterator victims_it;
	vector<Projectile*>::iterator bullets_it;

	if (bullets.size() < 1) {
		return;
	}

	if (victims.size() < 1) {
		return;
	}

	for (victims_it = victims.begin(); victims_it != victims.end(); victims_it++) {
		WorldObject* victim = (*victims_it);

		if (!victim->getcollisionable()) {
			continue;
		}

		// check collision for each bullet
		for (bullets_it = bullets.begin(); bullets_it != bullets.end(); bullets_it++) {
			Projectile* bullet = (*bullets_it);

			if ((bullet->getx() >= (victim->getx() - MAX_DISTANCE_FOR_COLLISION))
					&& (bullet->gety() >= (victim->gety() - MAX_DISTANCE_FOR_COLLISION))) {

				int bullet_min_x = bullet->getx();
				int bullet_min_y = bullet->gety();
				int bullet_max_x = bullet->getx() + bullet->getwidth();
				int bullet_max_y = bullet->gety() + bullet->getheight();

				int victim_min_x = victim->getx();
				int victim_min_y = victim->gety();
				int victim_max_x = victim->getx() + victim->getsurface()->w;
				int victim_max_y = victim->gety() + victim->getsurface()->h;

				if (((bullet_max_x > victim_min_x) &&
						(bullet_max_y > victim_min_y) &&
						(bullet_min_x < victim_max_x) &&
						(bullet_min_y < victim_max_y)) ||
						(bullet_min_x < 0 ||
								bullet_max_x > DrawEngine::get_screen_width() ||
								bullet_min_y < 0 ||
								bullet_max_y > DrawEngine::get_screen_height())) {

					// remove the bullet
					GarbageCollector::add_deletion_queue(bullet);
				}
			}

			if ((bullet->getx() > (bullet->getorgx() + 300)) ||
					(bullet->gety() > (bullet->getorgy() + 300))) {
				// if the bullet has been fired over 300 px, lets delete
				GarbageCollector::add_deletion_queue(bullet);
			}
		}
	}
}

void CollisionManager::perform_bullet_hit(vector<Zombie*> zombies, vector<Projectile*> bullets) {
	vector<Zombie*>::iterator zombie_it;
	vector<Projectile*>::iterator bullets_it;

	bool hit = false;

	for (zombie_it = zombies.begin(); zombie_it != zombies.end(); zombie_it++) {
		Zombie* zombie = (*zombie_it);

		if (!zombie->getcollisionable()) {
			continue;
		}

		if (!zombie->getrevealed() || zombie->gethidden()) {
			continue;
		}

		// check collision for each bullet
		for (bullets_it = bullets.begin(); bullets_it != bullets.end(); bullets_it++) {
			Projectile* bullet = (*bullets_it);

			if ((bullet->getx() >= (zombie->getx() - MAX_DISTANCE_FOR_COLLISION))
					&& (bullet->gety() >= (zombie->gety() - MAX_DISTANCE_FOR_COLLISION))
					&& (bullet->gety() <= (zombie->gety() + zombie->getsurface()->h))
					&& (bullet->getx() <= (zombie->getx() + zombie->getsurface()->w))) {

				int bullet_min_x = bullet->getx();
				int bullet_min_y = bullet->gety();
				int bullet_max_x = bullet->getx() + bullet->getwidth();
				int bullet_max_y = bullet->gety() + bullet->getheight();

				int zombie_min_x = zombie->getx();
				int zombie_min_y = zombie->gety();
				int zombie_max_x = zombie->getx() + zombie->getsurface()->w;
				int zombie_max_y = zombie->gety() + zombie->getsurface()->h;

				if ((bullet_min_x > zombie_min_x) &&
						(bullet_max_x < zombie_max_x) &&
						(bullet_min_y > zombie_min_y) &&
						(bullet_max_y < zombie_max_y)) {
					hit = true;
				}
			}

			if (hit) {
				// remove the bullet
				if (zombie->getrevealed() && !zombie->gethidden()) {
					zombie->setdamage(bullet->getdamage());

					if (zombie->gethealth() <= 0) {
						GarbageCollector::add_deletion_queue(zombie);
					}

					GarbageCollector::add_deletion_queue(bullet);
				}

				hit = false;
			}
		}

		zombie = 0;
	}
}

KeyAction* CollisionManager::perform_collision_detection(
		vector<WorldObject*> victims, MovableObject* ai, KeyAction* key_action) {
	vector<WorldObject*>::iterator it;

	// loop through all objects in the world, and detect a collision (if one exists)
	for (it = victims.begin(); it != victims.end(); it++) {
		WorldObject* victim = *it;

		if (!victim->getcollisionable())
			continue;

		if (((ai->getx() >= (victim->getx() - MAX_DISTANCE_FOR_COLLISION))
				&& (ai->gety() >= (victim->gety() - MAX_DISTANCE_FOR_COLLISION)))
				|| (ai->getx() < 0)
				|| (ai->gety() < 0)
				|| ((ai->getx() + ai->getsurface()->w) > DrawEngine::get_screen_width())
				|| ((ai->gety() + ai->getsurface()->h) > DrawEngine::get_screen_height())) {

			// get the size and position of victim
			int victim_height = victim->getsurface()->h;
			int victim_width = victim->getsurface()->w;

			int victim_max_x = victim->getx() + victim_width;
			int victim_max_y = victim->gety() + victim_height;

			int ai_min_x = ai->getx();
			int ai_min_y = ai->gety();
			int ai_max_x = ai->getx() + ai->getsurface()->w;
			int ai_max_y = ai->gety() + ai->getsurface()->h;

			if ((((ai_max_x > victim->getx())
					&& (ai_min_x < victim_max_x)
					&& (ai_max_y > victim->gety())
					&& (ai_min_y < victim_max_y)))
					|| ((ai_min_x < 0)
					|| (ai_max_x > DrawEngine::get_screen_width())
					|| (ai_min_y < 0)
					|| (ai_max_y > DrawEngine::get_screen_height()))) {

				// we have a collision
				if ((((ai_max_x > (victim->getx() + ai->getmovespeed()))
						&& ((ai_min_y < (victim_max_y - ai->getmovespeed()))
						&& (ai_max_y > (victim->gety() + ai->getmovespeed())))))
						|| (ai_min_x < 0)) {
					key_action->player_direction &= ~KeyAction::LEFT;
				}

				if (((ai_max_x >= victim->getx()
						&& (ai_min_x < (victim_max_x - ai->getmovespeed()))
						&& (ai_min_y < (victim_max_y - ai->getmovespeed())
						&& (ai_max_y > (victim->gety() + ai->getmovespeed())))))
						||(ai_max_x > DrawEngine::get_screen_width())) {
					key_action->player_direction &= ~KeyAction::RIGHT;
				}

				if (((ai_min_y < victim_max_y
						&& (ai_min_y > victim->gety())
						&& (ai_min_x < (victim_max_x - ai->getmovespeed())
						&& (ai_max_x > (victim->getx() + ai->getmovespeed())))))
						|| (ai_min_y < 0)) {
					key_action->player_direction &= ~KeyAction::UP;
				}

				if (((ai_max_y > victim->gety()
						&& (ai_min_y < (victim_max_y - ai->getmovespeed()))
						&& (ai_min_x < (victim_max_x - ai->getmovespeed())
						&& (ai_max_x > (victim->getx() + ai->getmovespeed())))))
						|| (ai_max_y > DrawEngine::get_screen_height())) {
					key_action->player_direction &= ~KeyAction::DOWN;
				}
			}
		}

		victim = NULL;
	}

	return key_action;
}

bool CollisionManager::check_player_collision(vector<Zombie*> zombies, MovableObject* player) {
	vector<Zombie*>::iterator it;

	for (it = zombies.begin(); it != zombies.end(); it++) {
		int zombie_min_x = (*it)->getx();
		int zombie_min_y = (*it)->gety();
		int zombie_max_x = (*it)->getx() + (*it)->getsurface()->w;
		int zombie_max_y = (*it)->gety() + (*it)->getsurface()->h;

		int player_min_x = player->getx();
		int player_min_y = player->gety();
		int player_max_x = player->getx() + player->getsurface()->w;
		int player_max_y = player->gety() + player->getsurface()->h;

		if (!(*it)->getrevealed() || (*it)->gethidden()) {
			continue;
		}

		if ((zombie_min_x >= player_min_x) &&
				(zombie_max_x <= player_max_x) &&
				(zombie_min_y >= player_min_y) &&
				(zombie_max_y <= player_max_y)) {
			return true;
		} else if ((zombie_max_x >= player_min_x) &&
				(zombie_max_x <= player_max_x) &&
				(zombie_min_y >= player_min_y) &&
				(zombie_max_y <= player_max_y)) {
			return true;
		} else if ((zombie_max_x >= player_min_x) &&
				(zombie_max_x <= player_max_x) &&
				(zombie_max_y >= player_min_y) &&
				(zombie_max_y <= player_max_y)) {
			return true;
		} else if ((zombie_max_x >= player_min_x) &&
				(zombie_max_x <= player_max_x) &&
				(zombie_min_y >= player_min_y) &&
				(zombie_min_y <= player_max_y)) {
			return true;
		} else if ((zombie_min_x >= player_min_x) &&
				(zombie_min_x <= player_max_x) &&
				(zombie_min_y >= player_min_y) &&
				(zombie_min_y <= player_max_y)) {
			return true;
		}
	}

	return false;
}

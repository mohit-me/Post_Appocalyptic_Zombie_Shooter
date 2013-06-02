#include <cmath>
#include "AIHandler.h"
#include "KeyAction.h"

AIHandler::AIHandler(CollisionManager* collision) :
	collision(collision) {
}

AIHandler::~AIHandler() {
}

void AIHandler::move_object(Zombie* zombie, WorldObject* player) {
	KeyAction* key_action = zombie->getmovement();

	int x = pow(player->getx() - zombie->getx(), 2.0);
	int y = pow(player->gety() - zombie->gety(), 2.0);
	float distance = sqrt(x + y);

	if (distance <= 300) {
		// we have "seen" the player, lets dig him up and move him towards the victim
		zombie->reveal();

		int player_x = player->getx() - zombie->getx();
		int player_y = player->gety() - zombie->gety();

		int y_off = player->getsurface()->h / 2;
		int x_off = player->getsurface()->w / 2;

		if (player_x > -2 && player_x < 2 && player_y > -2 && player_y < 2) {
		} else {
			key_action->key_event = KeyAction::MOVE;

			if ((player_x < -x_off) || (player_x > x_off))
			{
				if (player_x < 0) {
					key_action->player_direction |= KeyAction::LEFT;
				} else {
					key_action->player_direction |= KeyAction::RIGHT;
				}
			}

			if ((player_y < -y_off) || (player_y > y_off))
			{
				if (player_y < 0) {
					key_action->player_direction |= KeyAction::UP;
				} else {
					key_action->player_direction |= KeyAction::DOWN;
				}
			}
		}
	} else if (distance <= 400) {
		// show the cracks to the player
		zombie->show();
	}

	key_action = 0;
}

void AIHandler::clear_movement(Zombie* zombie) {
	zombie->getmovement()->player_direction &= ~KeyAction::LEFT;
	zombie->getmovement()->player_direction &= ~KeyAction::RIGHT;
	zombie->getmovement()->player_direction &= ~KeyAction::DOWN;
	zombie->getmovement()->player_direction &= ~KeyAction::UP;
	zombie->getmovement()->key_event &= ~KeyAction::MOVE;
}

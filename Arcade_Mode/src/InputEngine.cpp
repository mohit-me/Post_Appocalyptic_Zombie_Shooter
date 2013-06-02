#include "InputEngine.h"
#include "simple.h"
InputEngine::InputEngine() {

}

InputEngine::~InputEngine() {
	// TODO Auto-generated destructor stub
}

KeyAction* InputEngine::handle_event(KeyAction* key_action) {
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_KEYDOWN:
				switch (int(event.key.keysym.sym)) {
					case SDLK_ESCAPE:
						Start st; st.str();
						break;
					case SDLK_LEFT:
						key_action->key_event |= KeyAction::MOVE;
						key_action->player_direction |= KeyAction::LEFT;
						break;
					case SDLK_RIGHT:
						key_action->key_event |= KeyAction::MOVE;
						key_action->player_direction |= KeyAction::RIGHT;
						break;
					case SDLK_UP:
						key_action->key_event |= KeyAction::MOVE;
						key_action->player_direction |= KeyAction::UP;
						break;
					case SDLK_DOWN:
						key_action->key_event |= KeyAction::MOVE;
						key_action->player_direction |= KeyAction::DOWN;
						break;
				}

				switch (static_cast<int>(event.key.keysym.sym)) {
					case SDLK_w:
						key_action->key_event |= KeyAction::SHOOT;
						key_action->shoot_direction |= KeyAction::UP;
						break;
					case SDLK_a:
						key_action->key_event |= KeyAction::SHOOT;
						key_action->shoot_direction |= KeyAction::LEFT;
						break;
					case SDLK_s:
						key_action->key_event |= KeyAction::SHOOT;
						key_action->shoot_direction |= KeyAction::DOWN;
						break;
					case SDLK_d:
						key_action->key_event |= KeyAction::SHOOT;
						key_action->shoot_direction |= KeyAction::RIGHT;
						break;
				}
				break;
			case SDL_KEYUP:
				switch (static_cast<int>(event.key.keysym.sym)) {
					case SDLK_LEFT:
						key_action->player_direction &= ~KeyAction::LEFT;
						break;
					case SDLK_RIGHT:
						key_action->player_direction &= ~KeyAction::RIGHT;
						break;
					case SDLK_UP:
						key_action->player_direction &= ~KeyAction::UP;
						break;
					case SDLK_DOWN:
						key_action->player_direction &= ~KeyAction::DOWN;
						break;
					case SDLK_w:
						key_action->shoot_direction &= ~KeyAction::UP;
						break;
					case SDLK_a:
						key_action->shoot_direction &= ~KeyAction::LEFT;
						break;
					case SDLK_s:
						key_action->shoot_direction &= ~KeyAction::DOWN;
						break;
					case SDLK_d:
						key_action->shoot_direction &= ~KeyAction::RIGHT;
						break;
				}

				if (key_action->player_direction == 0) {
					key_action->key_event &= ~KeyAction::MOVE;
				}

				if (key_action->shoot_direction == 0) {
					key_action->key_event &= ~KeyAction::SHOOT;
				}
				break;
		}
	}

	return key_action;
}

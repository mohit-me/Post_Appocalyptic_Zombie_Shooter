#include <iostream>
#include <SDL/SDL.h>
#include "KeyAction.h"

#ifndef INPUTENGINE_H_
#define INPUTENGINE_H_

/* Handles every key press/release in the game.
 */
class InputEngine {
private:
	SDL_Event event;
public:
	/* Constructor
	 */
	InputEngine();

	/* Destructor
	 */
	~InputEngine();

	/* Handle a key event
	 */
	KeyAction* handle_event(KeyAction* key_action);
};

#endif /* INPUTENGINE_H_ */

#ifndef KEYACTION_H_
#define KEYACTION_H_

/* Key actions (movements, quit, shooting etc) */
struct KeyAction {
	enum KeyEvent { MOVE = 1, STOP = 2, QUIT = 4, SHOOT = 8, DEAD = 16 };
	enum PlayerDirection { NONE = 1, LEFT = 2, RIGHT = 4, UP = 8, DOWN = 16 };

	/* Which type of key event that is currently being handled*/
	int key_event;

	/* Which direction we are moving in*/
	int player_direction;

	/* Which direction we are shooting in	 */
	int shoot_direction;
};

#endif /* KEYACTION_H_ */

#include "../MovableObject.h"
#include "../KeyAction.h"
#include <string>

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

/* Base class of the zombie enemies.
  Inherits from MovableObject (which inherits from WorldObject)
 */
class Zombie: public MovableObject {
public:
	Zombie();
virtual ~Zombie();

	/* Moves the enemy to a new position (determined by the KeyAction supplied)
	 */
	void setmovement(KeyAction* new_movement);

	/* Sets damage to the enemy (if it was hit by a bullet)
	 */
	void setdamage(int damage);

	/* Sets the texture of a crack
	 */
	void setcrack(SDL_Surface* surface);

	/* Reveals the enemy from the ground (when we move too close, it
	  digs himself out of the ground and starts moving towards the player)
	 */
	void reveal();

	/* Reveals the crack in the ground
	 */
	void show();

	/* Returns the right surface depending on if the zombie is burried or not
	 */
	SDL_Surface* getzombie();

	/* Returns the current health of the zombie
	 */
	int gethealth();

	/* Returns the maximum health available for this zombie
	 */
	int getmaxhealth();

	/* Returns the points gained by killing the zombie
	 */
	int getpointsgained();

	/* Returns wether the zombie is revealed to the player or not
	 */
	bool getrevealed();

	/* Returns wether the zombie is hidden completely or not
	 */
	bool gethidden();

	/* Returns the movement of the zombie
	 */
	KeyAction* getmovement();
protected:
	/* Name of the zombie
	 */
	std::string name;

	/* Holds the current movement of the zombie
	 */
	KeyAction* movement;

	/* Amount of points gained by killing him
	 */
	int points_gained;

	/* Max health of the zombie
	 */
	const int MAX_HEALTH;

	/* Holds the ground crack as a surface
	 */
	SDL_Surface* crack;

	/* Holds a bool telling us if the zombie is revealed or not
	 */
	bool revealed;

	/* Holds a bool telling us if the zombie is completely hidden or not
	 */
	bool hidden;
};

#endif /* ZOMBIE_H_ */

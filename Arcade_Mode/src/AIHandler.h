#include <vector>
#include "enemies/Zombie.h"
#include "WorldObject.h"
#include "CollisionManager.h"
#include "Map.h"

#ifndef AIHANDLER_H_
#define AIHANDLER_H_

/* Takes care of AI movements of a enemy.
  This class handles the prediction of the new movement
  path of the zombie in order to move him towards the player.
 */
class AIHandler {
public:
	/* Move a zombie to a new position (determined by where the player is)
	   Detects the position of the player and the current zombie then it determines whether
	   it's inside the "attack" zone or not, if it is, lets move against the player.
	   If the enemy is within 2 pixels of the player, and the player is still, stop the
	   zombie from moving (to prevent the cpu from unnessesary load)
	 */
	void move_object(Zombie* zombie, WorldObject* player);

	/* Clears a zombie movement and "stops" him for a millisecond (before
	 * a new movement is added to the zombie)
	 */
	void clear_movement(Zombie* zombie);

	// Constructor
	AIHandler(CollisionManager* collision);

	//
	~AIHandler();
private:
	// Contains a pointer to our CollisionManager
	 	CollisionManager* collision;
};

#endif /* AIHANDLER_H_ */

#include <SDL/SDL.h>
#include <algorithm>
#include <vector>
#include "WorldObject.h"
#include "MovableObject.h"
#include "enemies/Zombie.h"
#include "KeyAction.h"
#include "Projectile.h"
#include "DrawEngine.h"
#include "GarbageCollector.h"

#ifndef COLLISIONMANAGER_H_
#define COLLISIONMANAGER_H_

/* Takes care of collision detectino between
  the player and WorldObjects, as well as between
  WorldObjects and enemies.
  It also handles bullet hits where it detects if a bullet
  hits a WorldObject or an enemy.
*/
class CollisionManager {
public:
	/*
	  Checks for a collision between a collection of WorldObject, a MovableObject and a movement (KeyAction)
	 */
	KeyAction* perform_collision_detection(vector<WorldObject*> victims, MovableObject* ai, KeyAction* key_action);

	/* Performs bullet collision detection to check wether a bullet has hit a
	   WorldObject or the screen edges. If that's the case, we remove the bullet
	 */
	void perform_collision_bullet(vector<WorldObject*> victims, vector<Projectile*> bullets);

	/* Detecting wether a bullet hits a zombie or not, if thats the case, we
	   lower the health on a zombie and removes the bullet.
	 */
	void perform_bullet_hit(vector<Zombie*> zombies, vector<Projectile*> bullets);

	/* Detects if a zombie hits the player, and in that case we tell the
	   game that the player has been hit, and we remove some health from the
	   player
	*/
	bool check_player_collision(vector<Zombie*> zombies, MovableObject* player);

	/* Constructor*/
	CollisionManager();

	/* Destructor */
	~CollisionManager();

private:
	/* The max distance to check for a collision*/
	const int MAX_DISTANCE_FOR_COLLISION;
};

#endif /* COLLISIONMANAGER_H_ */

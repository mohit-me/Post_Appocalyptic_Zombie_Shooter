#include "Zombie.h"
#include "HeadEater.h"
#include "../KeyAction.h"
#include "../DrawEngine.h"
#include "../Map.h"
#include "../CollisionManager.h"

#ifndef SPAWNHANDLER_H_
#define SPAWNHANDLER_H_

/* Takes care of spawning new enemies when we have
  killed one enemy.*/
class SpawnHandler {
public:
	/* Constructor
	 */
	SpawnHandler(DrawEngine* draw_engine, CollisionManager* collision);

	/* Destructor
	 */
	~SpawnHandler();

	/* Spawns a new enemy to the map
	 */
	Zombie* spawn_enemy();
private:
	/* Holds a pointer to our DrawEngine
	 */
	DrawEngine* draw_engine;

	/* Holds a pointer to our CollisionManager
	 */
	CollisionManager* collision;
};

#endif /* SPAWNHANDLER_H_ */

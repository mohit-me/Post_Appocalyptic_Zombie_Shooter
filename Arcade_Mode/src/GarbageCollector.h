#include <iostream>
#include <vector>
#include <algorithm>
#include "Projectile.h"
#include "enemies/Zombie.h"

#ifndef GARBAGECOLLECTOR_H_
#define GARBAGECOLLECTOR_H_

/* Takes care of old and used enemies and bullets.
  Frees up the memory and deletes the objects.
*/
class GarbageCollector {
private:
	static std::vector<Projectile*> trunk_projectiles;
	static std::vector<Zombie*> trunk_zombie;
public:
	/* Constructor*/
	GarbageCollector();

	/* Destructor  */
	~GarbageCollector();

	/* Get the size of the list with dead zombies*/
	static int get_zombie_size() {
		return GarbageCollector::trunk_zombie.size();
	}

	/* Get the deletion queue of bullets*/
	static std::vector<Projectile*> projectile_deletion_queue() {
		return GarbageCollector::trunk_projectiles;
	}

	/* Get the deletion queue of zombies
	 */
	static std::vector<Zombie*> zombie_deletion_queue() {
		return GarbageCollector::trunk_zombie;
	}

	/* Add a new bullet to the deletion queue
	 */
	static void add_deletion_queue(Projectile* bullet) {
		std::vector<Projectile*>::iterator it;
		it = find(GarbageCollector::trunk_projectiles.begin(), GarbageCollector::trunk_projectiles.end(), bullet);

		if (it == GarbageCollector::trunk_projectiles.end()) {
			GarbageCollector::trunk_projectiles.push_back(bullet);
		}
	}

	/* Add a zombie to the deletion queue
	 */
	static void add_deletion_queue(Zombie* worldobject) {
		GarbageCollector::trunk_zombie.push_back(worldobject);
	}

	/* Delete a bullet from the deletion queue
	 */
	static void delete_deletion_object(std::vector<Projectile*>::iterator it) {
		GarbageCollector::trunk_projectiles.erase(it);
	}

	/* Delete a zombie from the deletion queue
	 */
	static void delete_deletion_object(std::vector<Zombie*>::iterator it) {
		GarbageCollector::trunk_zombie.erase(it);
	}

	/* Clear the deletion queue after it has been processed
	 */
	static void clear_deletion_queue() {
		if (GarbageCollector::projectile_deletion_queue().size() > 0) {
			GarbageCollector::trunk_projectiles.clear();
		}

		if (GarbageCollector::zombie_deletion_queue().size() > 0) {
			GarbageCollector::trunk_zombie.clear();
		}
	}

	/* Execute the garbage collector to clear the main enemy and projectile vector
	 * from dead and used zombies/projectiles
	 */
	static int execute_collector(vector<Projectile*>& projectiles, vector<Zombie*>& enemies) {
		int points = 0;

		//
		// delete all bullets in the deletion queue
		//
		vector<Projectile*> deletion_queue = GarbageCollector::projectile_deletion_queue();

		if (GarbageCollector::projectile_deletion_queue().size() > 0) {
			std::vector<Projectile*>::iterator it;

			for (it = deletion_queue.begin(); it != deletion_queue.end(); it++) {
				vector<Projectile*>::iterator pos;
				pos = find(projectiles.begin(), projectiles.end(), *it);

				if (pos != projectiles.end()) {
					projectiles.erase(pos);

					delete (*it);
					*it = 0;
				}
			}
		}

		vector<Zombie*> zombie_queue = GarbageCollector::zombie_deletion_queue();

		if (GarbageCollector::zombie_deletion_queue().size() > 0) {
			std::vector<Zombie*>::iterator it;

			for (it = zombie_queue.begin(); it != zombie_queue.end(); it++) {
				vector<Zombie*>::iterator pos;
				pos = find(enemies.begin(), enemies.end(), *it);

				if (pos != enemies.end()) {
					points += (*it)->getpointsgained();

					delete *pos;
					*pos = 0;
					enemies.erase(pos);
				}
			}
		}

		GarbageCollector::clear_deletion_queue();

		return points;
	}
};

#endif /* GARBAGECOLLECTOR_H_ */

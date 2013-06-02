#include "WorldObject.h"
#include "KeyAction.h"

#ifndef MOVABLEOBJECT_H_
#define MOVABLEOBJECT_H_
// Subclass for all WorldObjects that are able to move around in the world.

class MovableObject : public WorldObject {
public:
	// Move a MovableObject in the direction provided by key_action
	 void move(const KeyAction* key_action);

	// Set the move speed of this object
	void setmovespeed(int speed);

	void sethealth(int health);

	// Get the current health of this MovableObject
	int gethealth() const;

	// Get the current movement speed
	int getmovespeed() const;

	// Constructor
	MovableObject();

	// Destructor
	 ~MovableObject();
protected:
	// Keeps the health
	int health;

	// Keeps the amount of damage done by this MovableObject
	int damage;

	// Keeps the move speed
	int move_speed;
};


#endif /* MOVABLEOBJECT_H_ */

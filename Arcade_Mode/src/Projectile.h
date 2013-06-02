#include <vector>
#include "SDL/SDL.h"
#include "KeyAction.h"

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

/*
  Class for a projectile, where we
  create a new instance for a projectile and
  determines position and direction when we fire it.
 */
class Projectile {
private:
	int x;
	int y;
	int org_x;
	int org_y;
	int damage;
	int direction;
	int width;
	int height;
	int move_speed;
	const int length;
	SDL_Rect* rect;
public:
	/* Constructor
	 */
	Projectile();

	/* Copy constructor
	 */
	Projectile(const Projectile &b);

	/* Destructor
	 */
	~Projectile();

	/* Set the current x position
	 */
	void setx(int x);

	/* Set the current y position
	 */
	void sety(int y);

	/* Set the damage done by the bullet
	 */
	void setdamage(int damage);

	/* Set the direction of which this bullet should travel
	 */
	void setdirection(int direction);

	/* Moves the projectile in a predefined direction (depending on the shooting
	   direction).
	 */
	void move();

	/* Returns the x position of the projectile
	 */
	int getx();

	/* Returns the y position of the projectile
	 */
	int gety();

	/* Get the damage done by the projectile
	 */
	int getdamage();

	/* Get the width of the projectile
	 */
	int getwidth();

	/* Get the height of the projectile
	 */
	int getheight();

	/* Get the original position of the projectile (where it came from)
	 */
	int getorgx();

	/* Get the original position of the projectile (where it came from)
	 */
	int getorgy();

	SDL_Rect* getbullet();
};

#endif /* PROJECTILE_H_ */

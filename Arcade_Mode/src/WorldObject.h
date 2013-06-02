#include <SDL/SDL.h>
#include <iostream>
using namespace std;

#ifndef WORLDOBJECT_H_
#define WORLDOBJECT_H_

/* Base class for all objects in our game world.
  All objects are somekind of WorldObject.
 */
class WorldObject {
public:
	/* Get the x position of the world object
	 */
	int getx();

	/* Get the y position of the world object
	 */
	int gety();

	/* Get whether the object is movable or not
	 */
	bool getmovable();

	/* Get whether the object is collisionable or not
	 */
	bool getcollisionable();

	/* Get the texture path of the world object
	 */
	string gettexture();

	/* Get the surface of the world object
	 */
	SDL_Surface* getsurface() const;

	/* Set the x position of the world object
	 */
	void setx(int x);

	/* Set the y position of the world object
	 */
	void sety(int y);

	/* Move the object to x position
	 */
	void movex(int x);

	/* Move the object to y position
	 */
	void movey(int y);

	/* Set whether the object is movable or not
	 */
	void setmovable(bool movable);

	/* Set the texture path of this object
	  */
	void settexture(string texture);

	/* Set the surface of this object
	 */
	void setsurface(SDL_Surface* surface);

	/* Set whether the object is collisionable or not
	 */
	void setcollisionable(bool collisonable);

	/* Constructor
	 */
	WorldObject();

	/* Destructor
	 */
	virtual ~WorldObject();
private:
	int x;
	int y;
	bool movable;
	bool collisionable;
	string texture;
	SDL_Surface* surface;
};

#endif /* WORLDOBJECT_H_ */

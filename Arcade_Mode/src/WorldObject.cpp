#include "WorldObject.h"

WorldObject::WorldObject() {
	// by default, all objects should be collisionable
	this->collisionable = true;
}

WorldObject::~WorldObject() {
	delete this->surface;
	this->surface = 0;

	std::cerr << "Deleting WorldObject" << std::endl;
}


/*
  FUNCTION WorldObject::getx()
  Returns the current x position of the object
 */
int WorldObject::getx() {
	return this->x;
}

/*
  FUNCTION WorldObject::gety()
  Returns the current y position of the object
 */
int WorldObject::gety() {
	return this->y;
}

/*
  FUNCTION WorldObject::getmovable()
  Returns true if the object is movable otherwise it returns false
 */
bool WorldObject::getmovable() {
	return this->movable;
}

/*
  FUNCTION WorldObject::getcollisionable()
  Returns true if the object is a object that we should perform collision detection on
 */
bool WorldObject::getcollisionable() {
	return this->collisionable;
}

/*
  FUNCTION WorldObject::gettexture()
  Returns the texture of this object to the caller class
 */
string WorldObject::gettexture() {
	return this->texture;
}

/*
 * FUNCTION WorldObject::getsurface()
 * Returns a pointer to the current SDL Surface of this object
 */
SDL_Surface* WorldObject::getsurface() const {
	return this->surface;
}

/*
  FUNCTION WorldObject::setx(int x)
  Sets the new x position of this object
 */
void WorldObject::setx(int x) {
	this->x = x;
}

/*
  FUNCTION WorldObject::sety(int y)
  Sets the new y position of this object
 */
void WorldObject::sety(int y) {
	this->y = y;
}

/*
  FUNCTION WorldObject::movex(int x)
  Moves the object by x pixels
 */
void WorldObject::movex(int x) {
	this->x += x;
}

/*
  FUNCTION WorldObject::movey(int y)
  Moves the object by y pixels
 */
void WorldObject::movey(int y) {
	this->y += y;
}

/*
  FUNCTION WorldObject::setmovable(bool movable)
  Defines wether the object is movable or not
 */
void WorldObject::setmovable(bool movable) {
	this->movable = movable;
}

/*
  FUNCTION WorldObject::setcollisionable(bool collisionable)
  Sets wether the object is a victim to collision detection or not
 */
void WorldObject::setcollisionable(bool collisionable) {
	this->collisionable = collisionable;
}

/*
  FUNCTION WorldObject::settexture(string texture)
  Sets the texture which will be drawn for this object
 */
void WorldObject::settexture(string texture) {
	this->texture = texture;
}

/*
  FUNCTION WorldObject::setsurface(SDL_Surface* surface)
  Sets the new surface to this object that should be rendered on screen
 */
void WorldObject::setsurface(SDL_Surface* surface) {
	this->surface = surface;
}

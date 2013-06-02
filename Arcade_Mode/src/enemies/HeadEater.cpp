#include "HeadEater.h"

HeadEater::HeadEater() {
	this->name = "Head Eater";
	this->damage = 5;
	this->health = 100;
	this->move_speed = 4;
	this->points_gained = 15;
	this->movement = new KeyAction();
	this->revealed = false;
	this->hidden = true;
	this->crack = 0;
}

HeadEater::~HeadEater() {
	// TODO Auto-generated destructor stub
	delete this->movement;
	this->movement = 0;

	delete this->crack;
	this->crack = 0;

	delete this->getsurface();
	this->setsurface(0);
}

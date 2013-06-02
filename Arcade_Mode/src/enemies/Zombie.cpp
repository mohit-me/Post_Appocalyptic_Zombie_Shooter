#include "Zombie.h"

Zombie::Zombie() : MAX_HEALTH(100) {
	this->name = "Brain Eater";
	this->damage = 10;
	this->health = 150;
	this->move_speed = 1;
	this->points_gained = 10;
	this->movement = new KeyAction();
	this->revealed = false;
	this->hidden = true;
	this->crack = 0;

	std::cerr << "Created monster: " << this->name << std::endl;
}

Zombie::~Zombie() {
	delete this->movement;
	this->movement = 0;

	delete this->crack;
	this->crack = 0;

	delete this->getsurface();
	this->setsurface(0);

	std::cerr << "Deleting Zombie " << this->name << std::endl;
}

void Zombie::show() {
	this->hidden = false;
}

void Zombie::reveal() {
	this->revealed = true;
}

void Zombie::setmovement(KeyAction* new_movement) {
	this->movement = new_movement;
}

void Zombie::setdamage(int damage) {
	this->health -= damage;
}

void Zombie::setcrack(SDL_Surface* surface) {
	this->crack = surface;
}

int Zombie::gethealth() {
	return this->health;
}

int Zombie::getmaxhealth() {
	return this->MAX_HEALTH;
}

int Zombie::getpointsgained() {
	return this->points_gained;
}

bool Zombie::getrevealed() {
	return this->revealed;
}

bool Zombie::gethidden() {
	return this->hidden;
}

KeyAction* Zombie::getmovement() {
	return this->movement;
}

SDL_Surface* Zombie::getzombie() {
	if (this->revealed && !this->hidden) {
		return this->getsurface();
	} else if (!this->hidden && !this->revealed) {
		return this->crack;
	} else {
		return 0;
	}
}


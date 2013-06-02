#include "MovableObject.h"

MovableObject::MovableObject() {
	this->health = 100;
	this->damage = 0;
	this->move_speed = 4;
}

MovableObject::~MovableObject() {
	std::cerr << "Deleting MovableObject" << std::endl;
}

void MovableObject::move(const KeyAction* key_action) {
	if ((KeyAction::LEFT & key_action->player_direction) == KeyAction::LEFT) {
		this->movex(-this->move_speed);
	}
	if ((KeyAction::RIGHT & key_action->player_direction) == KeyAction::RIGHT) {
		this->movex(this->move_speed);
	}
	if ((KeyAction::UP & key_action->player_direction) == KeyAction::UP) {
		this->movey(-this->move_speed);
	}
	if ((KeyAction::DOWN & key_action->player_direction) == KeyAction::DOWN) {
		this->movey(this->move_speed);
	}
}

void MovableObject::setmovespeed(int speed) {
	this->move_speed = speed;
}

void MovableObject::sethealth(int health) {
	this->health -= health;
}

int MovableObject::getmovespeed() const {
	return this->move_speed;
}

int MovableObject::gethealth() const {
	return this->health;
}

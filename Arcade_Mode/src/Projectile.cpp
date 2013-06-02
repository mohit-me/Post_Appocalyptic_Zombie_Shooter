#include "Projectile.h"

Projectile::Projectile() :
	length(3) {
	this->width = 0;
	this->height = 0;
	this->org_x = 0;
	this->org_y = 0;
	this->move_speed = 4;

	rect = new SDL_Rect();
	rect->x = this->org_x;
	rect->y = this->org_y;
	rect->w = this->width;
	rect->h = this->height;
}

Projectile::~Projectile() {
	delete rect;
	rect = 0;
}

int Projectile::getx() {
	return this->x;
}

int Projectile::gety() {
	return this->y;
}

int Projectile::getdamage() {
	return this->damage;
}

int Projectile::getwidth() {
	return this->width;
}

int Projectile::getheight() {
	return this->height;
}

int Projectile::getorgx() {
	return this->org_x;
}

int Projectile::getorgy() {
	return this->org_y;
}

SDL_Rect* Projectile::getbullet() {
	return this->rect;
}

void Projectile::move() {
	switch (this->direction) {
	case KeyAction::UP:
		this->y -= this->move_speed;
		break;
	case KeyAction::DOWN:
		this->y += this->move_speed;
		break;
	case KeyAction::LEFT:
		this->x -= this->move_speed;
		break;
	case KeyAction::RIGHT:
		this->x += this->move_speed;
		break;
	}

	this->rect->x = this->x;
	this->rect->y = this->y;
}

void Projectile::setx(int x) {
	if (this->org_x == 0) {
		this->org_x = x;
	}

	this->x = x;
}

void Projectile::sety(int y) {
	if (this->org_y == 0) {
		this->org_y = y;
	}

	this->y = y;
}

void Projectile::setdamage(int damage) {
	this->damage = damage;
}

void Projectile::setdirection(int direction) {
	this->direction = direction;

	switch (this->direction) {
	case KeyAction::UP:
	case KeyAction::DOWN:
		this->width = 1;
		this->height = this->length;
		break;
	case KeyAction::LEFT:
	case KeyAction::RIGHT:
		this->width = this->length;
		this->height = 1;
		break;
	}

	this->rect->w = this->width;
	this->rect->h = this->height;
}

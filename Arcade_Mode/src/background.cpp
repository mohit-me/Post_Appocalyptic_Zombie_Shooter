#include "background.h"
#include "config.h"

Background::Background(SDL_Surface* s) {
  image = s;
  x = y= x_ = y_ = 0;
  w = s->w;
  h = s->h;
}

void Background::scroll() {
  y -= Background::step;
  if(y <= -h) {
    this->reset();
  }
}

void Background::unscroll() {
  y += Background::step;
  if(y <= -h) {
    this->reset();
  }
}

void Background::reset() {
  x = x_;
  y = y_;
}

void Background::draw(SDL_Surface* screen) {
  ApplySurface(x, y, image, screen);
  if(y <= -h + HEIGHT) {
    ApplySurface(x, y + h, image, screen);
  }
}

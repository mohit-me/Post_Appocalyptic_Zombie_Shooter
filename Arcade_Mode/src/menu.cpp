#include "menu.h"
#include "config.h"

Menu::Menu(SDL_Surface* s) {
  menu = s;
  x = y = x_ = y_ = 0;
  w = s->w;
  h = s->h;
}


void Menu::reset() {
  x = x_;
  y = y_;
}

void Menu::draw(SDL_Surface* screen) {
  ApplySurface(x, y, menu, screen);
}
void Menu::setXY(int a, int b) { x = x_ = a; y = y_ = b; }

#ifndef _MENU_H_
#define _MENU_H_

#include "Game.h"

class Menu {
  const static int step = 2;
private:
  SDL_Surface* menu;
  int x, y, x_, y_;
  int w, h;
public:
  Menu(SDL_Surface*);
  void setX(int v) { x = x_ = v; }
  void setY(int v) { y = y_ = v; }
  void setXY(int , int );
  void reset();
  void clic(int , int);
  void draw(SDL_Surface*);
};

#endif

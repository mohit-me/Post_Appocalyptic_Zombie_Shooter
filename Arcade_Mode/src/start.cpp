#include "Game.h"
#include "config.h"
#include "simple.h"
#include "KeyAction.h"

void Start::str() {
  SDL_Surface *screen = InitSDL();
  Background background(LoadImage("Resources/main-screen.png", true));
  Background background1(LoadImage("Resources/back1.png", true));
  Menu menu1(LoadImage("Resources/menu.png", true));
  menu1.setXY(200, 120);
  Menu menu2(LoadImage("Resources/menu2.png", true));
  menu2.setXY(200, 170);
  Menu menu3(LoadImage("Resources/menu3.png", true));
  menu3.setXY(200, 220);
  Menu menu4(LoadImage("Resources/menu4.png", true));
  menu4.setXY(200, 270);
  Menu menu5(LoadImage("Resources/menu5.png", true));
  menu5.setXY(200, 320);

  Music::init();
  Music music("Resources/music.ogg");
  music.loop();
  SDL_Event event;
  background1.draw(screen);
  background.draw(screen);
    menu1.draw(screen);
    menu2.draw(screen);
    menu3.draw(screen);
    menu4.draw(screen);
    menu5.draw(screen);
  SDL_Flip(screen);
  while(1) {
    while(SDL_PollEvent(&event)) {
      switch(event.type) {
       case SDL_MOUSEBUTTONDOWN:
                if(event.button.x>200&&event.button.x<420)
                       {
                         if(event.button.y>120&&event.button.y<160){Game gm; gm.run();}
                         else if(event.button.y>170&&event.button.y<210){/*Showd shd; shd.run();*/}
                         else if(event.button.y>220&&event.button.y<260){Control ctrl; ctrl.control_run();}
                         else if(event.button.y>270&&event.button.y<310){Credit cr; cr.credit_run();}
                         else if(event.button.y>320&&event.button.y<360){exit(0);break;}
                       }
                break;
          break;
      }
    }
    background1.scroll();
    background1.draw(screen);
    background.draw(screen);
    menu1.draw(screen);
    menu2.draw(screen);
    menu3.draw(screen);
    menu4.draw(screen);
    menu5.draw(screen);
    SDL_Flip(screen);

  }

}

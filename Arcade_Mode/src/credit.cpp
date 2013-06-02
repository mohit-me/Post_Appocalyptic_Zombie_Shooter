#include "Game.h"
#include "music.h"
#include "background.h"
#include "menu.h"
#include "Text.h"
#include "simple.h"
#include "config.h"
#include <vector>
#include <algorithm>
#include <vector>
#include <sstream>

void Credit::credit_run() {
      SDL_Surface *screen = InitSDL();
      Background background(LoadImage("Resources/credits.png", true));
      Menu menu5(LoadImage("Resources/menuc.png", true));
      menu5.setXY(200, 420);
      Music::init();
      Music music("Resources/music.ogg");
      music.loop();
      SDL_Event event;
      background.draw(screen);
      menu5.draw(screen);
      SDL_Flip(screen);
      while(1) {
        while(SDL_PollEvent(&event)) {
          switch(event.type) {
           case SDL_MOUSEBUTTONDOWN:
                    if(event.button.y>420&&event.button.y<460){Start st; st.str();}
                    break;
          }
        }
    }
}

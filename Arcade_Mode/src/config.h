#ifndef _CONFIG_H_
#define _CONFIG_H_

/* Game config */
#define WIDTH            640
#define HEIGHT           480
#define DEPTH            32
#define WINDOW_TITLE     "A Game"
#define CHARACTER_BACK   0x00, 0x80,0x00
#include <string>
#include <iostream>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "config.h"

using std::string;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

// to save some precious keystrokes
#define IFNULL(x) if(x == NULL)
#define FATAL(msg) std::cerr << "FATAL: " << msg << std::endl; exit(EXIT_FAILURE)

/* util functions */
SDL_Surface *InitSDL(void);
SDL_Surface *LoadImage(std::string, bool transparent = false);
SDL_Surface *RemoveBackground(SDL_Surface*);
int CleanUp();
void ApplySurface(int, int, SDL_Surface*, SDL_Surface*, SDL_Rect* clip=NULL);


#endif /* _CONFIG_H_ */

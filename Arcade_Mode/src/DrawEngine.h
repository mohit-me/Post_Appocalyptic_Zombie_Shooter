#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include "WorldObject.h"
#include "Text.h"
#include "Projectile.h"
#include "enemies/Zombie.h"

#ifndef DRAWENGINE_H_
#define DRAWENGINE_H_

/* Draws all objects this game containsto the screen.
 */
class DrawEngine {
private:
	SDL_Surface* screen;
	static int screen_width;
	static int screen_height;

	void ApplySurface(int x, int y, SDL_Surface* source,
			SDL_Surface* destination);
	TTF_Font* loadfont(std::string file, int ptsize);
public:
	/* Draws a WorldObject to the screen*/
	void draw(WorldObject* object);

	/* Draws a ZOmbie to the screen
	 */
	void draw(Zombie* zombie);

	/* Draws a collection of WorldObjects to the screen
	 */
	void draw(vector<WorldObject*> objects);

	/* Draws a collection of Projectiles to the screen
	 */
	void draw(vector<Projectile*> bullets);

	/* Draws text to the screen at a given position
	 */
	void draw_text(Text* text, int x, int y);

	/* Push everything in the buffer to the screen
	 */
	void push_screen();

	/* Load a image and create a surface of it
	 */
	SDL_Surface* load_image(string filename);

	/* Get the screen width
	 */
	static int get_screen_width() {
		return screen_width;
	}

	/* Get the screen height
	 */
	static int get_screen_height() {
		return screen_height;
	}

	/* Constructor
	 */
	DrawEngine(int width, int height, int bpp);

	/* Destructor
	 */
	~DrawEngine();
};

#endif /* DRAWENGINE_H_ */

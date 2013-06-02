#include "DrawEngine.h"

int DrawEngine::screen_width;
int DrawEngine::screen_height;

DrawEngine::DrawEngine(int width, int height, int bpp) {
	if (-1 == SDL_Init(SDL_INIT_EVERYTHING)) {
		return;
	}

	if (-1 == TTF_Init()) {
		return;
	}

	screen = SDL_SetVideoMode(width, height, bpp, SDL_HWSURFACE|SDL_DOUBLEBUF);

	if (NULL == screen) {
		// this shouldn't happen, but if it does, we need to terminate the game
		return;
	}

	DrawEngine::screen_width = width;
	DrawEngine::screen_height = height;

	SDL_WM_SetCaption("Project Zombie", NULL);
}

DrawEngine::~DrawEngine() {
	delete screen;
	screen = NULL;
}

void DrawEngine::draw(WorldObject* object) {
	this->ApplySurface(object->getx(), object->gety(), object->getsurface(),
			this->screen);
}

void DrawEngine::draw(Zombie* zombie) {
	int x = 0, y = 0;

	if (!zombie->gethidden() && !zombie->getrevealed()) {
		x = zombie->getx() - (zombie->getsurface()->w / 2);
		y = zombie->gety() - (zombie->getsurface()->h / 2);
	} else {
		x = zombie->getx();
		y = zombie->gety();
	}

	this->ApplySurface(x, y, zombie->getzombie(),
				this->screen);
}

/*
 * FUNCTION DrawEngine::draw(vector<WorldObject*> objects)
 * Draws multiple WorldObjects contained in a vector to the back buffer
 */
void DrawEngine::draw(vector<WorldObject*> objects) {
	vector<WorldObject*>::iterator it;

	for (it = objects.begin(); it != objects.end(); it++) {
		this->ApplySurface((*it)->getx(), (*it)->gety(), (*it)->getsurface(),
				this->screen);
	}
}

void DrawEngine::draw(vector<Projectile*> bullets) {
	vector<Projectile*>::iterator it;
	Uint32 color;

	for (it = bullets.begin(); it != bullets.end(); it++) {
		// move bullets
		(*it)->move();

		color = SDL_MapRGB(this->screen->format, 0, 255, 255);
		SDL_FillRect(this->screen, (*it)->getbullet(), color);
	}
}

void DrawEngine::draw_text(Text* text, int x, int y) {
	this->ApplySurface(x, y, text->getsurface(), this->screen);
}

void DrawEngine::push_screen() {
	SDL_Flip(this->screen);
}

void DrawEngine::ApplySurface(int x, int y, SDL_Surface* source,SDL_Surface* destination) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(source, NULL, destination, &offset);
}

SDL_Surface* DrawEngine::load_image(string filename) {
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;

	loadedImage = IMG_Load(filename.c_str());

	if (loadedImage != NULL) {
		optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
		SDL_FreeSurface(loadedImage);
	}

	return optimizedImage;
}

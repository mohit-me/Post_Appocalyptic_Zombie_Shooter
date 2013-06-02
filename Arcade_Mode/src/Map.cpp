#include "Map.h"

vector<WorldObject*> Map::mapdata;

Map::Map(DrawEngine* draw) {
	this->draw_engine = draw;
}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

/* FUNCTION Map::loadmap(std::string path)
  Loads a map from a file and creates all surfaces
  and sets the right settings for all tiles on the map

  Every map tile is then stored in a vector (mapdata) that
  is later used when rendering the map to screen
 */
void Map::loadmap(std::string path) {
	MovableObject* stall = new MovableObject();
	stall->setx(190);
	stall->sety(100);
	stall->settexture("Resources/stall.png");
	stall->setmovable(true);
	stall->setcollisionable(true);
	stall->setsurface(draw_engine->load_image(stall->gettexture()));

	int tiles_per_row = (DrawEngine::get_screen_width() / 128);
	int y = -33;
	int x_off = 0;
	int counter = 0;

	// create grass
	for (int i = 0; i < 300; i++) {
		WorldObject* grass = new WorldObject();
		grass->setx(x_off + ((counter - 1) * 128));
		grass->sety(y);
		grass->settexture("Resources/grass3.png");
		grass->setmovable(false);
		grass->setcollisionable(false);

		SDL_Surface* surf_grass = draw_engine->load_image(grass->gettexture());
		grass->setsurface(surf_grass);

		mapdata.push_back(grass);

		if ((counter >= tiles_per_row && x_off == 0) || (counter
				>= (tiles_per_row) + 1)) {
			y += 32;
			x_off = (x_off == 0) ? -(64 * 1) : 0;
			counter = 0;
		}

		counter++;
	}

	this->setwidth(tiles_per_row);
	this->setheight(y);

	mapdata.push_back(stall);
}

void Map::setwidth(int width) {
	this->mapwidth = width;
}

void Map::setheight(int height) {
	this->mapheight = height;
}

int Map::getwidth() {
	return this->mapwidth;
}

int Map::getheight() {
	return this->mapheight;
}

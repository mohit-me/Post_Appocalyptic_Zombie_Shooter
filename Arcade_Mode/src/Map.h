#include <iostream>
#include <vector>
#include "WorldObject.h"
#include "MovableObject.h"
#include "DrawEngine.h"

#ifndef MAP_H_
#define MAP_H_

/* Handles map loading from a map file.
 */
class Map {
private:
	static vector<WorldObject*> mapdata;
	DrawEngine* draw_engine;
	int mapwidth;
	int mapheight;
public:
	//Constructor
	Map(DrawEngine* draw);

	// Destructor
	~Map();

	// Set the map width
	 void setwidth(int width);

	// Set the map height
	void setheight(int height);

	// Return the map width
	 int getwidth();

	// Return the map height
	 	int getheight();

	// Load a map from file
	void loadmap(std::string path);

	// Get the loaded map vector
	 static vector<WorldObject*> getmap() {
		return mapdata;
	}
};

#endif /* MAP_H_ */

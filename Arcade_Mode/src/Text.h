#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#ifndef TEXT_H_
#define TEXT_H_

/*Holds a Text that should be rendered to screen */
class Text {
public:
	/* Sets a new text string to this text object and creates
	  a new surface of the text
	 */
	void settext(std::string _text);

	/* Sets a new surface to the text
	 */
	void setsurface(SDL_Surface* surface);

	/* Get the current text string that is rendered with this object
	 */
	std::string gettext();

	/* Get the current surface that is rendered with this object
	 */
	SDL_Surface* getsurface();

	/* Constructor
	 */
	Text(int fontsize);

	/* Constructor
	 */
	Text(std::string text, int fontsize);

	/* Constructor
	 */
	Text(std::string text, int fontsize, int r, int g, int b);

	/* Constructor
	 */
	Text(std::string text);

	/* Destructor
	 */
	~Text();

private:
	std::string text;
	SDL_Surface* surface;
	TTF_Font* font;

	TTF_Font* loadfont(std::string file, int ptsize);
	SDL_Surface* createtextsurface(std::string text);

	int r;
	int g;
	int b;
};

#endif /* TEXT_H_ */

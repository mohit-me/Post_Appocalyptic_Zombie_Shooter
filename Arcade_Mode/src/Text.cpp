#include "Text.h"

Text::Text(int fontsize) {
	this->font = this->loadfont("game.ttf", fontsize);
	this->surface = 0;

	this->r = 255;
	this->g = 255;
	this->b = 255;
}

Text::Text(std::string text) {
	this->font = this->loadfont("game.ttf", 32);
	this->surface = 0;

	this->r = 255;
	this->g = 255;
	this->b = 255;

	this->settext(text);
}

Text::Text(std::string text, int fontsize) {
	this->font = this->loadfont("game.ttf", fontsize);
	this->surface = 0;

	this->r = 255;
	this->g = 255;
	this->b = 255;

	this->settext(text);
}

Text::Text(std::string text, int fontsize, int r, int g, int b) {
	this->font = this->loadfont("game.ttf", fontsize);
	this->surface = 0;

	this->r = r;
	this->g = g;
	this->b = b;

	this->settext(text);
}

Text::~Text() {
	delete this->surface;
	this->surface = 0;
}

void Text::settext(std::string text) {
	if (this->text == text) {
		return;
	}

	this->text = text;

	if (0 != this->surface) {
		delete this->surface;
		this->surface = 0;
	}

	this->setsurface(this->createtextsurface(this->gettext()));
}

void Text::setsurface(SDL_Surface* surface) {
	this->surface = surface;
}

/*
 * Text::loadfont(char* file, int ptsize)
 * Loads a font from a specified path
 * Returns the loaded font
 */
TTF_Font* Text::loadfont(std::string file, int ptsize) {
	TTF_Font* tmpfont;
	tmpfont = TTF_OpenFont(file.c_str(), ptsize);

	if (tmpfont == NULL) {
	  printf("Unable to load font: %s %s\n", file.c_str(), TTF_GetError());
	}

	return tmpfont;
}

std::string Text::gettext() {
	return this->text;
}

SDL_Surface* Text::getsurface() {
	return this->surface;
}

/*
 * FUNCTION Text::createtextsurface(std::string text)
 * Create a text with a specified color
 */
SDL_Surface* Text::createtextsurface(std::string text) {
	SDL_Color tmpfontcolor = { this->r, this->g, this->b, 100 };
	SDL_Surface* resulting_text;

	resulting_text = TTF_RenderText_Blended(this->font, text.c_str(),
			tmpfontcolor);
	return resulting_text;
}

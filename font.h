#ifndef _FONT_H_
#define _FONT_H_

#include <SDL/SDL.h>

SDL_Surface *font;

int initFont();
SDL_Surface *makeStringSurface(char *);

#endif

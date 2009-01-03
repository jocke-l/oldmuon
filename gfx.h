#ifndef _GFX_H_
#define _GFX_H_

#include <SDL/SDL.h>

SDL_Surface **sprite_array;

int drawRectOutlines(SDL_Surface *, SDL_Rect *, Uint32);
int loadSprites();
void drawSprite(Object);
void drawSurface(int, int, SDL_Surface *);
void drawGrid();

#endif

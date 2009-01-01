#ifndef _GFX_H_
#define _GFX_H_

SDL_Surface **sprite_array;

int drawRectOutlines(SDL_Surface *, SDL_Rect *, Uint32);
int loadSprites();
void drawSprite(Object);
void drawGrid();

#endif

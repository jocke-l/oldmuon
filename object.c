#include "object.h"

void Object_loadSprite(char *filename, Object *object) {
	SDL_Surface *sprite;
	if ((sprite = IMG_Load(filename)) == NULL)
		printFatalErr("IMG_Load failed!");

	object->sprite = sprite;
}

void Object_blitSprite(int x, int y, Object object, SDL_Surface *destination) {
	SDL_Surface *sprite;
	sprite = object.sprite;

	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = sprite->w;
	rect.h = sprite->h;

	SDL_BlitSurface(sprite, NULL, destination, &rect);
}
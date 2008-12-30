#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "muon.h"

typedef struct {
	int x;
	int y;
	int type;
	int hp;
	int owner;

	SDL_Surface *sprite;
} Object;

void Object_loadSprite(char *, Object *);
void Object_blitSprite(int, int, Object, SDL_Surface *);

#endif
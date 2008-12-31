#include "muon.h"

int loadSprites() {
	char filename[8][30] = {
		"0",
		"data/gfx/nothing.png",
		"data/gfx/control.png",
		"data/gfx/nothing.png",
		"data/gfx/repeat.png",
		"data/gfx/scout.png",
		"data/gfx/attacker.png",
		"data/gfx/nothing.png",
	};

	SDL_Surface **temp;
	temp = malloc(sizeof(SDL_Surface *));

	int i;
	for (i = 0; i < 4; i++) {
		if (strcmp(filename[i], "0")) {
			temp = realloc(temp, sizeof(SDL_Surface *) * (i + 1));
			temp[i] = IMG_Load(filename[i]);

			if (temp[i] == NULL) {
				printf("ERROR: loadSprites failed: %s", filename[i]);
				return -1;
			}
		}
	}

	array = temp;
	temp = NULL;

	return 0;
}

void drawSprite(Object object) {
	SDL_Rect rect;
	rect.x = object.x;
	rect.y = object.y;
	rect.w = array[object.type]->w;
	rect.h = array[object.type]->h;

	SDL_BlitSurface(array[object.type], NULL, context, &rect);
}
	
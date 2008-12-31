#include "muon.h"

int loadSprites() {
	char filename[8][30] = {
		"data/gfx/nothing.png",
		"data/gfx/generator.png",
		"data/gfx/control.png",
		"data/gfx/generator.png",
		"data/gfx/repeat.png",
		"data/gfx/scout.png",
		"data/gfx/attacker.png",
		"data/gfx/nothing.png",
	};

	SDL_Surface **temp;
	temp = malloc(sizeof(SDL_Surface *) * 10);

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
	rect.x = (object.x * 32) - map.camx;
	rect.y = (object.y * 32) - map.camy;
	rect.w = 32;
	rect.h = 32;
	SDL_BlitSurface(array[object.type], NULL, context, &rect);
	return;
}

void drawGrid() {
	int i, j;
	SDL_Rect grid;
	for (i = 0; i < map.height; i++) {
		for (j = 0; j < map.width; j++) {
			grid.x = j * 32 - map.camx;
			grid.y = i * 32 - map.camy;
			grid.w = 32;
			grid.h = 32;
			SDL_BlitSurface(array[0], NULL, context, &grid);
		}
	}
	return;
}

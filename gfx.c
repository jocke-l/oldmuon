#include "muon.h"

int drawRectOutlines(SDL_Surface *context, SDL_Rect *rectangle, Uint32 colour_value) {
	SDL_Rect temprect;

	temprect.x = rectangle->x;
	temprect.y = rectangle->y;
	temprect.w = rectangle->w;
	temprect.h = 1;
	SDL_FillRect(context, &temprect, colour_value);

	temprect.x = rectangle->x + rectangle->w;
	temprect.y = rectangle->y;
	temprect.w = 1;
	temprect.h = rectangle->h;
	SDL_FillRect(context, &temprect, colour_value);

	temprect.x = rectangle->x;
	temprect.y = rectangle->y + rectangle->h;
	temprect.w = rectangle->w;
	temprect.h = 1;
	SDL_FillRect(context, &temprect, colour_value);

	temprect.x = rectangle->x;
	temprect.y = rectangle->y;
	temprect.w = 1;
	temprect.h = rectangle->h;
	SDL_FillRect(context, &temprect, colour_value);

	return 0;
}

int loadSprites() {
	char filename[8][30] = {
		"data/gfx/nothing.png",
		"data/gfx/control.png",
		"data/gfx/control.png",
		"data/gfx/generator.png",
		"data/gfx/repeat.png",
		"data/gfx/scout.png",
		"data/gfx/attacker.png",
		"data/gfx/wall.png",
	};

	SDL_Surface **temp;
	temp = malloc(sizeof(SDL_Surface *) * 10);

	int i;
	for (i = 0; i < 8; i++) {
		temp = realloc(temp, sizeof(SDL_Surface *) * (i + 1));
		temp[i] = IMG_Load(filename[i]);

		if (temp[i] == NULL) {
			printf("ERROR: loadSprites failed: %s", filename[i]);
			return -1;
		}

		Uint32 colorkey = SDL_MapRGB(temp[i]->format, 0x00, 0x00, 0x00);
		SDL_SetColorKey(temp[i], SDL_SRCCOLORKEY, colorkey);
	}

	sprite_array = temp;
	temp = NULL;

	return 0;
}

void drawSprite(Object object) {
	SDL_Rect rect;
	rect.x = (object.x * 32) - map.camx;
	rect.y = (object.y * 32) - map.camy;
	rect.w = 32;
	rect.h = 32;
	SDL_BlitSurface(sprite_array[object.type], NULL, context, &rect);
	return;
}

void drawSurface(int x, int y, SDL_Surface *surface) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = surface->w;
	rect.h = surface->h;
	SDL_BlitSurface(surface, NULL, context, &rect);
	return;
}

void drawGrid() {
	int i, j;
	SDL_Rect grid;
	SDL_Rect temp;
	for (i = 0; i < map.height; i++) {
		for (j = 0; j < map.width; j++) {
			grid.x = j * 32 - map.camx;
			grid.y = i * 32 - map.camy;
			grid.w = 32;
			grid.h = 32;
			SDL_BlitSurface(sprite_array[0], NULL, context, &grid);

			temp.x = grid.x;
			temp.y = 0 - map.camy;
			temp.w = 32;
			temp.h = 1;

			SDL_FillRect(context, &temp, SDL_MapRGB(context->format, 0x77, 0x77, 0x77));
		}

		temp.x = 0 - map.camx;
		temp.y = grid.y;
		temp.w = 1;
		temp.h = 32;

		SDL_FillRect(context, &temp, SDL_MapRGB(context->format, 0x77, 0x77, 0x77));
	}
	return;
}

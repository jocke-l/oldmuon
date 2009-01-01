#include "muon.h"

void drawHud() {
	SDL_Rect bg;

	bg.w = 32;
	bg.h = 32;
	bg.x = 4;
	bg.y = map.windh - (32 + 4);

	SDL_FillRect(context, &bg, SDL_MapRGB(context->format, 0x22, 0x22, 0x22));
		
	SDL_BlitSurface(sprite_array[4], NULL, context, &bg);

	int i;
	for (i = 5; i < 8; i++) {
		bg.x += 32 + 4;

		SDL_FillRect(context, &bg, SDL_MapRGB(context->format, 0x22, 0x22, 0x22));
		SDL_BlitSurface(sprite_array[i], NULL, context, &bg);
	}

	float scale_factor = 0;
	if (map.width >= map.height) {
		scale_factor = 128 / map.width;
	} else {
		scale_factor = 128 / map.height;
	}

	bg.w = map.width * scale_factor;
	bg.h = map.height * scale_factor;
	bg.x = 4;
	bg.y = 4;

	SDL_FillRect(context, &bg, SDL_MapRGB(context->format, 0x22, 0x22, 0x22));

	for (i = 0; object_array[i].type != 0; i++) {
		bg.x = 4 + object_array[i].x * scale_factor;
		bg.y = 4 + object_array[i].y * scale_factor;
		bg.w = 4;
		bg.h = 4;

/*
		Uint8 r, g, b;
		fixa färg här sen :D
*/

		SDL_FillRect(context, &bg, SDL_MapRGB(context->format, 0xFF, 0xFF, 0xFF));
	}

	bg.x = 4 + map.camx / 32 * scale_factor;
	bg.y = 4 + map.camy / 32 * scale_factor;
	bg.w = map.windw / 32 * scale_factor;
	bg.h = map.windh / 32 * scale_factor;

	drawRectOutlines(context, &bg, SDL_MapRGB(context->format, 0x77, 0x77, 0x77));

}
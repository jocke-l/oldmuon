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

	bg.w += 1;
	bg.h += 1;
	bg.x -= 1;
	bg.y -= 1;

	drawRectOutlines(context, &bg, SDL_MapRGB(context->format, 0x77, 0x77, 0x77));

	for (i = 0; object_array[i].type != 0; i++) {
		bg.x = 4 + object_array[i].x * scale_factor;
		bg.y = 4 + object_array[i].y * scale_factor;
		bg.w = 4;
		bg.h = 4;


		Uint8 rr, gg, bb;
		rr = players[object_array[i].owner].r;
		gg = players[object_array[i].owner].g;
		bb = players[object_array[i].owner].b;


		SDL_FillRect(context, &bg, SDL_MapRGB(context->format, rr, gg, bb));
	}

	bg.x = 4 + map.camx * scale_factor / 32;
	bg.y = 4 + map.camy * scale_factor / 32;
	bg.w = map.windw / 32 * scale_factor;
	bg.h = map.windh / 32 * scale_factor;

	drawRectOutlines(context, &bg, SDL_MapRGB(context->format, 0x77, 0x77, 0x77));

}
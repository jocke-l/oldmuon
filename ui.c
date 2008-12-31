#include "muon.h"

void drawHud() {
	SDL_Rect bg;

	bg.w = 40;
	bg.h = 40;
	bg.x = 4;
	bg.y = map.windh - (40 + 4);

	SDL_FillRect(context, &bg, SDL_MapRGB(context->format, 0x22, 0x22, 0x22));

	int i;
	for (i = 0; i < 4; i++) {
		bg.x += 40 + 4;

		SDL_FillRect(context, &bg, SDL_MapRGB(context->format, 0x22, 0x22, 0x22));
	}

	bg.w = 136;
	bg.h = 136;
	bg.x = 4;
	bg.y = 4;

	SDL_FillRect(context, &bg, SDL_MapRGB(context->format, 0x22, 0x22, 0x22));
}
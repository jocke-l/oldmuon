#include "muon.h"

void drawHud() {
	SDL_Rect bg;

	bg.x = 0;
	bg.y = map.windh - (3 * 32);
	bg.w = map.windw;
	bg.h = 3 * 32;

	SDL_FillRect(context, &bg, SDL_MapRGB(context->format, 0x22, 0x22, 0x22));
}
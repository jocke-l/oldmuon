#include "muon.h"

void drawHud() {
	SDL_Rect rect;

	rect.w = 32;
	rect.h = 32;
	rect.x = 4;
	rect.y = map.windh - (32 + 4);
	button[0] = rect;

	SDL_FillRect(context, &rect, SDL_MapRGB(context->format, 0x22, 0x22, 0x22));		
	SDL_BlitSurface(sprite_array[4], NULL, context, &rect);

	int i;
	for (i = 5; i < 8; i++) {
		rect.x += 32 + 4;
		button[i - 4] = rect;

		SDL_FillRect(context, &rect, SDL_MapRGB(context->format, 0x22, 0x22, 0x22));
		SDL_BlitSurface(sprite_array[i], NULL, context, &rect);
	}

	float scale_factor = 0;
	if (map.width >= map.height) {
		scale_factor = 128 / map.width;
	} else {
		scale_factor = 128 / map.height;
	}

	rect.w = map.width * scale_factor;
	rect.h = map.height * scale_factor;
	rect.x = 4;
	rect.y = 4;

	SDL_FillRect(context, &rect, SDL_MapRGB(context->format, 0x22, 0x22, 0x22));

	rect.w += 1;
	rect.h += 1;
	rect.x -= 1;
	rect.y -= 1;

	drawRectOutlines(context, &rect, SDL_MapRGB(context->format, 0x77, 0x77, 0x77));

	for (i = 0; object_array[i].type != 0; i++) {
		rect.x = 4 + object_array[i].x * scale_factor;
		rect.y = 4 + object_array[i].y * scale_factor;
		rect.w = 4;
		rect.h = 4;


		Uint8 rr, gg, bb;
		rr = players[object_array[i].owner].r;
		gg = players[object_array[i].owner].g;
		bb = players[object_array[i].owner].b;


		SDL_FillRect(context, &rect, SDL_MapRGB(context->format, rr, gg, bb));
	}

	rect.x = 4 + map.camx * scale_factor / 32;
	rect.y = 4 + map.camy * scale_factor / 32;
	rect.w = map.windw / 32 * scale_factor;
	rect.h = map.windh / 32 * scale_factor;

	drawRectOutlines(context, &rect, SDL_MapRGB(context->format, 0x77, 0x77, 0x77));
}

void uiControl() {
	if (isPressed(BUTTON_ATTACKER))
		printf("Yeh: attacker\n");
}

int isPressed(SDL_Rect rect) {
	if (event.button.type == SDL_MOUSEBUTTONDOWN) {
		if (event.button.button == SDL_BUTTON_LEFT) {
			int x = event.button.x;
			int y = event.button.y;

			if ((x > rect.x) && (x < rect.x + rect.w)) {
				if ((y > rect.y) && (y < rect.y + rect.h))
					return 1;
			}
		}
	}

	return 0;
}
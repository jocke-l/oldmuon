#include "muon.h"

int initFont() {
	font = IMG_Load("data/gfx/font.png");
	if (font == NULL) {
		printf("ERROR: initFont failed: data/gfx/font.png");
		return -1;
	}

	return 0; 
}

SDL_Surface *makeStringSurface(char *str) {
	int surface_w = 640;
	int surface_h = 480;

	int lines = 0;
	int rows = 0;
		
	SDL_Surface *surface;
	surface = SDL_CreateRGBSurface(SDL_SWSURFACE, surface_w, surface_h, 24, 0x00, 0x00, 0x00, 0x00);

	SDL_Rect clip;
	clip.h = 23;
	clip.w = 11;
	clip.y = 0;

	int i;
	for (i = 0; str[i] != '\0'; i++) {
		clip.x = clip.w * (str[i] - 97);

		SDL_Rect rect;
		if (str[i] == '\n') {
			lines++;
			rows = 0;
		} else if (str[i] == ' ') {
			rows++;
		} else {
			rows++;

			rect.x = clip.w * rows;
			rect.y = clip.h * lines;
			rect.w = clip.w;
			rect.h = clip.h;

			SDL_BlitSurface(font, &clip, surface, &rect);
		}
	}

	Uint32 colorkey = SDL_MapRGB(surface->format, 0x00, 0x00, 0x00);
	SDL_SetColorKey(surface, SDL_SRCCOLORKEY, colorkey);

	return surface;
}
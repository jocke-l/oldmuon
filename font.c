#include "muon.h"

int initFont() {
	font = IMG_Load("data/gfx/font.png");
	if (font == NULL) {
		printf("ERROR: initFont failed: data/gfx/font.png");
		return -1;
	}

	return 0;
}

void drawString(int x, int y, char *str) {
	SDL_Rect clip;
	clip.h = 23;
	clip.w = 11;
	clip.y = 0;	

	int lines = 0;
	int rows = 0;

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

			rect.x = x + (clip.w * rows);
			rect.y = y + (clip.h * lines);
			rect.w = clip.w;
			rect.h = clip.h;

			SDL_BlitSurface(font, &clip, context, &rect);
		}
	}
}


		
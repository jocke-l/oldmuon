#include <stdio.h>
#include <math.h>
#include "../../muon.h"
#include "../../object.c"
#include "../../map.c"

SDL_Surface *loadImage(char *file_name) {
	SDL_Surface *temp_image = NULL;
	SDL_Surface *return_image = NULL;

	temp_image = SDL_LoadBMP(file_name);
	if (temp_image != NULL) {
		return_image = SDL_DisplayFormat(temp_image);
		SDL_FreeSurface(temp_image);
	}

	return return_image;
}

void surfaceBlit(int x, int y, SDL_Surface *src, SDL_Surface *dest) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(src, NULL, dest, &offset);

}

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		printf("Failed to initialise SDL.");
		return 1;
	}
	SDL_Surface *screen = NULL;
	SDL_Surface *blip = NULL;
	screen = SDL_SetVideoMode(640, 640, 32, SDL_SWSURFACE);
	if (screen == NULL) {
		printf("Failed to set video mode.");
		return 1;
	}

	Map_Init();
	Map_Load(argv[1]);

	int i;
	for (i=0; object_array[i].type != 0; i++) {
		switch (object_array[i].type) {
			case 1:
				blip = loadImage("stpoint.bmp");
				surfaceBlit(object_array[i].x, object_array[i].y, blip, screen);
				break;
			case 2:
				blip = loadImage("ctpoint.bmp");
				surfaceBlit(object_array[i].x, object_array[i].y, blip, screen);
				break;
			default:
				break;
		}
	}
	SDL_FreeSurface(blip);

	if (SDL_Flip(screen) == -1) {
		printf("Failed to flip screen.");
		return 1;
	}

	SDL_SaveBMP(screen, "a.bmp");
	printf("Saving image a.bmp...\n");

	SDL_Delay(2000);

	SDL_FreeSurface(screen);
	SDL_Quit();
	return 0;
}

#include "muon.h"

int main(int argc, char **argv) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL_Init Failed!");
		return -1;
	}

	map.windw = 640;
	map.windh = 480;
	frame_per_sec = 75;

	if ((context = SDL_SetVideoMode(map.windw, map.windh, 24, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		printf("SDL_SetVideoMode Failed!");
		return -1;
	}
	
	initEverything();
	
	Map_load("data/maps/testmap");
	
	loadSprites();

	Timer fps;
	
	int running = 1;
	while (running) {
		Timer_S_ST(&fps, 0);

		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT)
			running = 0;
		
		cameraControl();
		
		drawGrid();
		objectDrawAll();
		drawHud();

		drawString(150, 20, "this is a bitmap font test\nit can handle newlines\nbut no more character\nthan were in the english language\nit can also only handle small characters\nat the moment\nthis can be a good function\nto handle runtime exceptions\nin the game");
		SDL_Flip(context);

		SDL_FillRect(context, &context->clip_rect, SDL_MapRGB(context->format, 0x00, 0x00, 0x00));
		
		
		if (Timer_getTicks(fps) < 1000 / frame_per_sec)
			SDL_Delay((1000 / frame_per_sec) - Timer_getTicks(fps));


		sprintf(map.wind_title, "Muon FPS: %d", Timer_getFPS(fps));
		SDL_WM_SetCaption(map.wind_title, NULL);
	}

	SDL_Quit();
	return 0;
}

void initEverything() {
	objectTemplateArray_Init();
	Map_init();
	initPlayers(2);
	initFont();
}

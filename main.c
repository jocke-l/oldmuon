#include "muon.h"

int main(int argc, char **argv) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL_Init Failed!");
		return -1;
	}

	map.windw = 640;
	map.windh = 380;
	frame_per_sec = 75;

	if ((context = SDL_SetVideoMode(map.windw, map.windh, 24, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		printf("SDL_SetVideoMode Failed!");
		return -1;
	}
	
	initEverything();
	
	Map_load("data/maps/testmap");
	
	loadSprites();
	SDL_Surface *test_text;
	test_text = makeStringSurface("This is a pretty good bitmap font text :D");

	Timer fps;
	
	int running = 1;
	while (running) {
		Timer_S_ST(&fps, 0);

		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT)
			running = 0;
		
		cameraControl();
		
		drawGrid();
		objectDrawPoints();
		objectDrawOwnBuildings();
		objectDrawEnemy();
		//objectDrawAll();
		drawHud();

		drawSurface(140, 20, test_text);
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
	current_player = 1;
	objectTemplateArray_Init();
	Map_init();
	initPlayers(2);
	initFont();
}

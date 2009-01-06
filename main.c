/* All needed header files is included there */
#include "muon.h"

int main(int argc, char **argv) {
	/* Init SDL */
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL_Init Failed!");
		return -1;
	}

	/* Init window related integears */
	//map.windw = 640;
	//map.windh = 480;
	//frame_per_sec = 75;
	
	fileLoad("conf");

	/* Set up a window */
	if ((context = SDL_SetVideoMode(map.windw, map.windh, 24, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		printf("SDL_SetVideoMode Failed!");
		return -1;
	}

	/* Init all structs in that function */
	initEverything();

	/* Load all data here*/
	loadSprites();
	fileLoad("data/maps/testmap");
	makeGrid();

	SDL_Surface *test_text;
	test_text = makeStringSurface("This is a pretty good bitmap font text :D");

	Timer fps;
	
	/* Main loop */
	int running = 1;
	while (running) {
		/* Start FPS timer */
		Timer_S_ST(&fps, 0);

		/* Clear Screen */
		SDL_FillRect(context, &context->clip_rect, SDL_MapRGB(context->format, 0x00, 0x00, 0x00));

		/* Do all event handling here */
		if (SDL_PollEvent(&event)) {
			uiControl();

			if (event.type == SDL_QUIT)
				running = 0;
		}

		cameraControl();

		/* Draw all things here */
		drawGrid();
		objectDrawPoints();
		objectDrawOwnBuildings();
		objectDrawEnemy();
		//objectDrawAll();
		drawHud();
		drawSurface(140, 20, test_text);

		/* Update screen */
		SDL_Flip(context);

		/* FPS Cap */	
		if (Timer_getTicks(fps) < 1000 / frame_per_sec)
			SDL_Delay((1000 / frame_per_sec) - Timer_getTicks(fps));

		/* Write fps in window caption */
		sprintf(map.wind_title, "Muon FPS: %d", Timer_getFPS(fps));
		SDL_WM_SetCaption(map.wind_title, NULL);
	}

	SDL_Quit();
	return 0;
}

/* Init all structs here */
void initEverything() {
	//current_player = 1;
	objectTemplateArray_Init();
	Map_init();
	map.gamemode = 1;
	initPlayers(2);
	initFont();
}

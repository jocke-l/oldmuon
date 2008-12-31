#include "muon.h"


void printFatalErr(char *msg) {
	printf("FATAL ERROR: %s\n", msg);
	exit(0);
}

int main(int argc, char **argv) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		printFatalErr("SDL_Init Failed!");

	SDL_Surface *context;
	SDL_WM_SetCaption("Muon", NULL);
	if ((context = SDL_SetVideoMode(640, 480, 24, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
		printFatalErr("SDl_SetVideoMode Failed!");

	Object circle;
	//Object_loadSprite("circle.png", &circle);

	SDL_Event event;

	Timer fps;
	
	Map_init();
	Map_load("testmap");
	Map_debug();
	Map_unload();
	
	int running = 1;
	while (running) {
		Timer_toggleS_ST(&fps);

		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				running = 0;
		}

		//Object_blitSprite(100, 100, circle, context);

		SDL_Flip(context);

		if (Timer_getTicks(fps) < 1000 / 75)
			SDL_Delay((1000 / 75) - Timer_getTicks(fps));
	}

	SDL_Quit();
	return 0;
}

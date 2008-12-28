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

	SDL_Event event;

	int running = 1;
	while (running) {
		SDL_PollEvent(&event);

		SDL_Flip(context);
	}

	SDL_Quit();
	return 0;
}
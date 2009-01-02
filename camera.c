#include "muon.h"

void cameraControl() {
	Uint8 *keys;
	keys = SDL_GetKeyState(NULL);

	int vel = 10;

	if (keys[SDLK_LSHIFT])
		vel = 25;
	
	if (keys[SDLK_UP])  {
		if(map.camy > 0 - map.windh / 2) 
			map.camy -= vel;
	}
		
	if (keys[SDLK_DOWN]) {
		if(map.camy < map.height * 32 - map.windh / 2) 
			map.camy += vel;
	}

	if (keys[SDLK_LEFT]) {
		if(map.camx > 0 - map.windw / 2)
			map.camx -= vel;
	}

	if (keys[SDLK_RIGHT]) {
		if(map.camx < map.width * 32 - map.windw / 2)
			map.camx += vel; 
	}	
}

#include "muon.h"

void cameraControl() {
	Uint8 *keys;
	keys = SDL_GetKeyState(NULL);

	if (keys[SDLK_UP])
		camera.y -= 5;

	if (keys[SDLK_DOWN])
		camera.y += 5;

	if (keys[SDLK_LEFT])
		camera.x -= 5;

	if (keys[SDLK_RIGHT])
		camera.x += 5;
}
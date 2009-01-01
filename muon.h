#ifndef _MUON_H_
#define _MUON_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "timer.h"
#include "object.h"
#include "map.h"
#include "gfx.h"
#include "camera.h"
#include "ui.h"
#include "player.h"

SDL_Surface *context;
SDL_Event event;

void initEverything();

#endif

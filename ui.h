#ifndef _UI_H_
#define _UI_H_

#include <SDL/SDL.h>

#define BUTTON_REPEATER button[0]
#define BUTTON_SCOUT button[1]
#define BUTTON_ATTACKER button[2]
#define BUTTON_WALL button[3]

void drawHud();
void uiControl();
void addToQueue(int);
int isPressed(SDL_Rect);

#endif
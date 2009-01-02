#ifndef _FONT_H_
#define _FONT_H_

SDL_Surface *font;

int initFont();
void drawString(int, int, char *);

#endif
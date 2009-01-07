#ifndef _GFX_H_
#define _GFX_H_

#include <GL/glfw.h>
#include "object.h"

typedef struct {
	int x;
	int y;

	int w;
	int h;
} Rect;

GLuint *sprite_array;

void drawRect(Rect, GLbyte, GLbyte, GLbyte);
void drawRectOutlines(Rect, GLbyte, GLbyte, GLbyte);
int loadSprites();
void drawSprite(Object);
//void makeGrid();
void drawGrid();

#endif

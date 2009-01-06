#ifndef _GFX_H_
#define _GFX_H_

#include <GL/glfw.h>
#include "object.h"

GLuint *sprite_array;

int loadSprites();
void drawSprite(Object);
//void makeGrid();
//void drawGrid();

#endif

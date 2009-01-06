#include "muon.h"

int loadSprites() {
	char filename[8][30] = {
		"data/gfx/nothing.tga",
		"data/gfx/control.tga",
		"data/gfx/control.tga",
		"data/gfx/generator.tga",
		"data/gfx/repeat.tga",
		"data/gfx/scout.tga",
		"data/gfx/attacker.tga",
		"data/gfx/wall.tga"
	};

	GLuint temp[8];

	int i;
	for (i = 0; i < 8; i++) {   
		glGenTextures(1, (temp + i));
		glBindTexture(GL_TEXTURE_2D, temp[i]);
   
		if (glfwLoadTexture2D(filename[i], GLFW_BUILD_MIPMAPS_BIT | GLFW_ORIGIN_UL_BIT)) {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		} else {
			printf("loadSprites: failed: %s\n", filename[i]);
			return -1;
		}
	}

	sprite_array = temp;

	return 0;
}

void drawSprite(Object object) {
	glLoadIdentity();
	glTranslatef(object.x, object.y, 20);
	glBegin(GL_QUADS);
		glVertex2f(0, 0);
		glVertex2f(32, 0);
		glVertex2f(0, 32);
		glVertex2f(32, 32);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, sprite_array[object.type]);
}

/*void makeGrid() {
	grid = SDL_CreateRGBSurface(SDL_SWSURFACE, map.width * 32, map.height * 32 , 24, 0x00, 0x00, 0x00, 0x00);

	SDL_Rect rect;

	int i, j;
	for (i = 0; i < map.width; i++) {
		for (j = 0; j < map.height; j++) {
			rect.x = i * 32;
			rect.y = j * 32;
			rect.w = 32;
			rect.h = 32;

			SDL_BlitSurface(sprite_array[0], NULL, grid, &rect);
		}
	}

	rect.x = 0;
	rect.y = 0;
	rect.w = map.width * 32;
	rect.h = map.height * 32;

	drawRectOutlines(grid, &rect, SDL_MapRGB(grid->format, 0x77, 0x77, 0x77));
}*/

/*void drawGrid() {
	SDL_Rect clip;
	clip.x = map.camx;
	clip.y = map.camy;
	clip.w = map.windw;
	clip.h = map.windh;

	SDL_BlitSurface(grid, &clip, context, NULL);
	return;
}*/

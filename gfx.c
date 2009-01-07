#include "muon.h"

void drawRectOutlines(Rect rect, GLbyte r, GLbyte g, GLbyte b) {
	glLoadIdentity();
	glTranslatef(rect.x, rect.y, 0.0f);

	glBegin(GL_LINES);
		glColor3b(r, g, b);

		glVertex2i(0, 1);
		glVertex2i(rect.w + 1, 1);

		glVertex2i(0, rect.h);
		glVertex2i(rect.w, rect.h);

		glVertex2i(0, 1);
		glVertex2i(0, rect.h);

		glVertex2i(rect.w, 1);
		glVertex2i(rect.w, rect.h);
	glEnd();
}

void drawRect(Rect rect, GLbyte r, GLbyte g, GLbyte b) {
	glLoadIdentity();
	glTranslatef(rect.x, rect.y, 0.0f);

	glBegin(GL_QUADS);
		glColor3b(r, g, b);

		glVertex2i(0, 0);
		glVertex2i(rect.w, 0);
		glVertex2i(rect.w, rect.h);
		glVertex2i(0, rect.h);
	glEnd();
}

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

	GLFWimage sprite;
	GLuint array[8];

	int i;
	for (i = 0; i < 8; i++) {      
		if (glfwReadImage(filename[i], &sprite, GLFW_ORIGIN_UL_BIT | GLFW_ALPHA_MAP_BIT)) {
			glGenTextures(1, &array[i]);
			glBindTexture(GL_TEXTURE_2D, array[i]);

			glTexImage2D(GL_TEXTURE_2D, 0, 4, sprite.Width, sprite.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, sprite.Data);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		} else {
		printf("loadSprites: failed: %s\n", filename[i]);
			return -1;
		}
	}

	sprite_array = array;

	return 0;
}

void drawSprite(Object object) {
	glLoadIdentity();
	glTranslatef(object.x * 32 - map.camx, object.y * 32 - map.camy, 0.0f);

	//glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
	glBindTexture(GL_TEXTURE_2D, sprite_array[object.type]);

	glBegin(GL_QUADS);
		glTexCoord2i(0, 0);
		glVertex2i(0, 0);
		glTexCoord2i(255, 0);
		glVertex2i(32, 0);
		glTexCoord2i(255, 255);
		glVertex2i(32, 32);
		glTexCoord2i(0, 255);
		glVertex2i(0, 32);
	glEnd();
}

void drawGrid() {
	int i;

	glLoadIdentity();
	glTranslatef(0.0f - map.camx, 0.0f - map.camy, 0.0f);

	glBegin(GL_LINES);
		glColor3b(0x55, 0x55, 0x55);

		for (i = 0; i < map.width; i++) {
			glVertex2i(i * 32, 0);
			glVertex2i(i * 32, map.height * 32);
		}

		for (i = 0; i < map.height; i++) {
			glVertex2i(0, i * 32);
			glVertex2i(map.width * 32, i * 32);
		}

		glVertex2i(0, map.height * 32);
		glVertex2i(map.width * 32, map.height * 32);
		glVertex2i(map.width * 32, 0);
		glVertex2i(map.width * 32, map.height * 32);
	glEnd();				
}

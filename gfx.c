#include "muon.h"

void drawRectOutlines(Rect rect, GLbyte r, GLbyte g, GLbyte b) {
	glLoadIdentity();
	glTranslatef(rect.x, rect.y, 0.0f);

	glColor3b(r, g, b);
	glBegin(GL_LINES);
		glVertex2i(0, 1);
		glVertex2i(rect.w + 1, 1);


		glVertex2i(rect.w, 1);
		glVertex2i(rect.w, rect.h);

		glVertex2i(0, 1);
		glVertex2i(0, rect.h);

		glVertex2i(0, rect.h);
		glVertex2i(rect.w, rect.h);
	glEnd();
}

void drawRect(Rect rect, GLbyte r, GLbyte g, GLbyte b) {
	glLoadIdentity();
	glTranslatef(rect.x, rect.y, 0.0f);

	glColor3b(r, g, b);
	glBegin(GL_QUADS);
		glVertex2i(0, 0);
		glVertex2i(0, rect.h - 1);
		glVertex2i(rect.w, rect.h - 1);
		glVertex2i(rect.w, 0);
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

	int i;
	for (i = 0; i < 8; i++) {
		if (glfwReadImage(filename[i], &sprite, GLFW_ORIGIN_UL_BIT | GLFW_ALPHA_MAP_BIT)) {
			glBindTexture(GL_TEXTURE_2D, i);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sprite.Width, sprite.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, sprite.Data);

			free(sprite.Data);
		} else {
			printf("loadSprites: failed: %s\n", filename[i]);
			return -1;
		}
	}

	return 0;
}

void drawSprite(Object object) {
	glBindTexture(GL_TEXTURE_2D, object.type);

	glLoadIdentity();
	glTranslatef(object.x * 32 - map.camx, object.y * 32 - map.camy, 0.0f);

	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);

	//glColor4b(0x0, 0x00, 0x00, 0xFF);
	glColor3b(0x00, 0x00, 0x00);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex2i(1, 0);

		glTexCoord2f(0.0f, 1.0f);
		glVertex2i(1, 31);

		glTexCoord2f(1.0f, 1.0f);
		glVertex2i(32, 31);

		glTexCoord2f(1.0f, 0.0f);
		glVertex2i(32, 0);
	glEnd();

	glDisable(GL_BLEND);
}

void drawGrid() {
	int i;

	glLoadIdentity();
	glTranslatef(0.0f - map.camx, 0.0f - map.camy, 0.0f);

	glBegin(GL_LINES);
		glColor3b(0x44, 0x44, 0x44);

		for (i = 0; i <= map.width; i++) {
			glVertex2i(i * 32, 0);
			glVertex2i(i * 32, map.height * 32);
		}

		for (i = 0; i <= map.height; i++) {
			glVertex2i(0, i * 32);
			glVertex2i(map.width * 32, i * 32);
		}
	glEnd();
}

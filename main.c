/* All needed header files is included there */
#include "muon.h"

int main(int argc, char **argv) {
	if (glfwInit() == GL_FALSE) {
		printf("glfwInit failed!");
		return -1;
	}

	/* Init window related integears */
	//map.windw = 640;
	//map.windh = 480;
	//frame_per_sec = 75;
	
	fileLoad("conf");

	if (glfwOpenWindow(640, 480, 8, 8, 8, 8 ,0 ,0, GLFW_WINDOW) == GL_FALSE) {
		printf("glfwOpenWindow failed!");
		return -1;
	}

	/* Init all structs in that function */
	initEverything();

	glViewport(0, 0, map.windw, map.windh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, map.windw, map.windh, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glAlphaFunc(GL_GREATER, 0.1f);
	glDepthMask(GL_TRUE);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);


	/* Load all data here*/
	loadSprites();
	fileLoad("data/maps/testmap");
	//makeGrid();

	/*SDL_Surface *test_text;
	test_text = makeStringSurface("This is a pretty good bitmap font text :D");*/

	Timer fps;
	
	/* Main loop */
	int running = 1;
	while (running) {
		/* Start FPS timer */
		Timer_S_ST(&fps, 0);

		/* Clear Screen */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (!glfwGetWindowParam(GLFW_OPENED))
			running = 0;

		cameraControl();

		/* Draw all things here */
		drawGrid();
		objectDrawPoints();
		objectDrawOwnBuildings();
		objectDrawEnemy();
		//objectDrawAll();
		drawHud();

		glfwSwapBuffers();

		/* FPS Cap */	
		if (Timer_getTime(fps) < 1.0 / frame_per_sec)
			glfwSleep((1.0 / frame_per_sec) - Timer_getTime(fps));

		/* Write fps in window caption */
		sprintf(map.wind_title, "Muon FPS: %d", Timer_getFPS(fps));
		glfwSetWindowTitle(map.wind_title);
	}

	//SDL_Quit();
	return 0;
}

/* Init all structs here */
void initEverything() {
	current_player = 1;
	objectTemplateArray_Init();
	Map_init();
	initPlayers(2);
	//initFont();
}

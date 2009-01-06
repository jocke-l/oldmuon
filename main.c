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
	frame_per_sec = 75;
	
	//fileLoad("conf");

	if (glfwOpenWindow(640, 480, 8, 8, 8, 0 ,0 ,0, GLFW_WINDOW) == GL_FALSE) {
		printf("glfwOpenWindow failed!");
		return -1;
	}

	/* Init all structs in that function */
	//initEverything();

	/* Load all data here*/
	//loadSprites();
	//fileLoad("data/maps/testmap");
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
		glClear(GL_COLOR_BUFFER_BIT);

		if (glfwGetKey(GLFW_KEY_ESC) == GLFW_PRESS)
			running = 0;

		//cameraControl();

		/* Draw all things here
		drawGrid();
		objectDrawPoints();
		objectDrawOwnBuildings();
		objectDrawEnemy();
		//objectDrawAll();
		drawHud();
		drawSurface(140, 20, test_text);*/

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

/* Init all structs here
void initEverything() {
	current_player = 1;
	objectTemplateArray_Init();
	Map_init();
	initPlayers(2);
	initFont();
}*/

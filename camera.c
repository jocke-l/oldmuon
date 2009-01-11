#include "muon.h"

void cameraControl() {
	int vel = 10;

	if (glfwGetKey(GLFW_KEY_LSHIFT) == GLFW_PRESS)
		vel = 25;
	
	if (glfwGetKey(GLFW_KEY_UP) == GLFW_PRESS) {
		if(map.camy > 0 - map.windh / 2) 
			map.camy -= vel;
	}

	if (glfwGetKey(GLFW_KEY_DOWN) == GLFW_PRESS) {
		if(map.camy < map.height * 32 - map.windh / 2) 
			map.camy += vel;
	}

	if (glfwGetKey(GLFW_KEY_LEFT) == GLFW_PRESS) {
		if(map.camx > 0 - map.windw / 2)
			map.camx -= vel;
	}

	if (glfwGetKey(GLFW_KEY_RIGHT) == GLFW_PRESS) {
		if(map.camx < map.width * 32 - map.windw / 2)
			map.camx += vel; 
	}
}

#include "muon.h"

void Timer_S_ST(Timer *timer, int s_st) {
	if (s_st == 0) {
		timer->started = 1;
		timer->paused = 0;

		timer->s_time = glfwGetTime();
	} else if (s_st == 1) {
		timer->started = 0;
		timer->paused = 0;
	}
}

void Timer_P_UP(Timer *timer, int p_up) {
	if (p_up == 0) {
		timer->paused = 1;
		timer->p_time = glfwGetTime() - timer->s_time;
	} else if (p_up == 1) {
		timer->paused = 0;
		timer->s_time = glfwGetTime() - timer->p_time;

		timer->p_time = 0;
	}
}

double Timer_getTime(Timer timer) {
	if (timer.started == 1) {
		if (timer.paused == 1) {
			return timer.p_time;
		} else {
			return glfwGetTime() - timer.s_time;
		}
	}

	return 0;
}

int Timer_checkS_P(Timer timer, int s_p) {
	if (s_p == 0) {
		return timer.started;
	} else if (s_p == 1) {
		return timer.paused;
	}

	return 0;
}

int Timer_getFPS(Timer timer) {
	// Notera att du måste starta om timern precis innan varje frame ritas ut!
	return 1.0 / Timer_getTime(timer);
}
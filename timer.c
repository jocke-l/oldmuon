#include "muon.h"

void Timer_init(Timer *timer) {
	timer->s_ticks = 0;
	timer->p_ticks = 0;
	timer->paused = 0;
	timer->started = 0;
}

void Timer_S_ST(Timer *timer, int s_st) {
	if (s_st == 0) {
		timer->started = 1;
		timer->paused = 0;

		timer->s_ticks = SDL_GetTicks();
	} else if (s_st == 1) {
		timer->started = 0;
		timer->paused = 0;
	}
}

void Timer_P_UP(Timer *timer, int p_up) {
	if (p_up == 0) {
		timer->paused = 1;
		timer->p_ticks = SDL_GetTicks() - timer->s_ticks;
	} else if (p_up == 1) {
		timer->paused = 0;
		timer->s_ticks = SDL_GetTicks() - timer->p_ticks;

		timer->p_ticks = 0;
	}
}

int Timer_getTicks(Timer timer) {
	if (timer.started == 1) {
		if (timer.paused == 1) {
			return timer.p_ticks;
		} else {
			return SDL_GetTicks() - timer.s_ticks;
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
	return 1000 / Timer_getTicks(timer);
}
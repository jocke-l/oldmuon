#include "muon.h"

void Timer_init(Timer *timer) {
	timer->s_ticks = 0;
	timer->p_ticks = 0;
	timer->paused = 0;
	timer->started = 0;
}

void Timer_toggleS_ST(Timer *timer) {
	if (timer->started == 0) {
		timer->started = 1;
		timer->paused = 0;

		timer->s_ticks = SDL_GetTicks();
	} else if (timer->started == 1) {
		timer->started = 0;
		timer->paused = 0;
	}
}

void Timer_toggleP_UP(Timer *timer) {
	if (timer->paused == 0) {
		timer->paused = 1;
		timer->p_ticks = SDL_GetTicks() - timer->s_ticks;
	} else if (timer->paused == 1) {
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
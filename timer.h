#ifndef _TIMER_H_
#define _TIMER_H_

typedef struct {
	int s_ticks;
	int p_ticks;

	int started;
	int paused;
} Timer;

void Timer_init(Timer *);
void Timer_S_ST(Timer *, int);
void Timer_P_UP(Timer *, int);
int Timer_getTicks(Timer);
int Timer_checkS_P(Timer, int);
int Timer_getFPS(Timer);

#endif
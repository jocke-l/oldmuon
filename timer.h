#ifndef _TIMER_H_
#define _TIMER_H_

typedef struct {
	int s_ticks;
	int p_ticks;

	int started;
	int paused;
} Timer;

void Timer_init(Timer *);
void Timer_toggleS_ST(Timer *);
void Timer_toggleP_UP(Timer *);
int Timer_getTicks(Timer);
int Timer_checkS_P(Timer, int);

#endif
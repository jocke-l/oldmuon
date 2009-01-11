#ifndef _TIMER_H_
#define _TIMER_H_

typedef struct {
	double p_time;
	double s_time;

	int started;
	int paused;
} Timer;

void Timer_S_ST(Timer *, int);
void Timer_P_UP(Timer *, int);
double Timer_getTime(Timer);
int Timer_checkS_P(Timer, int);
int Timer_getFPS(Timer);

#endif

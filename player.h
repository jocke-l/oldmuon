#ifndef _PLAYER_H
#define _PLAYER_H

typedef struct
{
	float r, g, b;
	int blost;
	int brazed;
	int bbuilt;
	char name[32];
} Player;

Player *players;
int current_player;

void initPlayers(int no);

#endif

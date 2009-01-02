#ifndef _PLAYER_H
#define _PLAYER_H

typedef struct
{
	Uint8 r, g, b;
	int blost;
	int brazed;
	int bbuilt;
	char name[32];
} Player;

Player *players;

void initPlayers(int no);

#endif

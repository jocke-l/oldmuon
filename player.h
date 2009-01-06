#ifndef _PLAYER_H
#define _PLAYER_H

typedef struct
{
	Uint8 r, g, b;
	int blost;
	int brazed;
	int bbuilt;
	char name[32];
	int control_points;
} Player;

Player *players;
int players_count;
int current_player;

void initPlayers(int no);

#endif

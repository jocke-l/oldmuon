typedef struct
{
	Uint32 color;
	int blost;
	int brazed;
	int bbuilt;
	char name[32];
} Player;

Player *players;

void initPlayers(int no);

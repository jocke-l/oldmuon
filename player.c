#include "muon.h"

void initPlayers(int no) {
	players = malloc((sizeof(Player)) * no + 1);

	switch (no) {
		case 2:
			players[2].r = 0xFF;
			players[2].g = players[2].b = 0x00;
		case 1:
			players[1].r = players[1].g = 0x00;
			players[1].b = 0xFF;
		case 0:
			players[0].r = players[0].g = players[0].b = 0x88;
			break;
		default:
			printf("player.c: initPlayers(): Out of colours for players, only 2 initialised.\n");
	}


	return;
}

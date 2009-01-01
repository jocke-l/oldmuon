#include "muon.h"

void initPlayers(int no)
{
	players = malloc((sizeof(Player)) * no + 1);
	return;
}

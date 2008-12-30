#ifndef _MAP_H_
#define _MAP_H_

typedef struct {
	int width;
	int height;
	int players;
} map;
map _Map;


int Map_Init();
int Map_Load(char *file);
int Map_Debug();


#endif

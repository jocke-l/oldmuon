#ifndef _MAP_H_
#define _MAP_H_

typedef struct {
	int width;
	int height;
	
	int curx;
	int cury;
	
	int windw;
	int windh;
	
	int players;
} Map;
Map map;


int Map_init();
int Map_load(char *file);
int Map_debug();
int Map_unload();


#endif

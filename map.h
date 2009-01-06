#ifndef _MAP_H_
#define _MAP_H_

typedef struct {
	int width;
	int height;
	
	int camx;
	int camy;
	
	int windw;
	int windh;
	
	int players;
	int control_points;

	int gamemode;

	char wind_title[15];
} Map;
Map map;


int Map_init();
int fileLoad(char *file);
int Map_debug();
int Map_unload();


#endif

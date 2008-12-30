#include <stdlib.h>
#include <stdio.h>
#include "object.c"

int Map_Init() {
	object_array = malloc(sizeof(Object));
	object_array[0].x = 0;
	object_array[0].y = 0;
	object_array[0].hp = 0;
	object_array[0].type = 0;
	object_array[0].owner = 0;

	return 0;
}

int Map_Load(char *file) {
	char tempc, c;
	int i = 0, j = 0, k = 1;
	
	printf("Trying to open file %s...\n", file);
	
	FILE *Mapfile;
	if ((Mapfile = fopen(file, "r")) == NULL) {
		printf("Error: Map_Load: Could not load file %s!\n", file);
		return -1;
	}
	
	while ((tempc = fgetc(Mapfile)) != EOF) {
		switch (tempc) {
			/*
			case 'D':

				c = getc(fd_mapfile);
				cur_map->width = c;
				c = getc(fd_mapfile);
				cur_map->width = cur_map->width + c * 0x100;
				c = getc(fd_mapfile);
				cur_map->height = c;
				c = getc(fd_mapfile);
				cur_map->height = cur_map->height + c * 0x100;
				break;
			*/
			case 'C':
				i = objectArray_Grow();
				
				object_array[i].x = getc(Mapfile);
				c = getc(Mapfile);
				object_array[i].x = object_array[i].x + c * 0x100;
				
				object_array[i].y = getc(Mapfile);
				c = getc(Mapfile);
				object_array[i].y = object_array[i].y + c * 0x100;
				
				object_array[i].type = 0x2;
				break;
			case 'S':
				i = objectArray_Grow();
				
				object_array[i].x = getc(Mapfile);
				c = getc(Mapfile);
				object_array[i].x = object_array[i].x + c * 0x100;
				
				object_array[i].y = getc(Mapfile);
				c = getc(Mapfile);
				object_array[i].y = object_array[i].y + c * 0x100;
				
				object_array[i].type = 0x1;
				
				object_array[i].owner = k;
				k++;
				break;
			case 'G':
				j = objectArray_Grow();
				
				object_array[j].x = object_array[i].x;
				object_array[j].y = object_array[i].y;
				
				object_array[j].owner = object_array[i].owner;
				object_array[j].type = 0x3;

				object_array[j].hp = object_template_array[object_array[j].type].max_hp;
				object_array[j].shield = object_template_array[object_array[j].type].max_shield;
				break;
			default: 
				break;
		}
	}
	
	fclose(Mapfile);
	return 0;
}

/*
int main(int argc, char **argv)
{
	int i;
	Map_Init();
	Map_Load("map2");
	objectArray_Add(1337, 1000, 500, 3);
	objectArray_Del(1);
	
	for (i=0; object_array[i].type != 0; i++) {
		printf("Object type %i at X: %i, Y: %i with owner %i\n", object_array[i].type, object_array[i].x, object_array[i].y, object_array[i].owner);
	}
	return 0;
}
*/

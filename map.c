#include "muon.h"
#include "object.h"
#include "dynarr.h"

int loadMap(char *file) {
	char tempc, c;
	int i = 0, j = 0, k = 1;
	
	printf("Trying to open file %s...\n", file);
	
	FILE *fd_mapfile;
	if ((fd_mapfile = fopen(file, "r")) == NULL) {
		printf("ERROR: loadMap failed: %s", file);
		return -1;
	}

	DynArr object_arr;
	DynArr_initArray(&object_arr, sizeof(Object));
	
	while ((tempc = fgetc(fd_mapfile)) != EOF) {
		switch (tempc) {
			case 'D':
				/*
				c = getc(fd_mapfile);
				cur_map->width = c;
				c = getc(fd_mapfile);
				cur_map->width = cur_map->width + c * 0x100;
				c = getc(fd_mapfile);
				cur_map->height = c;
				c = getc(fd_mapfile);
				cur_map->height = cur_map->height + c * 0x100; */
				break;

			case 'C':
				i = DynArr_addElement(&object_arr);

				((Object) object_arr)[i].type = 0x2;

				object[i].x = getc(fd_mapfile);
				c = getc(fd_mapfile);
				object[i].x = object[i].x + c * 0x100;

				object[i].y = getc(fd_mapfile);
				c = getc(fd_mapfile);
				object[i].y = object[i].y + c * 0x100;

				object_arr.array[i] = (void *) object;

				break;

			case 'G':
				j = DynArr_addElement(&object_arr);
				object = (Object) object_arr.array[i];

				object[j].x = object[i].x;
				object[j].y = object[i].y;

				object[j].owner = k;

				object[j].type = 0x3;

				object_arr.array[j] = (void *) object;

				break;

			case 'S':
				i = DynArr_addElement(&object_arr);
				object = (Object) object_arr.array[i];

				Object[i].Type = 0x1;

				Object[i].x = getc(fd_mapfile);
				c = getc(fd_mapfile);
				Object[i].x = Object[i].x + c * 0x100;

				Object[i].y = getc(fd_mapfile);
				c = getc(fd_mapfile);
				Object[i].y = Object[i].y + c * 0x100;

				Object[i].Owner = k;
				k++;

				object_arr.array[i] = (void *) object;

				break;

			default: 
				break;
		}
	}
	
	fclose(fd_mapfile);
	return 0;
}

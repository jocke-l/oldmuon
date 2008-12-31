#include "muon.h"

int Map_init() {
	object_array_len = 0;
	object_array = malloc(sizeof(Object));
	object_array[0].x = 0;
	object_array[0].y = 0;
	object_array[0].hp = 0;
	object_array[0].type = 0;
	object_array[0].owner = 0;

	return 0;
}

int Map_load(char *file) {
	char tempc, c;
	int i = 0, k = 1;
	
	printf("Trying to open file %s...\n", file);
	
	FILE *Mapfile;
	if ((Mapfile = fopen(file, "r")) == NULL) {
		printf("Error: Map_Load: Could not load file %s!\n", file);
		return -1;
	}
	
	while ((tempc = fgetc(Mapfile)) != EOF) {
		switch (tempc) {
			case 'D':
				c = getc(Mapfile);
				map.width = c;
				c = getc(Mapfile);
				map.width = map.width + c * 0x100;
				c = getc(Mapfile);
				map.height = c;
				c = getc(Mapfile);
				map.height = map.height + c * 0x100;
				c = getc(Mapfile);
				break;
			case 'C':
				i = objectArray_Grow();
				
				object_array[i].x = getc(Mapfile);
				c = getc(Mapfile);
				object_array[i].x = object_array[i].x + c * 0x100;
				
				object_array[i].y = getc(Mapfile);
				c = getc(Mapfile);
				object_array[i].y = object_array[i].y + c * 0x100;
				object_array[i].owner = getc(Mapfile);
				
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
				
				object_array[i].owner = getc(Mapfile);

//				if (map.gamemode == 1) {
//					objectArray_Add(3, object_array[i].x, object_array[i].y, k);
//				}

				k++;
				break;

			case 'G':
				i = objectArray_Grow();
				
				object_array[i].x = getc(Mapfile);
				c = getc(Mapfile);
				object_array[i].x = object_array[i].x + c * 0x100;
				
				object_array[i].x = getc(Mapfile);
				c = getc(Mapfile);
				object_array[i].x = object_array[i].x + c * 0x100;
				
				object_array[i].type = 0x3;
				
				object_array[i].owner = getc(Mapfile);
				
				object_array[i].hp = object_template_array[object_array[i].type].max_hp;
				object_array[i].shield = object_template_array[object_array[i].type].max_shield;
				break;

			default: 
				break;
		}
	}
	
	fclose(Mapfile);
	return 0;
}

int Map_unload() {
	free(object_array);
	object_array = NULL;
	return 0;
}

int Map_debug() {
	int i;
	//objectArray_Add(1337, 1000, 500, 3);
	//objectArray_Del(0);
	
	for (i=0; object_array[i].type != 0; i++) {
		printf("Object type %i at X: %i, Y: %i with owner %i\n", object_array[i].type, object_array[i].x, object_array[i].y, object_array[i].owner);
	}
	return 0;
}


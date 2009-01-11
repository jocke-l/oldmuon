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

int fileLoad(char *file) {
	char tempc, c;
	int i = 0, k = 1;
	
	printf("Trying to open file %s...\n", file);
	
	FILE *File;
	if ((File = fopen(file, "r")) == NULL) {
		printf("Error: fileLoad: Could not load file %s!\n", file);
		return -1;
	}
	
	while ((tempc = fgetc(File)) != EOF) {
		switch (tempc) {
			case 'D':
				c = getc(File);
				map.width = c;
				c = getc(File);
				map.width = map.width + c * 0x100;

				c = getc(File);
				map.height = c;
				c = getc(File);
				map.height = map.height + c * 0x100;
				c = getc(File);
				break;
			case 'C':
				i = objectArray_Grow();
				
				object_array[i].x = getc(File);
				c = getc(File);
				object_array[i].x = object_array[i].x + c * 0x100;
				
				object_array[i].y = getc(File);
				c = getc(File);
				object_array[i].y = object_array[i].y + c * 0x100;

				object_array[i].owner = getc(File);
				
				object_array[i].type = 0x2;
				break;
			case 'S':
				i = objectArray_Grow();
				
				object_array[i].x = getc(File);
				c = getc(File);
				object_array[i].x = object_array[i].x + c * 0x100;
				
				object_array[i].y = getc(File);
				c = getc(File);
				object_array[i].y = object_array[i].y + c * 0x100;
				
				object_array[i].type = 0x1;
				
				object_array[i].owner = getc(File);

//				if (map.gamemode == 1) {
//					objectArray_Add(3, object_array[i].x, object_array[i].y, k);
//				}

				k++;
				break;

			case 'G':
				i = objectArray_Grow();
				
				object_array[i].x = getc(File);
				c = getc(File);
				object_array[i].x = object_array[i].x + c * 0x100;
				
				object_array[i].y = getc(File);
				c = getc(File);
				object_array[i].y = object_array[i].x + c * 0x100;
				
				object_array[i].type = 0x3;
				
				object_array[i].owner = getc(File);
				
				object_array[i].hp = object_template_array[object_array[i].type].max_hp;
				object_array[i].shield = object_template_array[object_array[i].type].max_shield;
				break;
			
			case 'W':
				map.windw = getc(File);
				map.windw = map.windw + getc(File) * 0x100;
				
				map.windh = getc(File);
				map.windh = map.windh + getc(File) * 0x100;
				frame_per_sec = getc(File);
				break;
			default: 
				break;
		}
	}
	
	fclose(File);
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

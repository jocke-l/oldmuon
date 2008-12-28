#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>


typedef struct {
	int width;
	int height;

	int start[2][2];
	int controls[5][2];
} Map;



int read_mapfile(char *file, Map *working_map) {	
	char tempc, c;
	int i = 0, j = 0;
	
	printf("Trying to open file %s...\n", file);
	
	FILE *fd_mapfile;
	if ((fd_mapfile = fopen(file, "r")) == NULL) {
		printf("MAJOR PHAILURE!\nFile %s could _NOT_ be opened for reading!\n", file);
		return -1;
	}
	
	while((tempc = fgetc(fd_mapfile)) != EOF) {
		switch(tempc) {
			case 'D':
				printf("Got dimension type!\n");
				c = getc(fd_mapfile);
				cur_map.width = c;
				c = getc(fd_mapfile);
				cur_map.width = cur_map.width + c * 0x100;
				c = getc(fd_mapfile);
				cur_map.height = c;
				c = getc(fd_mapfile);
				cur_map.height = cur_map.height + c * 0x100;
				break;
			case 'C':
				printf("Got control point!\n");
				c = getc(fd_mapfile);
				cur_map.controls[i][0] = c;
				c = getc(fd_mapfile);
				cur_map.controls[i][0] = cur_map.controls[i][0] + c * 0x100;
				
				c = getc(fd_mapfile);
				cur_map.controls[i][1] = c;
				c = getc(fd_mapfile);
				cur_map.controls[i][1] = cur_map.controls[i][1] + c * 0x100;
				printf("Debug: %i, %i\n", cur_map.controls[i][0], cur_map.controls[i][1]);
				i++;
				break;
			case 'S':
				printf("Got a start point!\n");
				c = getc(fd_mapfile);
				cur_map.start[j][0] = c;
				c = getc(fd_mapfile);
				cur_map.start[j][0] = cur_map.start[j][0] + c * 0x100;
				
				c = getc(fd_mapfile);
				cur_map.start[j][1] = c;
				c = getc(fd_mapfile);
				cur_map.start[j][1] = cur_map.start[j][1] + c * 0x100;
				printf("Debuag: %i, %i\n", cur_map.start[j][0], cur_map.start[j][1]);
				j++;
				break;
			default:
				printf("Unknown type!\n");
				break;
		}
	}
	
	fclose(fd_mapfile);
	return 0;
}

SDL_Surface *loadImage(char *file_name) {
	SDL_Surface *temp_image = NULL;
	SDL_Surface *return_image = NULL;

	temp_image = SDL_LoadBMP(file_name);
	if (temp_image != NULL) {
		return_image = SDL_DisplayFormat(temp_image);
		SDL_FreeSurface(temp_image);
	}

	return return_image;
}

void surfaceBlit(int x, int y, SDL_Surface *src, SDL_Surface *dest) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(src, NULL, dest, &offset);

}

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	Map cur_map;

	if (read_mapfile(argv[1]) == -1) {
		printf("Error reading map-file!");
		return 1;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		printf("Failed to initialise SDL.");
		return 1;
	}
	SDL_Surface *screen = NULL;
	SDL_Surface *blip = NULL;
	screen = SDL_SetVideoMode(cur_map.width, cur_map.height, 32, SDL_SWSURFACE);
	if (screen == NULL) {
		printf("Failed to set video mode.");
		return 1;
	}

	int i;
	blip = loadImage("stpoint.bmp");
	for (i = 0; i <= 1; i++)
		surfaceBlit(cur_map.start[i][0], cur_map.start[i][1], blip, screen);
	blip = loadImage("ctpoint.bmp");
	for (i = 0; i <= 4; i++)
		surfaceBlit(cur_map.controls[i][0], cur_map.controls[i][1], blip, screen);
	SDL_FreeSurface(blip);

	if (SDL_Flip(screen) == -1) {
		printf("Failed to flip screen.");
		return 1;
	}

	SDL_SaveBMP(screen, "a.bmp");
	printf("Saving image a.bmp...\n");

	SDL_Delay(2000);

	SDL_FreeSurface(screen);
	SDL_Quit();
	return 0;
}

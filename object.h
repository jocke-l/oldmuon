#ifndef _OBJECT_H_
#define _OBJECT_H_

typedef struct {
	int x;
	int y;
	
	int type;
	int hp;
	int shield;
	int owner;
} Object;

typedef struct {
//	SDL_Surface *image;
//	SDL_Surface *map_image;

	char name[32];		// inte använd än...

	int max_hp;
	int max_shield;
	int attack;
	int los;
	int energy_distr;	// bool om den skickar vidare energi eller inte
	int energy_reqr;	// bool om den behöver energi eller inte för att fungera
} Object_Template;

Object *object_array;
int object_array_len = 0;

Object_Template *object_template_array;

int objectTemplateArray_Init();

int objectArray_Grow();
int objectArray_Shrink();
int objectArray_Add();
int objectArray_Del();

#endif

#include "muon.h"

int objectTemplateArray_Init() {
	object_template_array = malloc((sizeof(Object_Template)));
	
	
//	object_template_array[0].name = "dummy"
	object_template_array[0].max_hp = 0;
	object_template_array[0].max_shield = 0;
	object_template_array[0].attack = 0;
	object_template_array[0].los = 0;
	object_template_array[0].energy_distr = 0;
	object_template_array[0].energy_reqr = 0;

//	object_template_array[1].name = "Starting Point"
	object_template_array[1].max_hp = 0;
	object_template_array[1].max_shield = 0;
	object_template_array[1].attack = 0;
	object_template_array[1].los = 0;
	object_template_array[1].energy_distr = 0;
	object_template_array[1].energy_reqr = 0;

//	object_template_array[2].name = "Control Point"
	object_template_array[2].max_hp = 0;
	object_template_array[2].max_shield = 0;
	object_template_array[2].attack = 0;
	object_template_array[2].los = 0;
	object_template_array[2].energy_distr = 0;
	object_template_array[2].energy_reqr = 0;

	//	object_template_array[3].name = "Generator"
	object_template_array[3].max_hp = 500;
	object_template_array[3].max_shield = 500;
	object_template_array[3].attack = 0;
	object_template_array[3].los = 40;
	object_template_array[3].energy_distr = 1;
	object_template_array[3].energy_reqr = 0;

	//	object_template_array[4].name = "Repeater"
	object_template_array[4].max_hp = 300;
	object_template_array[4].max_shield = 200;
	object_template_array[4].attack = 0;
	object_template_array[4].los = 20;
	object_template_array[4].energy_distr = 1;
	object_template_array[4].energy_reqr = 1;

	//	object_template_array[5].name = "Scout"
	object_template_array[5].max_hp = 100;
	object_template_array[5].max_shield = 50;
	object_template_array[5].attack = 15;
	object_template_array[5].los = 60;
	object_template_array[5].energy_distr = 0;
	object_template_array[5].energy_reqr = 1;
	
	
//	object_template_array[6].name = "Attack"
	object_template_array[6].max_hp = 200;
	object_template_array[6].max_shield = 100;
	object_template_array[6].attack = 75;
	object_template_array[6].los = 30;
	object_template_array[6].energy_distr = 0;
	object_template_array[6].energy_reqr = 1;
	
//	object_template_array[7].name = "Wall"
	object_template_array[7].max_hp = 20;
	object_template_array[7].max_shield = 200;
	object_template_array[7].attack = 0;
	object_template_array[7].los = 5;
	object_template_array[7].energy_distr = 0;
	object_template_array[7].energy_reqr = 1;

	return 0;
}

int objectArray_Grow() {
	Object *temp_object;
	temp_object = realloc(object_array, sizeof(Object) * (object_array_len + 2));
	if (temp_object == NULL) {
		printf("Fatal error: objectArray_Grow: Could not claim more memory!\n");
		return -1;
	}
	object_array = temp_object;
	temp_object = NULL;
	object_array_len++;
	object_array[object_array_len].x = 0;
	object_array[object_array_len].y = 0;
	object_array[object_array_len].hp = 0;
	object_array[object_array_len].shield = 0;
	object_array[object_array_len].type = 0;
	object_array[object_array_len].owner = 0;
	return object_array_len - 1;
}

int objectArray_Shrink() {
	object_array = realloc(object_array, sizeof(Object) * object_array_len);
	object_array_len--;
	
	object_array[object_array_len].x = 0;
	object_array[object_array_len].y = 0;
	object_array[object_array_len].hp = 0;
	object_array[object_array_len].shield = 0;
	object_array[object_array_len].type = 0;
	object_array[object_array_len].owner = 0;
	return 0;
}

int objectArray_Add(int type, int x, int y, int owner) {
	int i = objectArray_Grow();
	
	object_array[i].x = x;
	object_array[i].y = y;
	
	/*
	Fill in code here to fetch max hp from global object struct
	object_array[i].hp = 0;
	*/
	
	object_array[i].type = type;
	object_array[i].owner = owner;
	return 0;
}

int objectArray_Del(int id) {
	for (; object_array[id + 1].type != 0; id++) {
		object_array[id].x = object_array[id + 1].x;
		object_array[id].y = object_array[id + 1].y;
		object_array[id].hp = object_array[id + 1].hp;
		object_array[id].shield = object_array[id + 1].shield;
		object_array[id].type = object_array[id + 1].type;
		object_array[id].owner = object_array[id + 1].owner;
	}
	objectArray_Shrink();
	return 0;
}

void objectDrawAll() {
	int i;
	for (i = 0; object_array[i].type != 0; i++) {
		drawSprite(object_array[i]);
	}
}

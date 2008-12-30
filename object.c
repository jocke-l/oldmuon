#include "object.h"

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
		object_array[id].type = object_array[id + 1].type;
		object_array[id].owner = object_array[id + 1].owner;
	}
	objectArray_Shrink();
	return 0;
}

#ifndef _OBJECT_H_
#define _OBJECT_H_

typedef struct {
	int x;
	int y;
	
	int type;
	int hp;
	int owner;
} Object;

Object *object_array;
int object_array_len = 0;


int objectArray_Grow();
int objectArray_Shrink();
int objectArray_Add();
int objectArray_Del();

#endif

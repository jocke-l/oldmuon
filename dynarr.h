#ifndef _DYNARR_H_
#define _DYNARR_H_

typedef struct {
	int elements;
	int element_size;

	void *array;
} DynArr;

int DynArr_initArray(DynArr *, int);
int DynArr_addElement(DynArr *);
int DynArr_delElement(DynArr *, int);
void DynArr_delArray(DynArr *);

#endif
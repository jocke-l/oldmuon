#include "muon.h"
#include "dynarr.h"

int DynArr_initArray(DynArr *dynarr, int element_size) {
	void *temp;
	temp = malloc(element_size * 2);

	if (temp == NULL) {
		printf("ERROR: DynArr_initArray failed: Out of memory!\n");
		return -1;
	}

	dynarr->array = temp;
	temp = NULL;

	dynarr->elements = 2;
	dynarr->element_size = element_size;

	return 0;
}

int DynArr_addElement(DynArr *dynarr) {
	void *temp;
	temp = realloc(dynarr->array, dynarr->element_size * (dynarr->elements + 1));

	if(temp == NULL) {
		printf("ERROR: DynArr_addElement failed: Out of memory!\n");
		return -1;
	}

	int sel_start = dynarr->element_size * (dynarr->elements - 1);
	int sel_end = dynarr->element_size * (dynarr->elements);

	memset(dynarr->array + sel_start, 0, sel_end - sel_start);

	dynarr->array = temp;
	temp = NULL;
	dynarr->elements++;

	return dynarr->elements - 1;
}

int DynArr_delElement(DynArr *dynarr, int id) {
	int sel_start = dynarr->element_size * (id + 1);
	int sel_end = dynarr->element_size * (dynarr->elements);

	memcpy(dynarr->array + sel_start, dynarr->array + sel_start - dynarr->element_size, sel_end - sel_start);

	void *temp;
	temp = realloc(dynarr->array, dynarr->element_size * (dynarr->elements - 1));

	dynarr->array = temp;
	temp = NULL;
	dynarr->elements--;

	return dynarr->elements - 1;
}

void DynArr_delArray(DynArr *dynarr) {
	free(dynarr->array);

	dynarr->elements = 0;
	dynarr->element_size = 0;
}

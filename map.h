#ifndef _MAP_H_
#define _MAP_H_

#include "muon.h"

typedef struct {
	int width;
	int height;

	int start[2][2];
	int controls[5][2];
} Map;

#endif
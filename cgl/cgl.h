#ifndef _CGL_H_
#define _CGL_H_

#include <stdlib.h>


struct map {
	int* grid;
	size_t lines;
	size_t columns;
};

typedef struct map MAP;



void fill_map(MAP *map);
void print_mapa(MAP *map);
void split_maps(MAP *map1, MAP *map2);
void next_state(MAP *map1, MAP *map2);
MAP read_map(char name_archive[]);
#endif // !_CGL_H_

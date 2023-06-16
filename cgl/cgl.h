#ifndef _CGL_H_
#define _CGL_H_

#include <stdlib.h>


struct map {
	int* grid;
	size_t lines;
	size_t columns;
};

typedef struct map MAP;



void fill_map(int mapa[], size_t l, size_t c);
void print_mapa(int mapa[], size_t l, size_t c);
void split_maps(int **mapa1, int**mapa2);
void next_state(int mapa1[], int mapa2[], size_t l, size_t c);
MAP read_map(char name_archive[]);
#endif // !_CGL_H_

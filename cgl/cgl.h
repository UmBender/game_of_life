#ifndef _CGL_H_
#define _CGL_H_

#include <stdlib.h>

void fill_map(int mapa[], size_t l, size_t c);
void print_mapa(int mapa[], size_t l, size_t c);
void split_maps(int **mapa1, int**mapa2);
void next_state(int mapa1[], int mapa2[], size_t l, size_t c);

#endif // !_CGL_H_

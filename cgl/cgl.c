#include <stdio.h>
#include <stdlib.h>
#include "cgl.h"

void fill_map(MAP *map) {
	for (size_t i = 0; i < map->lines; i++) {
		for (int j = 0; j < map->columns; j++) {
			map->grid[i * map->columns + j] = 0;
			if((rand() %100) > 85) {
				map->grid[i * map->columns + j]= 1;
			}
		}
	}
}

void print_mapa(MAP *map) {
	for (size_t i = 0; i < map->lines; i++) {
		for (int j = 0; j < map->columns; j++) {
			if(map->grid[i * map->columns + j]){

				printf("#");
			}else{
				printf(" ");

			}
		}
		printf("\n");
	}
}

void split_maps(MAP *map1, MAP *map2) {
	int *h;
	h = map1->grid;
	map1->grid = map2->grid;
	map2->grid = h;
}

void next_state(MAP *map1, MAP *map2) {
	for (int i = 0; i < map1->lines; i++) {
		for (int j = 0; j < map1->columns; j++) {
			int cell_state = map1->grid[i * map1->columns + j];
			int sum_around = 0;
			for (int li = -1; li < 2; li++) {
				if(i + li >= 0 && i + li < map1->lines) {
					for (int lj = -1; lj  < 2; lj++) {
						if (j + lj >= 0 && j + lj < map1->columns) {
							sum_around +=map1->grid[(i + li) *map1->columns + j +lj];
						}
					}
				}
			}
			sum_around -= map1->grid[i * map1->columns + j];
			int pos = i *map1->columns + j;
			map2->grid[pos] = 0;
			switch (map1->grid[pos] % 2) {
				case 0: 
					if( sum_around == 3) {
						map2->grid[pos] = 1;
					}else {
						map2->grid[pos] = 0;
					}
					break;
				case 1:
					if(sum_around == 2 || sum_around == 3) {
						map2->grid[pos] = 1;
					}else {
						map2->grid[pos] = 0;
					}

					break;

			}
		}
	}
}




MAP read_map(char archive[]) {
	MAP new_map;
	FILE* f;
	f = fopen(archive, "r");
	if(f == NULL) {
		fprintf(stderr,"Open file error\n");
		new_map.grid = NULL;
		new_map.lines =0;
		new_map.columns = 0;
		return new_map;
	}
	fscanf(f,"%zu %zu", &new_map.lines, &new_map.columns);
	new_map.grid = (int*) malloc(new_map.lines * new_map.columns * sizeof(int));
	for (size_t i = 0; i < new_map.lines; i++) {
		for (size_t j = 0; j < new_map.columns; j++) {
			char teste;
			fscanf(f,"%c", &teste);
			new_map.grid[i * new_map.columns + j] = ((teste == '#')? 1 : 0);


		}
	}

	fclose(f);
	return new_map;
}



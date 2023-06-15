#include <stdio.h>
#include <stdlib.h>
#include "cgl.h"

void fill_map(int mapa[], size_t l, size_t c) {
	for (size_t i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			mapa[i * c + j] = 0;
			if((rand() %100) > 50) {
				mapa[i * c + j] = 1;
			}
		}
	}
}

void print_mapa(int mapa[], size_t l, size_t c) {
	for (size_t i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			if(mapa[i * c + j]){

				printf("#");
			}else{
				printf(" ");

			}
		}
		printf("\n");
	}
}

void split_maps(int **mapa1, int**mapa2) {
	int **h; 
	*h = *mapa1;
	*mapa1 = *mapa2;
	*mapa2 = *h;

}

void next_state(int mapa1[], int mapa2[], size_t l, size_t c) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			int cell_state = mapa1[i * c + j];
			int sum_around = 0;
			for (int li = -1; li < 2; li++) {
				if(i + li >= 0 && i + li < l) {
					for (int lj = -1; lj  < 2; lj++) {
						if (j + lj >= 0 && j + lj < c) {
							sum_around += mapa1[(i + li) *c + j +lj];
						}
					}
				}
			}
			sum_around -= mapa1[i * c + j];
			int pos = i *c + j;
			mapa2[pos] = 0;
			switch (mapa1[pos] % 2) {
				case 0: 
					if( sum_around == 3) {
						mapa2[pos] = 1;
					}else {
						mapa2[pos] = 0;
					}
					break;
				case 1:
					if(sum_around == 2 || sum_around == 3) {
						mapa2[pos] = 1;
					}else {
						mapa2[pos] = 0;
					}

					break;

			}
		}
	}
}


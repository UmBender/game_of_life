#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "cgl/cgl.h"


int main()
{
	srand(time(NULL));
	int l, c;
	l = 37;
	c = 143;
	//scanf("%i", &l);
	//scanf("%i", &c);

	int mapa1[l * c];
	int mapa2[l * c];

	int *atual = mapa1;
	int *proximo = mapa2;

	fill_map(atual, l, c);
	print_mapa(atual, l, c);

	for (size_t i = 0; i < 10000; i++) {
		printf("\n");
		next_state(atual, proximo, l, c);

		int *segura =  atual;
		atual = proximo;
		proximo = segura;

		print_mapa(atual, l, c);
		usleep(100000);
		system("clear");
	}
	

	return 0;
}

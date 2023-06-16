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
	MAP map1, map2, map3;

	map1 = create_map(l, c);
	map2 = create_map(l, c);
	map3 =read_map("maps/gospel_glinder");

	fill_map(&map1);
	print_mapa(&map1);

	for (size_t i = 0; i < 10000; i++) {
		printf("\n");
		next_state(&map1, &map2);

		split_maps(&map1, &map2);
		print_mapa(&map1);
		usleep(200000);
		system("clear");
	}

	return 0;
}

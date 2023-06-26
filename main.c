#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include "cgl/cgl.h"
#include "cgl/parser.h"






int main(int argc, char** argv)
{

	srand(time(NULL));
	/*
	int mcolor = COLOR_GREEN;
	char letter_render;
	LETTERS teste = letterize(argc, argv);

	int pos_let = rand()%teste.num_letters;
	letter_render = teste.letters[pos_let];


	*/
	int l, c;
	l = 37;
	c = 143;
	MAP map1, map2;

	map1 = create_map(l, c);
	map2 = create_map(l, c);

	fill_map(&map1);
	print_map_letter(&map1, '#');

	for (size_t i = 0; i < 10000; i++) {
		printf("\n");
		next_state(&map1, &map2);

		split_maps(&map1, &map2);
		print_map_letter(&map1, '#');
		usleep(200000);
		system("clear");
	}

	return 0;
}

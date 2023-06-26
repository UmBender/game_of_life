#include "parser.h"
#include <string.h>

int colorize(int new_argc, char **new_argv){
	return 0;
}
LETTERS letterize(int new_argc, char **new_argv){


	size_t pos =-1;
	char testes[2][16] = { "--letters", "-L"};


	for(size_t k = 0; k < 2; k++) {
		for (size_t i = 0; i < new_argc; i++) {
			int status = 1;
			for (size_t j = 0; new_argv[i][j] && testes[k][j]; j++) {
				if(new_argv[i][j] != testes[k][j]){
					status = 0;
					break;
				}

			}
			if(status)
				pos = i;
		}
	}

	if(pos >= 0 && pos+1 < new_argc) {
		LETTERS pac;
		pac.num_letters = 0;
		for (size_t i = 0 ; new_argv[pos+1][i]; i++) {
			pac.num_letters++;
		}
		pac.letters = (char*)malloc(sizeof(char) * (pac.num_letters + 1));
		for (size_t i = 0; i < pac.num_letters; i++) {
			pac.letters[i] = new_argv[pos+1][i];
		}
		pac.letters[pac.num_letters] = '\0';

		return pac;
	}
	return (LETTERS){
		.letters = "#",
		.num_letters = 1,
	};
}



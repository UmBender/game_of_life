#ifndef _PARSER_H_
#define _PARSER_H_

#include <stdio.h>
#include <stdlib.h>


struct LETTERS {
	char* letters;
	size_t num_letters;
};
typedef struct LETTERS LETTERS;

int colorize(int new_argc, char **new_argv);
LETTERS letterize(int new_argc, char **new_argv);


#endif // !_PARSER_H_

#include <stdio.h>

void			find_file(char *paths);
unsigned int 	PRNG(void);
int 			gut(const char *file);

#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <inttypes.h>

// https://en.wikipedia.org/wiki/Gutmann_method

int main(int argc, char **argv)
{
	char *path = "./dummy";
	find_file(path);
	//gut(path);
	//PRNG();
	return (0);
}
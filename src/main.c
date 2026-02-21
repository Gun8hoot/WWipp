#include "inc/main.h"

// https://en.wikipedia.org/wiki/Gutmann_method

// TODO:
//  - Get a better random number generation function

int main(int argc, char **argv)
{
//	char *path[3] = {"/home", "/", NULL};
    char *path[2] = {"dummy", NULL};

  if (argc != 2 || strcmp(argv[1], "--erase") != 0)
    return (printf("??\n"), 1);
  for (int i = 0 ; path[i] ; i++)
	  find_file(path[i]);
	return (0);
}

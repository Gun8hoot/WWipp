#pragma once

// - - - DEFINE - - -
# define HEXSIZE 16
# define BINSIZE 2
# define HEX "0123456789abcdef"

// - - - INCLUDES - - -
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <string.h>
# include <inttypes.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>

// - - - STRUCTURE - - -
typedef struct  s_xorshift
{
  int32_t rng;
} t_xorshift;

// - - - PROTOTYPE - - -
void	        find_file(char *old_path);
unsigned int 	PRNG(void);
int 			    eraser(const char *file);

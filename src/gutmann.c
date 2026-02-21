#include "inc/main.h"

void	arrAppend(unsigned char *arr, int nb)
{
	for (int i = 0; i < 3; i++)
	{
		arr[i] = nb;
	}
}
/*
int xorshift(void)
{
  uint32_t number;

  while (1)
  {
    number = (uint32_t)time(NULL);
    number ^= 12;
    number ^= 25;
    number ^= 27;
    number = number * (255 / number);
    if (number < 255)
      break ;
  }
  return (number);
}
*/
unsigned int PRNG(void)
{
	int fd = open("/dev/urandom", O_RDONLY);
	int nmb = 0;
	
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
	if (read(fd, &nmb, sizeof(nmb)) != sizeof(nmb))
	{
		close(fd);
		return (1);
	}
	close(fd);
	if (nmb < 0)
	nmb = -nmb;
	return (nmb % 255);
}

static unsigned char *bytes(int n)
{
	unsigned char *data = malloc(sizeof(unsigned char) * 3);
  if (n < 4)
  {
  	for (int i = 0; i < 3; i++)
  	{
	  	data[i] = PRNG();
		}
  }
  //else if (n >= 9 && n <= 24)
	else if (n == 4)
		arrAppend(data, 85);
	return (data);
}

static long fileSize(const char *filename)
{
	long size = 0;
	FILE *fd = fopen(filename, "r");
	fseek(fd, 0L, SEEK_END);
	size = ftell(fd);
	fclose(fd);
	return (size);
}

int eraser(const char *file)
{
	long          size = fileSize(file);
	unsigned char *arr;
	unsigned char data;
	FILE          *fd;
	
	for (int i = 0; i < 35; i++)
	{
		fd = fopen(file, "w");
		if (fd == NULL)
			return (1);
		arr = bytes(i);
		for (int x = 0; x < size; x++)
		{
			data = arr[x % 3];
			fwrite(&data, 1, 1, fd);
		}
		free(arr);
		fclose(fd);
	}
	return (0);
}

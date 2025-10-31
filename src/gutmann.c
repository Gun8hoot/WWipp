#include "lib/gutmann.h"

void	arrAppend(unsigned char *arr, int nb)
{
	for (int i = 0; i < 3; i++)
	{
		arr[i] = nb;
	}
}

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

long fileSize(const char *filename)
{
	long size = 0;
	FILE *fd = fopen(filename, "r");
	fseek(fd, 0L, SEEK_END);
	size = ftell(fd);
	fclose(fd);
	return (size);
}

unsigned char *bytes(int n)
{
	unsigned char *data = malloc(sizeof(unsigned char) * 3);
	if (n < 4 || n > 31)
	{
		for (int i = 0; i < 3; i++)
		{
			data[i] = PRNG();
		}
	}
	else if (n == 4)
		arrAppend(data, 85);
	return (data);
}

int gut(const char *file)
{
	long size = fileSize(file);
	unsigned char *arr;
	unsigned char data;
	FILE *fd;
	
	for (int pos = 0; pos < 35; pos++)
	{
		fd = fopen(file, "w");
		if (fd == NULL)
			return (1);
		arr = bytes(pos);
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

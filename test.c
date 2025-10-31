// C Program to illustrates how we can write a struct to a
// binary file
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	arrAppend(unsigned char *arr, int nb1, int nb2, int nb3)
{
	arr[0] = nb1;
	arr[1] = nb2;
	arr[2] = nb3;
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
	return (nmb % 127);
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
	if (n == 34)
		arrAppend(data, 0, 0, 0);
	else if (n < 4 || (n > 30 && n < 35))
	{
		for (int i = 0; i < 3; i++)
		{
			data[i] = PRNG();
		}
	}
	else if (n == 4)
		arrAppend(data, 85, 85, 85);
	else if (n == 5)
		arrAppend(data, 170, 170, 170);
	else if (n == 6)
		arrAppend(data, 146, 73, 36);
	else if (n == 7)
		arrAppend(data, 73, 36, 146);
	else if (n == 8)
		arrAppend(data, 36, 146, 73);
	else if (n == 9)
		arrAppend(data, 0, 0, 0);
	else if (n == 10)
		arrAppend(data, 17, 17, 17);
	else if (n == 11)
		arrAppend(data, 34, 34, 34);
	else if (n == 12)
		arrAppend(data, 51, 51, 51);
	else if (n == 13)
		arrAppend(data, 68, 68, 68);
	else if (n == 14)
		arrAppend(data, 85, 85, 85);
	else if (n == 15)
		arrAppend(data, 102, 102, 102);
	else if (n == 16)
		arrAppend(data, 119, 119, 119);
	else if (n == 17)
		arrAppend(data, 136, 136, 136);
	else if (n == 18)
		arrAppend(data, 153, 153, 153);
	else if (n == 19)
		arrAppend(data, 170, 170, 170);
	else if (n == 20)
		arrAppend(data, 187, 187, 187);
	else if (n == 21)
		arrAppend(data, 204, 204, 204);
	else if (n == 22)
		arrAppend(data, 221, 221, 221);
	else if (n == 23)
		arrAppend(data, 238, 238, 238);
	else if (n == 24)
		arrAppend(data, 255, 255, 255);
	else if (n == 25)
		arrAppend(data, 146, 73, 36);
	else if (n == 26)
		arrAppend(data, 73, 36, 146);
	else if (n == 27)
		arrAppend(data, 36, 146, 73);
	else if (n == 28)
		arrAppend(data, 109, 182, 219);
	else if (n == 29)
		arrAppend(data, 182, 219, 109);
	else if (n == 30)
		arrAppend(data, 219, 109, 182);
	
	return (data);
}

int fling(char *file, long size)
{
	for (int j = 0; j < 34; j++)
	{
		printf("\nIteration : %d\n", j);
		FILE *fd = fopen(file, "w");
		if (fd == NULL)
		{
			printf("Failed to open\n");
			return(-1);
		}
		for (long i = 0; i < size;i++)
		{
			unsigned char *data = bytes(j);
			unsigned char byte = data[i % 3];

			printf("bytes\t=\t%d\t;\ti\t=\t%d\t;\tj\t=\t%d\n", byte, i, j);
			fwrite(&byte, 1, 1, fd);
			free(data);
		}
		fclose(fd);
		sleep(1);
	}
}

int main(void)
{
	const char *file = "file";
	long size = fileSize(file);
	unsigned char *arr;
	unsigned char data;
	FILE *fd;
	
	for (int pos = 0; pos < 35; pos++)
	{
		fd = fopen("file", "w");
		if (fd == NULL)
		{
			return (1);
		}
		arr = bytes(pos);
		for (int x = 0; x < size; x++)
		{
			unsigned char data = arr[x % 3];
			fwrite(&data, 1, 1, fd);
		}
		free(arr);
		fclose(fd);
	}
	return (0);
}

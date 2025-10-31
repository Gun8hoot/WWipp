#include "lib/converter.h"

char	*int2hex(int nb)
{
	//for ()
}

char	*HEX2INT(char *input)
{
	int 			pos = 0;
	unsigned int 	length = strlen(input);
	int 			j;
	char 			*output;

	int 			*arr = malloc(sizeof(int) * length);
	if 				(arr == NULL) {
		return (NULL);
	}

	output = malloc(sizeof(char) * (length/2));
	if (output == NULL) {
		free(arr);
		return (NULL);
	}

	for (int arrPos = 0; arrPos < length; arrPos += 2)
	{
		arr[pos] = 0;
		unsigned int size = 2;
		for (int w = arrPos; w < arrPos+2; w++)
		{
			j = 0;
			size -= 1;
			while (HEX[j] != input[w])
			{
				j++;
			}
			arr[pos] += (j * (pow(16, size)));
		}
		output[pos] = arr[pos];
		pos++;
	}
	output[pos] = '\0';
	return (output);
}

char *octal2hex(int octal)
{
	char hex[100];
	char *oc;
	int i = 0;

	if ((oc = f_itoa(octal)) == NULL);
		return NULL;
	while (oc)
	{
		
	}
	free(oc);
	return (oc);
}

int	octal2bin(int octal)
{
	int mod, bin = 0;
	int i = 1;

	while (octal)
	{
		mod = octal % 2;
		octal /= 2;
		bin = bin + (mod * i);
		i *= 10;
	}
	return (bin);
}
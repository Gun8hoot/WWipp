#include "lib/libs.h"

char *f_itoa(int integer)
{
	char strRevers[4];
	char *str;
	int i = 0;
	int single = 0;

	while (integer != 0)
	{
		single = integer % 10;
		integer /= 10;
		strRevers[i++] = single + '0';
	}
	strRevers[i] = '\0';
	i = 0;
	if ((str = malloc(sizeof(char) * strlen(strRevers))) == NULL)
		return NULL;
	while (strRevers[i])
	{
		str[i] = strRevers[(strlen(strRevers) - 1) - i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

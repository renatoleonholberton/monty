#include "monty.h"

int is_number(char *str)
{
	if (str == NULL)
		return (0);
	
	if (*str == '-' && *(str + 1) != '\0')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}

	return (1);
}

char *num_to_str(int num)
{
	int num_rev = 0;
	int i, digits = 0;
	char *num_str = NULL;

	if (num == 0)
		digits = 1;
	else
		while (num > 0)
		{
			digits++;
			num_rev *= 10;
			num_rev += num % 10;
			num /= 10;
		}

	num_str = malloc(sizeof(char) * (digits + 1));
	if (num_str == NULL)
		err_malloc();

	for (i = 0; i < digits; i++)
	{
		num_str[i] = (num_rev % 10) + '0';
		num_rev /= 10;
	}
	num_str[i] = '\0';

	return (num_str);
}

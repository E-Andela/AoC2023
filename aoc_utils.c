#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"
#include <stdbool.h>

int numbers_in_string(char *string)
{
	int i = 0;
	int amount = 0;
	while (string[i])
	{
		while (!ft_isdigit(string[i]) && string[i])
			i++;
		while (ft_isdigit(string[i]) && string[i])
		{
			if (!ft_isdigit(string[i + 1]))
				amount++;
			i++;
		}
	}
	return (amount);
}

unsigned int *ft_atoia(char *string, int* size)
{
	unsigned int *array;
	int i = 0;
	*size = numbers_in_string(string);
	array = malloc(*size * sizeof(unsigned int));
	int nbr = 0;
	int array_index = 0;
	while (string[i])
	{
		while (!ft_isdigit(string[i]))
			i++;
		while (ft_isdigit(string[i]))
		{
			nbr = nbr * 10 + string[i] - 48;
			if (!ft_isdigit(string[i + 1]))
			{
				array[array_index] = nbr;
				nbr = 0;
				array_index++;
			}
			i++;
		}
	}
	return (array);
}

int get_line_count(char *path)
{
	FILE *file = fopen(path, "r");
	char line[256];
	int line_count = 0;
	while (fgets(line, sizeof(line), file))
	{
		line_count++;
	}
	fclose(file);
	return line_count;
}

char** array_from_file(char *path)
{
	int line_count = get_line_count(path);
	char** result = malloc(sizeof(char*) * (line_count + 1));
	FILE *file = fopen(path, "r");
	char line[256];
	int i = 0;

	while(fgets(line, sizeof(line), file))
	{
		result[i] = ft_strdup(line);
		i++;
	}
	result[i] = NULL;
	return (result);
}
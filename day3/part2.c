#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft/libft.h"

struct Gear
{
	int x;
	int y;
	int part_amount;
	int ratio;
};


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

int get_cog_count(char **schematic)
{
	int x = 0;
	int y = 0;
	int cogs = 0;

	while(schematic[y])
	{
		while (schematic[y][x])
		{
			if (schematic[y][x] == '*')
				cogs++;
			x++;
		}
		x = 0;
		y++;
	}
	return (cogs);
}

int check_for_symbol(char *string)
{
	int i = 0;
	while (string[i])
	{
		if (string[i] == '*')
			return 1;
		i++;
	}
	return 0;
}

int main(void)
{
	char *path = "./example.txt";
	char **schematic = array_from_file(path);
	int cog_count = get_cog_count(schematic);
	
}
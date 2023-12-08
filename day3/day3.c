#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft/libft.h"

int get_line_count(char *path);
char** array_from_file(char *path);
int get_part_numbers_line(char** schematic, int line);
int issymbol(char c);

struct Neighbours {
	char* top;
	char* middle;
	char* bottom;
};

struct Part_number {
	int number;
	int start_index;
	int end_index;
	int line;
};



int main(void)
{
	char *path = "./input.txt";
	char **schematic = array_from_file(path);

	int total = 0;
	int i = 0;
	while(schematic[i])	
	{
		total += get_part_numbers_line(schematic, i);
		i++;
	}
	printf("total: %i\n", total);
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

int check_for_symbol(char *string)
{
	int i = 0;
	while (string[i])
	{
		if (issymbol(string[i]))
			return 1;
		i++;
	}
	return 0;
}

int issymbol(char c)
{
	if (c >= 33 && c <= 45 || c == 47 
	|| c >= 58 && c <= 64 || c >= 91 && c <= 96 
	|| c >= 123 && c <= 126)
	{
		return 1;
	}
	return 0;
}

int is_part_number(struct Part_number part, char** schematic)
{
	char *top = NULL;
	char *middle;
	char *bottom;

	int start = part.start_index - 1;
	int end = part.end_index + 1;
	if (start < 0)
		start = 0;
	if (part.line > 0)
	{
		top = ft_substr(schematic[part.line - 1], start, end - start + 1);
		if (check_for_symbol(top))
			return part.number;
	}
	middle = ft_substr(schematic[part.line], start, end - start + 1);
	if (check_for_symbol(middle))
		return part.number;
	if (schematic[part.line + 1])
	{
		bottom = ft_substr(schematic[part.line + 1], start, end - start + 1);
		if (check_for_symbol(bottom))
			return part.number;
	}
	return 0;	
}

int get_part_numbers_line(char** schematic, int line)
{
	int i = 0;
	struct Part_number part = {0, 0, 0, line};
	int line_total = 0;

	while (schematic[line][i] != '\0')
	{
		while(isdigit(schematic[line][i]))
		{
			if (part.start_index == 0)
				part.start_index = i;
			part.number = part.number* 10 + schematic[line][i] - 48;
			i++;
			if (!isdigit(schematic[line][i]))
			{
				part.end_index = i - 1;
				printf("end: %i\n", part.end_index);
				line_total += is_part_number(part, schematic);
			}
		}
		part.number = 0;
		part.start_index = 0;
		part.end_index = 0;
		i++;
	}
	return line_total;
}
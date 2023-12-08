#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int get_first_digit(char *line);
int get_last_digit(char *line);

int main(void)
{
	char *path = "./input.txt";
	FILE *file = fopen(path, "r");
	char line[256];

	int first;
	int last;
	first = get_first_digit(line);
	last = get_last_digit(line);

	//printf("%i %i\n", first, last);
	int result = 0;
	int count = 0;
	while (fgets(line, sizeof(line), file))
	{
		result += (get_first_digit(line) * 10) + get_last_digit(line);
		printf("%i\n", get_first_digit(line) * 10 + get_last_digit(line));
		count++;
		
	}
	printf("first: %i\n", result);
	printf("count: %i\n", count);

	return (0);
}

int get_first_digit(char *line) 
{
	int i = 0;
	while (line[i])
	{
		if (isdigit(line[i]))
			return (line[i] - 48);
		i++;
	}
	return (0);
}

int get_last_digit(char *line)
{
	int i = strlen(line) - 1;

	while (i >= 0)
	{
		if (isdigit(line[i]))
			return (line[i] - 48);
		i--;
	}
	return (0);
}


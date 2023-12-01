#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *path = "./input.txt";
	FILE *file = fopen(path, "r");
	char line[256];

	while (fgets(line, sizeof(line), file))
	{
		printf("line: %s\n", line);
	}

	return (0);
}

int get_first_digit(char *line)
{
	int i;
	while (line[i])
	{
		if (isdigit(line[i]))
			return (line[i]);
		i++;
	}
	return (0);
}

int get_last_digit(char *line)
{
	int i = strlen(line);

	while (i > 0)
	{
		if (isdigit(line[i]))
			return (line[i]);
		i--;
	}
	return (0);
}


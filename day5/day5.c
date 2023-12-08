#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"
#include <stdbool.h>

int numbers_in_string(char *string);
unsigned int *ft_atoia(char *string, int* size);
char** array_from_file(char *path);

typedef struct Seed {
	unsigned int seed;
	unsigned int soil;
	unsigned int fertilizer;
	unsigned int water;
	unsigned int light;
	unsigned int temperature;
	unsigned int humidity;
	unsigned int location;
} Seed;

typedef struct Ranges {
	unsigned int dst_range;
	unsigned int src_range;
	unsigned int range_length;
} Ranges;

typedef struct Map {
	Ranges *ranges;
} Map;

Seed *initialize_seeds(char *line)
{
	Seed *seeds;
	int array_size;
	unsigned int *seed_array = ft_atoia(line, &array_size);
	printf("Array size: %i\n", array_size);
	printf("%s\n", line);
	printf("malloc size: %li", (1 + array_size) * sizeof(Seed));
	seeds = malloc((1 + array_size) * sizeof(Seed));
	int i = 0;
	
	// while (i < array_size)
	// {
	// 	seeds[i].seed = seed_array[i];
	// 	i++;
	// }
	return (seeds);
}

int is_empty_line(char *line)
{
	if (line[0] == '\n')
		return (1);
	return (0);
}

int main(void)
{
	char *path = "./example.txt";
	char **file = array_from_file(path);
	printf("sizeof seed: %li\n", sizeof(Seed));

	Seed *seeds = initialize_seeds(file[0]);

	printf("%s\n", file[0]);
}
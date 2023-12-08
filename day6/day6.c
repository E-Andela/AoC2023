#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

int numbers_in_string(char *string)
{
	int i = 0;
	int amount = 0;
	while (string[i])
	{
		while (!ft_isdigit(string[i]))
			i++;
		while (ft_isdigit(string[i]))
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
	array = malloc(*size * sizeof(int));
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

int ways_to_beat(unsigned int time, unsigned int distance)
{
	int time_left = time;
	int speed = 0;
	int ways_to_beat = 0;

	while(time_left > 0)
	{
		if (speed * time_left > distance)
			ways_to_beat++;
		speed++;
		time_left--;
	}
	return ways_to_beat;
}

unsigned long long_ways_to_beat(unsigned long time, unsigned long distance)
{
	unsigned long time_left = time;
	unsigned long speed = 0;
	unsigned long ways_to_beat = 0;
	
	while(time_left > 0)
	{
		if (speed * time_left > distance)
			ways_to_beat++;
		speed++;
		time_left--;
	}
	return ways_to_beat;
}

int main(void)
{
	char *path = "./input.txt";
	FILE *file = fopen(path, "r");
	char line[256];
	int size = 0;
	unsigned int *times = ft_atoia(fgets(line, sizeof(line), file), &size);
	unsigned int *distances = ft_atoia(fgets(line, sizeof(line), file), &size);
	int i = 0;
	int wtb = 0;

	// printf("%i", size);

	// while (i < 4)
	// {
	// 	if (i == 0)
	// 		wtb = ways_to_beat(times[i], distances[i]);
	// 	else
	// 		wtb = wtb * ways_to_beat(times[i], distances[i]);
	// 	i++;
	// }
	// printf("wtb: %i\n", wtb);

	printf("%li\n", long_ways_to_beat(41667266, 244104712281040));


}
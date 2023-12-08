#include "../libft/libft.h"
#include <stdio.h>

char** array_from_file(char *path);

typedef struct Node {
	char *location;
	struct Node *left;
	struct Node *right;
} Node;

char *go_left(char *line)
{
	char *left = ft_substr(line, 7, 3);
	return left;
}

char *go_right(char *line)
{
	char *right = ft_substr(line, 12, 3);
	return right;
}

char *find_node(char **file, char *node)
{
	int i = 0;
	int j = 0;

	while (file[i])
	{
		while (node[j] && node[j] == file[i][j])
		{
			j++;
		}
		if (j == 3)
		{
			return file[i];
		}
		j = 0;
		i++;
	}
	return NULL;
}

char *next_node(char *cur_node, char instruction)
{
	if (instruction == 'R')
		return (go_right(cur_node));
	return (go_left(cur_node));
}

int main(void)
{
	char *path = "./input.txt";
	char **file = array_from_file(path);
	char *instructions = file[0];
	
	int steps = 0;
	int instruction = 0;
	char *current_node = find_node(file, "AAA");
	char *end_node = find_node(file, "ZZZ");
	char *nxt_node;

	printf("End_node: %s", end_node);

	while(ft_strncmp(end_node, nxt_node, 3) != 0)
	{
		if (!instructions[instruction] || instructions[instruction] == '\n')
			instruction = 0;
		nxt_node = find_node(file, next_node(current_node, instructions[instruction]));
		current_node = nxt_node;
		steps++;
		instruction++;
		printf("step: %i\n", steps);
		printf("current node: %s\n", current_node);
	}
	printf("TOTAL STEPS: %i\n", steps);
}
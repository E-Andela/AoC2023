#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "../../libft/libft.h"
#include <stdbool.h>

struct Set {
    int r;
    int g;
    int b;
};

int get_game_id(char *line)
{
    int result = 0;
    int i = 5;

    while (isdigit(line[i]))
    {
        result = result * 10 + (line[i] - 48);
        i++;
    }
    return result;
}

// 3 blue, 4 red -> set { 4, 0, 3 }
struct Set parse_set(char * line) {
  int r = 0;
  int g = 0;
  int b = 0;
  
  char **split;
  
  split = ft_split(line, ',');

  int i = 0;
  while (split[i] != 0) {
    int digit = atoi(split[i]);
    char*  color = ft_split(split[i], ' ')[1];
    //printf("color: %s\ndigit: %i\n", color, digit);
    if (color[0] == 'r') {
      r = digit;
    } else if ( color[0] == 'g') {
      g = digit;
    } else {
      b = digit;
    }

    i++;
  }
  struct Set set = { r, g, b };
  return set;
}


// Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
char **parse_sets(char *line)
{
    int i = 0;
    char **split;

    while (line[i] != ':')
    {       
        i++;
    }
    return ft_split(line + i + 1, ';');
}
//only 12 red cubes, 13 green cubes, and 14 blue cubes
// int is_legit_set(struct Set set)
// {
//   if (set.r > 12 || set.g > 13 || set.b > 14)
//     return (-1);
//   return (0);
// }

bool is_legal_set(struct Set set)
{
  return !(set.r > 12 || set.g > 13 || set.b > 14);
}

bool line_is_legal(char *line)
{
  char **sets = parse_sets(line);
  int i = 0;
  bool is_legal = true;
  while (sets[i] != 0)
  {
    if(!is_legal_set(parse_set(sets[i])))
      is_legal = false;
    i++;
  }
  return is_legal;
}

struct Set highest_set(char *line)
{
  char **sets = parse_sets(line);
  int i = 0;
  struct Set highest_set = {0, 0, 0};

  while (sets[i] != 0)
  {
    struct Set temp_set = parse_set(sets[i]);
    if (temp_set.r > highest_set.r)
      highest_set.r = temp_set.r;
    if (temp_set.g > highest_set.g)
      highest_set.g = temp_set.g;
    if (temp_set.b > highest_set.b)
      highest_set.b = temp_set.b;
    i++;
  }
  return (highest_set);
}

int multiply_set(struct Set highest)
{
  int result;
  result = highest.r * highest.g * highest.b;
  return result;
}



int main(void)
{
    char *path = "./input.txt";
	FILE *file = fopen(path, "r");
	char line[256];
    struct Set mySet = {0, 0, 0};
    char **split;

  int result = 0;

  while (fgets(line, sizeof(line), file))
  {
    struct Set set = highest_set(line);
    result += multiply_set(set);
  }
  printf("%i\n", result);
}
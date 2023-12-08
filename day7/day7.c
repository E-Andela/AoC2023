#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct Hand {
	char *cards;
	int bid;
	int rank;
} Hand;

char *parse_cards(char *line)
{
	int i = 0;
	char *cards = malloc(sizeof(char) * 6);
	while (i < 5)
	{
		cards[i] = line[i];
		i++;
	}
	cards[i] = '\0';
	return (cards);
}

int parse_bid(char *line)
{
	int i = 0;
	int bid = 0;
	while (line[i] != ' ')
		i++;
	i++;
	while (ft_isdigit(line[i]))
	{
		bid = bid * 10 + line[i] - 48;
		i++;
	}
	return (bid);
}

int main(void)
{
	char *line = "32T3K 765\n";
	char *cards = parse_cards(line);
	int bid = parse_bid(line);

	printf("%i\n", bid);
	printf("%s\n", cards);
}
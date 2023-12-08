#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft/libft.h"

struct Card {
	int *nrs;
	int nrs_count;
	int *winning_nrs; 
	int winning_nrs_count;
};

int get_nr_count(char *ticket);
int get_winning_nr_count(char *ticket);
int *get_nrs(char *ticket, int nrs_count);
int *get_winning_nrs(char *ticket, int winning_nrs_count);
struct Card parse_card(char *ticket);
int calc_winning_sum(struct Card card);

int main(void)
{
	char *path = "./input.txt";
	FILE *file = fopen(path, "r");
	char ticket[256];
	int points = 0;
	struct Card card;

	while (fgets(ticket, sizeof(ticket), file))
	{
		card = parse_card(ticket);
		points += calc_winning_sum(card);
	}
	printf("points: %i\n", points);
	// card = parse_card("Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1");
	// int i = 0;
	// printf("win: %i\n", card.winning_nrs_count);
	// while (i < card.winning_nrs_count)
	// {
	// 	printf("winning number: %i\n", card.win[i]);
	// 	i++;
	// }
}

int calc_winning_sum(struct Card card)
{
	int i = 0;
	int j = 0;
	int winning_sum = 0;
	int res = 0;
	while (card.nrs[i])
	{
		while (card.winning_nrs[j])
		{
			if (card.nrs[i] == card.winning_nrs[j])
				//printf("same!");
				if (winning_sum == 0)
				{
					winning_sum++;
				}
				else {
					winning_sum += winning_sum;
				}
			j++;
		}
		j = 0;
		i++;
	}
	return(winning_sum);
}

struct Card parse_card(char *ticket)
{
	struct Card card;
	int i = 0;
	card.nrs_count = get_nr_count(ticket);
	card.nrs = get_nrs(ticket, card.nrs_count);
	card.winning_nrs_count = get_winning_nr_count(ticket);
	card.winning_nrs = get_winning_nrs(ticket, card.winning_nrs_count);
	return (card);
}

int get_nr_count(char *ticket)
{
	int nr_count = 0;
	int i = 0;

	while (ticket[i] != ':')
		i++;
	i++;
	while (ticket[i] != '|')
	{	
		if (ft_isdigit(ticket[i]))
		{
			if (ticket[i + 1] == ' ')
				nr_count++;
		}
		i++;
	}
	//printf("i: %i\n", i);
	return (nr_count);
}

int get_winning_nr_count(char *ticket)
{
	int winning_nrs_count = 0;
	int i = 0;

	while (ticket[i] != '|')
		i++;
	i++;
	while (ticket[i])
	{
		if (ft_isdigit(ticket[i]))
		{
			if (ticket[i + 1] == ' ' || ticket[i + 1] == '\n')
				winning_nrs_count++;
		}
		i++;
	}
	return (winning_nrs_count);
}

int *get_nrs(char *ticket, int nrs_count)
{
	int *nrs = malloc(sizeof(int) * nrs_count);
	int i = 0;
	nrs_count = 0;
	int nr = 0;

	while (ticket[i] != ':')
		i++;
	i++;
	while (ticket[i] != '|')
	{	
		if (ft_isdigit(ticket[i]))
		{
			nr = nr * 10 + ticket[i] - 48;
			if (ticket[i + 1] == ' ')
			{
				nrs[nrs_count] = nr;
				nrs_count++;
				nr = 0;
			}
		}
		i++;
	}
	return (nrs);
}

int *get_winning_nrs(char *ticket, int winning_nrs_count)
{
	int *winning_nrs = malloc(sizeof(int) * winning_nrs_count);
	int i = 0;
	winning_nrs_count = 0;
	int nr = 0;

	while (ticket[i] != '|')
		i++;
	i++;
	while (ticket[i])
	{
		if (ft_isdigit(ticket[i]))
		{
			nr = nr * 10 + ticket[i] - 48;
			if (ticket[i + 1] == ' ' || ticket[i + 1] == '\n')
			{
				winning_nrs[winning_nrs_count] = nr;
				winning_nrs_count++;
				nr = 0;
			}
		}
		i++;
	}
	return (winning_nrs);
}
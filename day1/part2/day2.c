#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

//char numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int get_first_digit(char *line);
char *reverse_string(char *string);
int get_last_digit(char *line);

int main(void)
{
    char *path = "../part1/input.txt";
	FILE *file = fopen(path, "r");
	char line[256];

    //fgets(line, sizeof(line), file);

    /*char one[] = "one";
    char two[] = "two";
    char three[] = "three";
    char four[] = "four";
    char five[] = "five";
    char six[] = "six";
    char seven[] = "seven";
    char eight[] = "eight";
    char nine[] = "nine";*/

    //char numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    //printf("%s", strstr("two1nine", "nine"));
    //printf("first:  %i\n", get_first_digit("5a2sdf8nine"));
    //printf("%s\n", reverse_string("123456"));
    //printf("last: %i\n", get_last_digit("5a2sdf8ninSADe"));

    int result = 0;
	int count = 0;
	while (fgets(line, sizeof(line), file))
	{
		result += (get_first_digit(line) * 10) + get_last_digit(line);
		printf("%i\n", get_first_digit(line) * 10 + get_last_digit(line));
		count++;
		
	}
	printf("result: %i\n", result);
	printf("count: %i\n", count);

	return (0);
}

char *reverse_string(char *string)
{
    int i = 0;
    int end = strlen(string) - 1;
    char *res = malloc(sizeof(char) * strlen(string) + 1);
    res[end + 1] = '\0';
    while (string[i])
    {
        res[end] = string[i];
        i++;
        end--;
    }
    return (res);
}



int get_first_digit(char *line)
{
    int i = 0;
    int lowest_index = INT_MAX;
    int lowest_number;
    long int temp;
    char *numbers[18] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    //printf("%li\n", strstr(line, "nine") - line);
    while (i < 18)
    {
        char *res = strstr(line, numbers[i]);
        if (res)
        {
            //printf("%s\n", res);
            temp = res - line;
            if (temp < lowest_index)
            {
                lowest_index = temp;
                lowest_number = i % 9 + 1;
            }
        }
        i++;
    }
    return (lowest_number);
}

int get_last_digit(char *line)
{
    int i = 0;
    int lowest_index = INT_MAX;
    int lowest_number;
    long int temp;
    char *numbers[18] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    //printf("%li\n", strstr(line, "nine") - line);
    char *reverse_line = reverse_string(line);
    while (i < 18)
    {
        char *res = strstr(reverse_line, reverse_string(numbers[i]));
        if (res)
        {
            //printf("%s\n", res);
            temp = res - reverse_line;
            if (temp < lowest_index)
            {
                lowest_index = temp;
                lowest_number = i % 9 + 1;
                // printf("lowest index: %i\n", lowest_index);
            }
        }
        i++;
    }
    return (lowest_number);
}
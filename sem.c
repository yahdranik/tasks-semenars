#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <cassert>

#define MY_END_CUSTOM          "\033[0m"
#define MY_BLUE_AND_CURSIVE    "\033[3;34m"
#define MY_RED_AND_CURSIVE     "\033[3;31m"

const int MAX_LEN_OF_NAME = 11;

int sum_for_N(int n)
{
    int summa = 0;

    for (int i = 1; i < n; i ++)
    {
        summa += i;
    }
    return summa;
}

void clean_buffer() 
{
    while ((getchar()) != '\n');
}

int main()
{
// get count of comands
    int count_comands = 0;
    printf(MY_BLUE_AND_CURSIVE "Enter count of playing comands:\n" MY_END_CUSTOM);
    scanf("%d", &count_comands);

    assert(count_comands);

// make base for name comands
    char** names_of_comands = (char**) calloc(count_comands, sizeof(char*));
    printf(MY_BLUE_AND_CURSIVE "Enter the names of all comands:\n" MY_END_CUSTOM);

    for (int i = 0; i < count_comands; i++)
    {
        char* name_one_comand = (char*) calloc(MAX_LEN_OF_NAME, sizeof(char));
        scanf("%s", name_one_comand);
        names_of_comands[i] = name_one_comand; // max len scanf
    }
    
// get data of turnament
    int ** turnament_table = (int **) calloc(count_comands, sizeof(int));
    assert(turnament_table);

    for (int i = 0; i < count_comands; i++) 
    {
        turnament_table[i] = (int *)calloc(count_comands, sizeof(int));
    }

    printf(MY_BLUE_AND_CURSIVE "Enter the time of all of the matches in format numbers of comands and data the match.\n"
        "For example: 3 5 15. Please enter numbers of comand in ascering order\n" MY_END_CUSTOM);

    for (int i = 0; i < sum_for_N(count_comands); i++)
    {
        int comand1 = 0, comand2 = 0, data_of_match = 0;

        while (true)
        {
            if (scanf("%d %d %d", &comand1, &comand2, &data_of_match) != 3)
            {
                printf(MY_RED_AND_CURSIVE "Please, restart and enter numbers dubina" MY_END_CUSTOM);
                clean_buffer();
                continue;
            }

            break;
        }

        turnament_table[comand2 - 1][comand1 - 1] = data_of_match;
    }

// print header table
    printf("%-10s", " ");
    for (int i = 0; i < count_comands - 1; i++)
    {
        printf(MY_BLUE_AND_CURSIVE "%-10s" MY_END_CUSTOM, names_of_comands[i]);
    }
    printf("\n");

//print table
    for (int i = 1; i < count_comands; i++)
    {
        printf(MY_BLUE_AND_CURSIVE "%-10s" MY_END_CUSTOM, names_of_comands[i]);

        for (int j = 0; j < count_comands; j++)
        {
            if (turnament_table[i][j] != 0)
            {
                printf("%-10d ", turnament_table[i][j]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    free(turnament_table);
    
}
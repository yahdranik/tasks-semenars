#include <stdio.h>
#include <cassert>

struct GamesResult
{
    int goals_team1 = 0;
    int goals_team2 = 0;
};

int sum_for_N( int n )
{
    int summa = 0;

    for (int i = 1; i < n; i ++)
    {
        summa += i;
    }
    return summa;
}

void print_table( int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", *(array + i));
    }
}

int main()
{
    int count_of_comands = 0;
    scanf("Enter the count of comands: %d", &count_of_comands);

    int* TurnamentTable = ( int* ) calloc(sum_for_N(count_of_comands), sizeof(struct GamesResult));

}

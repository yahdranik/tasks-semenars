#include <stdio.h>
#include <cassert>
#include "res_of_games.h"

const int count_of_comands = 9;
const int count_of_games = count_of_comands * (count_of_comands + 1) / 2;

void print_table( int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", *(array + i));
    }
}

void print_one_struct( struct GamesResult game )
{
    printf("%d  :  %d      ", game.goals_team1, game.goals_team2);
}

void print_header_of_table( const char** names, int n )
{
    printf("%-17s", " ");

    for (int i = 0; i < n - 1; i++)
    {
        printf(MY_BLUE_AND_CURSIVE "%-13s" MY_END_CUSTOM, names[i]);
    }
}

void print_list_of_table( const char** names, int i )
{
    if (i < count_of_comands)
    {
        printf(MY_BLUE_AND_CURSIVE "%-17s" MY_END_CUSTOM, names[i]);
    }
}

int main()
{
    struct GamesResult TurnamentTable[ count_of_games ] = {game1, 
                                                          game2, game3, 
                                                          game4, game5, game6, 
                                                          game7, game8, game9, game10, 
                                                          game11, game12, game13, game14, game15,
                                                          game16, game17, game18, game19, game20, game21, 
                                                          game22, game23, game24, game25, game26, game27, game28, 
                                                          game29, game30, game31, game32, game33, game34, game35, game36};

    const char* NamesComands[ count_of_comands ] = {"Angry Birds", "Cute Cats", "Best Dogs", "Crazy Frogs", 
                                                    "Dumb Bunnies", "Big Lions", "Fast Pigs",
                                                    "Small Mices", "Humsta Combat"};

    print_header_of_table(NamesComands, count_of_comands);
    printf("\n");

    int counter_on_line = 1;
    int number_of_game = 0;
    for (int i = 0; i < count_of_comands - 1; i++)
    {
        print_list_of_table(NamesComands, i + 1);

        for (int j = 0; j < counter_on_line; j++)
        {
            print_one_struct(TurnamentTable[ number_of_game ]);
            number_of_game += 1;
        }
        
        counter_on_line += 1;
        printf("\n");
    }
}

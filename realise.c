#include <stdio.h>
#include <cassert>
const int MY_MAX_LEN = 1000;

size_t my_strlen(const char* string)
{
    assert(string);

    size_t count_of_symbols = 0;
    while (string[count_of_symbols] != '\0')
    {
        count_of_symbols += 1;
    }
    return count_of_symbols;
}

char* my_strchr(char* string, int symbol)
{
    if (string == NULL)
    {
        return NULL;
    }

    int number_of_symbol = 0;

    while (true)
    {
        if (string[number_of_symbol] == symbol or string[number_of_symbol] == '\0')
        {
            return string + number_of_symbol;
        }

        number_of_symbol += 1;

    }
}

int my_strcmp(const char* string1, const char* string2)
{
    assert(string1);
    assert(string2);

    size_t current_symbol = 0;

    while (true)
    {
        if (string1[current_symbol] != string2[current_symbol]) 
        {
            if (string1[current_symbol] > string2[current_symbol])
            {
                return 1;
            }
            return -1;
        }

        current_symbol += 1;
    }
    return 0;
}

int my_strncmp(const char* string1, const char* string2, size_t num)
{
    assert(string1);
    assert(string2);

    size_t current_symbol = 0;

    while (current_symbol != num)
    {
        if (string1[current_symbol] != string2[current_symbol]) 
        {
            if (string1[current_symbol] > string2[current_symbol])
            {
                return 1;
            }
            return -1;
        }

        current_symbol += 1;
    }
    return 0;
}

char* my_strcat(char* destptr, const char* srcptr) // нах сломается если добавление строки больше той куда добавляем, так надо
{
    assert(destptr);
    assert(srcptr);

    size_t length_of_destptr = my_strlen((const char*) destptr);
    size_t length_of_srcptr = my_strlen((const char*) srcptr);
    size_t number_of_symbol = 0;

    while (number_of_symbol <= length_of_srcptr)
    {
        if (srcptr[number_of_symbol] == '\0')
        {
            destptr[number_of_symbol + length_of_destptr] = '\0';
            break;
        }
        destptr[number_of_symbol + length_of_destptr] = srcptr[number_of_symbol];
        number_of_symbol += 1;
    }
    return destptr;
}

char* my_strncat(char* destptr, const char* srcptr, size_t num)
{
    assert(destptr);
    assert(srcptr);

    size_t length_of_destptr = my_strlen((const char*) destptr);
    size_t number_of_symbol = 0;

    assert(sizeof(*destptr) >= (length_of_destptr + num));

    while (number_of_symbol <= num)
    {
        if (srcptr[number_of_symbol] == '\0')
        {
            destptr[number_of_symbol + length_of_destptr] = '\0';
            break;
        }
        destptr[number_of_symbol + length_of_destptr] = srcptr[number_of_symbol];
        number_of_symbol += 1;
    }
    return destptr;
}



int main()
{
    const char* string = "Hello World";
    const char* string2 = "Hello Mir";
    char string3[100] = "Hello World";
    char symbol = 'o';
    size_t num = 5;

    printf("result of strlen: %lld \n", my_strlen(string));
    printf("result of strchr: %p \n", my_strchr(string, symbol));
    printf("result of strcmp: %d \n", my_strcmp(string, string2));
    printf("result of strncmp: %d \n", my_strncmp(string, string2, num));
    printf("result of strcpy: %p \n", my_strcat(string3, string2));
    printf("result of strncpy: %p \n", my_strncat(string3, string2, num));
}
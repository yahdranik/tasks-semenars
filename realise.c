#include <stdio.h>
#include <cassert>
const int MY_MAX_LEN = 1000;

size_t my_strlen( const char* string )
{
    assert(string);

    size_t count_of_symbols = 0;
    while (string[count_of_symbols] != '\0')
    {
        count_of_symbols += 1;
    }
    return count_of_symbols;
}

const char* my_strchr(const char* string, int symbol )
{
    if (string == NULL)
    {
        return NULL;
    }

    int number_of_symbol = 0;

    while (string[number_of_symbol] != symbol && string[number_of_symbol] != '\0')
    {
        number_of_symbol += 1;
    }

    return string + number_of_symbol;
}

int my_strcmp( const char* string1, const char* string2 ) 
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

int my_strncmp( const char* string1, const char* string2, size_t num )
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

char* my_strcat( char* destptr, const char* srcptr )
{
    assert(destptr);
    assert(srcptr);

    size_t length_of_destptr = my_strlen((const char*) destptr);
    size_t number_of_symbol = 0;

    while (srcptr[number_of_symbol] != '\0')
    {
        destptr[number_of_symbol + length_of_destptr] = srcptr[number_of_symbol];
        number_of_symbol += 1;
    }
    destptr[number_of_symbol + length_of_destptr] = '\0';

    return destptr;
}

char* my_strncat( char* destptr, const char* srcptr, size_t num )
{
    assert(destptr);
    assert(srcptr);

    size_t length_of_destptr = my_strlen((const char*) destptr);
    size_t number_of_symbol = 0;

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

char* my_strcpy( char* destptr, const char* srcptr )
{
    assert(destptr);
    assert(srcptr);

    size_t number_of_symbol = 0;
    while (srcptr[number_of_symbol] != '\0')
    {
        destptr[number_of_symbol] = srcptr[number_of_symbol];
        number_of_symbol += 1;
    }
    return destptr;
}

char* my_strncpy( char* destptr, const char* srcptr, size_t num)
{
    assert(destptr);
    assert(srcptr);
    assert(num);

    size_t number_of_symbol = 0;
    while (srcptr[number_of_symbol] != '\0' && number_of_symbol != num - 1)
    {
        destptr[number_of_symbol] = srcptr[number_of_symbol];
        number_of_symbol += 1;
    } 
    
    return destptr;
}

char* my_strdup( const char* s )
{
    assert(s);

    char* s_dublicate = (char*) malloc(my_strlen(s));
    return my_strcpy(s_dublicate, s);
}

char* my_strndup( const char* s, size_t num)
{
    assert(s);
    assert(num);

    char* s_dublicate = (char*) malloc(num);
    return my_strncpy(s_dublicate, s, num);
}

char* my_strsep( char** stringp, const char* delim ) // не очень пон че она все таки возврашает и что с указателем
{
    if (stringp == NULL|| *stringp == NULL || delim == NULL)
    {
        return NULL;
    }

    size_t length_of_stringp = my_strlen(*stringp);

    for (size_t i = 0; i < length_of_stringp; i++)
    {
        if ((*stringp)[i] == *delim)
        {
            (*stringp)[i] = '\0';
        }
    }
    return *stringp;
}

int my_puts( const char* string )
{
    if (string == NULL)
    {
        return EOF;
    }
    size_t length_of_string = my_strlen(string);
    for (size_t i = 0; i < length_of_string; i++)
    {
        putchar(string[i]);
    }
    return 1;
}



int main()
{
    const char* string = "Hello World";
    const char* string2 = "Hello Mir";
    const char* delim = "o";
    char string3[ 100 ] = "Hello World";

    char string4_buffer[] = "Hello World";
    char* string4 = string4_buffer;

    char symbol = 'o';
    size_t num = 5;

    printf("result of strlen: %lld \n", my_strlen(string));
    printf("result of strchr: %p \n", my_strchr(string, symbol));
    printf("result of strcmp: %d \n", my_strcmp(string, string2));
    printf("result of strncmp: %d \n", my_strncmp(string, string2, num));
    printf("result of strcat: %p, \n", my_strcat(string3, string2));
    printf("result of strncat: %p \n", my_strncat(string3, string2, num));
    printf("result of strcpy: %p \n", my_strcpy(string3, string2));
    printf("result of strncpe: %p \n", my_strncpy(string3, string2, num));
    printf("result of strdup: %p \n", my_strdup(string));
    printf("result of strndup: %p \n", my_strndup(string, num));
    printf("result of strsep: %p\n", my_strsep(&string4, delim));
    my_puts(string);
}
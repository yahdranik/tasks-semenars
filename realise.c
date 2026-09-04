#include <stdio.h>
#include <cassert>
#include <unistd.h>

const char* string5 = "Hello";
const char* delim = ",";
const long int offset_adress = 100;
const int MY_MAX_LEN = 1000;
const char* string1 = "Hello World";
const char* string2 = "Hello Mip";

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

char* my_strsep( char** stringp, const char* delim )
{
    if (stringp == NULL|| *stringp == NULL || delim == NULL)
    {
        return NULL;
    }

    char* begin_adress = *stringp;
    char* current_adress = begin_adress;

    while (*current_adress != '\0')
    {
        for (const char* d = delim; *d != '\0'; d++)
        {
            if (*current_adress == *d)
            {
                *current_adress = '\0';
                *stringp = begin_adress + 1;
                return begin_adress;
            }

            current_adress += 1;
        }
    }

    begin_adress = NULL;
    return begin_adress;
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
    putchar('\n');
    return 1;
}

int my_fseek( FILE* filestream, long int offset, int origin )
{
    if (filestream == NULL)
    {
        return NULL;
    }

    int fd = fileno(filestream);
    if (lseek(fd, offset, origin) == -1)
    {
        return -1;
    }
    clearerr(filestream);
    return 0;
}

char* my_fgets( char* string, int num, FILE* filestream ) // костыльно но для трех ночи прошу простить
{
    if (filestream == NULL || string == NULL || num == NULL)
    {
        return NULL;
    }

    size_t number_of_symbol = 0;

    while (number_of_symbol <= (size_t) num)
    {
        int file_symbol = fgetc(filestream);

        if (file_symbol == '\n')
        {
            break;
        }

        else if (file_symbol == EOF)
        {
            return NULL;
        }

        string[number_of_symbol] = (char) file_symbol;
        number_of_symbol += 1;
    }

    return string;
}

int my_fputs( const char* string, FILE* filestream )
{
    if (filestream == NULL || string == NULL)
    {
        return EOF;
    }

    size_t length_of_string = strlen(string);

    for (size_t i = 0; i < length_of_string; i++)
    {
        fputc((int) string[i], filestream);
    }

    return 1;
}

char* my_strstr( const char* string1, const char* string2 ) 
{
    if (string1 == NULL || string2 == NULL)
    {
        return NULL;
    }

    for (const char* s1 = string1; *s1 != '\0'; s1++)
    {
        const char* s1_ptr = s1;
        const char* s2_ptr = string2;

        while (*s1_ptr != '\0' && *s2_ptr != '\0' && *s1_ptr == *s2_ptr) 
        {
            s1_ptr +=1;
            s2_ptr +=1;
        }

        if (*s2_ptr == '\0') 
        {
            return (char*) s1;
        }
    }

    return NULL;
}

char* my_strrev(char *string)
{
    if (string == NULL) 
    {
        return NULL;
    }

    size_t length_of_string = my_strlen(string);
    char help_cell = 0;

    for (size_t i = 0; i < length_of_string / 2; i++)
    {
        help_cell = string[i];
        string[i] = string[length_of_string - i - 1];
        string[length_of_string - i - 1] = help_cell;
    }
    
    return string;
}

int main()
{
    FILE* file_musor = fopen("huymusor.txt", "r");

    char string3[ MY_MAX_LEN ] = "Hello World";
    char string4[ MY_MAX_LEN ] = "bebebbebebe";
 
    char string6_buffer[ MY_MAX_LEN ] = "Hello World, beatiful";
    char* string6 = string6_buffer;
    char string7[ MY_MAX_LEN ] = {};
    char* string8 = string6_buffer;

    char symbol = 'o';
    size_t num = 5;

    printf("result of strlen: %lld\n", my_strlen(string1));
    printf("result of strchr: %p\n", my_strchr(string1, symbol));
    printf("result of strcmp: %d\n", my_strcmp(string1, string2));
    printf("result of strncmp: %d\n", my_strncmp(string1, string2, num));
    printf("result of strcat: %p\n", my_strcat(string3, string2));
    printf("result of strncat: %p\n", my_strncat(string3, string2, num));
    printf("result of strcpy: %p\n", my_strcpy(string4, string2));
    printf("result of strncpy: %p\n", my_strncpy(string4, string2, num));
    printf("result of strdup: %p\n", my_strdup(string1));
    printf("result of strndup: %p\n", my_strndup(string1, num));
    printf("result of strsep: %p\n", my_strsep(&string6, delim));
    my_puts(string1);
    printf("result of fseek: %d\n", my_fseek(file_musor, offset_adress, SEEK_SET));
    printf("result of fgets: %p\n", my_fgets(string7, MY_MAX_LEN, file_musor));
    printf("result of fputs: %d\n", my_fputs(string1, file_musor));
    printf("result of strstr: %p\n", my_strstr(string5, string1));
    
    fclose(file_musor);
    my_strrev(string8);
    printf("result of strrev: %s\n", string8);
    
}
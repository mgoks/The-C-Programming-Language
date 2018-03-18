/* Write a program to convert its input to lowercase using a function lower(c)
which returns c if c is not a letter and the lowercase value of c if it is a letter. */

#include <stdio.h>

char lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c+32;
    return c;
}

int main()
{
    int c;

    while ((c = getchar()) != EOF)
        putchar(lower(c));
}
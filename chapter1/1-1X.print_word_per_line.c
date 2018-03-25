/* Write a program which prints the words in its input, one per line. 
Word: Any sequence of characters that does not contain a blank, tab, or newline. */

#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\t' || c == '\n')
            putchar('\n');
        else
            putchar(c);
    }
}

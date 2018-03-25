/* Write a program to copy its input to its output,
replacing each string of one or more blanks by a single blank. */

#include <stdio.h>

int main()
{
    int c;
    
    c = getchar();
    while (c != EOF){
        if (c != ' ')
            putchar(c);
        else{
            while (c == ' ')
                c = getchar();
            putchar(' ');
            putchar(c);
        }
        c = getchar();
    }
}

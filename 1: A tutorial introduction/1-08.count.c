/* Write a program to count blanks, tabs, newlines. */

#include <stdio.h>

#define BLANK ' '
#define TAB   '\t'
#define NL    '\n'  // newline

int main()
{
    int c, b, t, nl;

    nl = 0;
    b = 0;
    t = 0;
    while ((c = getchar()) != EOF){
        if (c == NL)
            ++nl;
        else if (c == BLANK)
            ++b;
        else if (c == TAB)
            ++t;
    }
    printf("%d blanks, %d tabs, %d newlines\n", b, t, nl);
}

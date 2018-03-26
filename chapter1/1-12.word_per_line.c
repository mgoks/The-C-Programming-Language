/* Write a program that prints its input one word per line */

#include <stdio.h>

#define IN  1 // inside word
#define OUT 0 // outside word

int main()
{
    int c, state;

    state = OUT;
    while ( (c = getchar()) != EOF ){
        if (c != ' ' && c != '\t' && c != '\n'){
            state = IN;
            putchar(c);
        }
        else if (state == IN){ // equivalent to if ( state == IN && (c == ' ' || c == '\t' || c == '\n') )
            putchar('\n');
            state = OUT;
        }
    }
}
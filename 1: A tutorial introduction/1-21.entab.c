/* Replaces strings of blanks by the minimum number of tabs and blanks to
achieve the same spacing. When either a tab or a single blank would suffice
to reach a tab stop, which should be given preference?
Answer: Space for simplicity. */

#include <stdio.h>

#define TABSTOP 8
#define TRUE    1
#define FALSE   0

int main()
{
    int c, i, column, trailingBlanks;
    int nb; // number of blanks

    column = 0;
    trailingBlanks = FALSE;
    nb = 0;
    while ( (c = getchar()) != EOF ){
        ++column;
        if (c == ' '){
            ++nb;
            trailingBlanks = TRUE;
        }else{
            trailingBlanks = FALSE;
            for (i = 0; i < nb; ++i)
                putchar('_');
            putchar(c);
            nb = 0;
        }
        if (column%TABSTOP == 0 && trailingBlanks == TRUE){
            putchar('\t');
            nb = 0;
            trailingBlanks = FALSE;
        }
        if (c == '\n'){
            putchar('\n');
            column = nb = 0;
            trailingBlanks = FALSE;
        }
    }
}
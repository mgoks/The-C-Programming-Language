/* Replaces tabs in the input with the proper number of blanks to space
to the next tab stop. Assumes a fixed set of tab stops */

#include <stdio.h>

#define TABSTOP  8

int main()
{
	int c, i, j;
	int nb; // number of blanks to insert

	i = 0;
	while ( (c = getchar()) != EOF ){
		if (c == '\t'){
			nb = TABSTOP - (i % TABSTOP);
			for (j = 0; j < nb; ++j)
				putchar(' ');
			i = 0;
		}else if (c == '\n'){
			i = 0;
			putchar(c);
		}else{
			putchar(c);
			++i;
		}
	}
}
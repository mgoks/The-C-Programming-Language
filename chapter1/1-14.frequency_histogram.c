/* Prints a histogram of the frequencies of different characters in its input */

#include <stdio.h>

#define NCHAR 128  // number of ASCII characters

int main()
{
    // array of frequencies
    // freq[i] represents the frequency of the ith ASCII character
    int freq[NCHAR];
    int c, i;

    // initialize all frequencies to zero
    for (c = 0; c < NCHAR; ++c)
        freq[c] = 0;

    while ( (c = getchar()) != EOF )
        ++freq[c];
    
    for (c = 0; c < NCHAR; ++c){
        if (freq[c] > 0){
            if (c == '\n')
                printf("LF ");
            else
                printf("%2c ", (char) c);
                
            for (i = 0; i < freq[c]; ++i){
                putchar('=');
            }
            printf("|\n");
        }
    }
}
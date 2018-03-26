/* Write a program to print a histogram of the lengths of words in its input */

#include <stdio.h>

#define MAX 34

int main()
{
    int length[MAX+1];  // length[i] is the number of words that are of length i
    int i, j, wordlen, c;

    for (i = 0; i < MAX+1; ++i)
        length[i] = 0;

    wordlen = 0;
    while ((c = getchar()) != EOF){
        if (c != ' ' && c != '\t' && c != '\n')
            ++wordlen;
        else{
            ++length[wordlen];
            wordlen = 0;
        }
    }
    for (i = 1; i < MAX+1; ++i){
        printf("%2d ", i);
        for (j = 0; j < length[i]; ++j)
            putchar('=');
        if (j > 0)
            printf("D");
        putchar('\n');
    }
}

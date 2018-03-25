/* Write a function reverse(s) which reverses the character string s.
Use it to write a program which reverses its input a line at a time */

#include <stdio.h>
#define MAXLEN 1000

void reverse(char s[], char rev[], int len);
int getLine(char s[], int lim);

int main()
{
    int len;
    char line[MAXLEN];

    // test reverse()
    
}

/* Reverses string s into rev */
void reverse(char s[], char rev[], int len)
{
    int i;

    for (i = 0; i )
}

int getLine(char s[], int lim) /* returns (size of s) - 1 */
{
    int i, c;

    for (i = 0; (i < lim-1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
        s[i] = c;
    if (c  == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}
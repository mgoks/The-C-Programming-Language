/* Write a function reverse(s) that reverses the character string s.
Use it to write a program that reverses its input a line at a time. */

#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);
void swap(char s[], int i, int j);
int getLine(char s[], int lim);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0){
        reverse(line);
        printf("%s", line);
    }
}

void reverse(char s[])
{
    int lo, hi;

    lo = 0;
    // set hi = s.length - 1
    hi = 0;
    while (s[hi] != '\n')
        ++hi;
    --hi; // because we don't want s[hi] == '\n'

    while (lo < hi){
        swap(s, lo, hi);
        ++lo;
        --hi;
    }
}

void swap(char s[], int i, int j)
{
    char temp;

    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
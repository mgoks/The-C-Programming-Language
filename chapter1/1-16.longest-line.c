/* Revise the main routine of the longest-line program 
so it will correctly print the length of arbitrarily long input lines, 
and as much as possible of the text. */

/* Note:
"By testing the length and the last character returned, main can determine whether the line was 
too long, and then cope as it wishes. */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;                /* max length seen so far */
    char line[MAXLINE];
    char longest[MAXLINE];  /* longest line, saved */
    int c;                  /* character*/

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0){
        if (len == MAXLINE-1 && line[MAXLINE-1] != '\n')
            while ( (c = getchar()) != '\n' && c != EOF)
                ++len;
        if (len > max){
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0){   /* there was a line */
        printf("longest line: %s\nlength: %d\n", longest, max);
    }
}

/* getline: read a line into s, 
return length if length <= MAXLINE-1, MAXLINE-1 otherwise */
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
/* TODO:

Revise the main routine of the longest-line program 
so it will correctly print the length of arbitrarily long input lines, 
and as much as possible of the text. */

/* Note:
It is worth mentioning in passing that even a program as small as this one presents some sticky
design problems. For example, what should main do if it encounters a line which is bigger than
its limit? getline works safely, in that it stops collecting when the array is full, even if no
newline has been seen. By testing the length and the last character returned, main can
determine whether the line was too long, and then cope as it wishes. In the interests of brevity,
we have ignored this issue. */

#include <stdio.h>
#define MAXLINE 10 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;                /* max length seen so far */
    char line[MAXLINE];
    char longest[MAXLINE];  /* longest line, saved */
    int c, nc;              /* character, number of characters */

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > max){
            max = len;
            copy(longest, line);
        }
    if (max > 0){   /* there was a line */
        printf("%s\n", longest);
    }
}

/* getline: read a line into s, 
return length if length <= MAXLINE-1, MAXLINE-1 otherwise*/
int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
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

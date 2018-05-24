/* Fix getint to push + and - back on the input if they are not followed by a digit. */

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
#define SIZE    10

int getch(void), getint(int *);
void ungetch(int);

char buf[BUFSIZE];  // buffer for ungetch
int  bufp = 0;      // next free position in buf

int main()
{
    int n, array[SIZE];

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;
    // print array
    for (n = 0; n < SIZE /*&& array[n] != 0*/; n++)
        printf("%d, ", array[n]);
    printf("\n");
}

// get next integer from input into *pn
int getint(int *pn)
{
    int c, sign;

    while (isspace( c = getch() ))  // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c); // it's not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-'){
        c = getch();
        if (!isdigit(c)){
            printf("INPUT ERROR: Sign found not followed by digit\n");
            ungetch(c);
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void) // get a (possibly pushed back) character 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
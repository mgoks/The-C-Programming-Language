/* The floating-point analog of getint.
What type does getfloat return as its function value?
Answer: int */

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
#define SIZE    10

int getch(void), getfloat(float *);
void ungetch(int);

char buf[BUFSIZE];  // buffer for ungetch
int  bufp = 0;      // next free position in buf

int main()
{
    int n; 
    float array[SIZE];

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;
    // print
    for (n = 0; n < SIZE; n++)
        printf("%f, ", array[n]);
    printf("\n");
}

/**
 * gets next floating-point number from input into *pn
 * @return: EOF                 for end of file
 *          0,                  if next input is not a number
 *          a positive value,   if the input contains a valid number
 * 
 * Inputs with leading '.' are valid, e.g. .2, but signs must be followed by 0
 * if -1 < number < 0 or 0 < number < 1.
 * e.g. +.2 is not valid, but +0.2 is.
 */
int getfloat(float *pn)
{
    int c;
    float sign, pos;

    while (isspace( c = getch() ))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1.0f : 1.0f;
    if (c == '+' || c == '-'){
        c = getch();
        if (!isdigit(c)){
            printf("INPUT ERROR: Sign not followed by digit\n");
            ungetch(c);
            ungetch(sign = 1.0f ? '+' : '-');
            return 0;
        }
    }
    *pn = 0.0f;
    for (; isdigit(c); c = getch())
        *pn = 10.0f * *pn + (c - '0');
    if (c == '.')
        for (pos = 0.1f; isdigit(c = getch()); pos /= 10.0f)
            *pn += (float)(c - '0') * pos;
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
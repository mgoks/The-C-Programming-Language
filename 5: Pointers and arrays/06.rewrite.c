/* getline, atoi, itoa, and their variants, reverse, strindex, and getop */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE     1000
#define BUFSIZE     100
#define NUMBER      '0'

void    itoa    (int, char *);      
void    reverse (char *);           
void    ungetch (int);
int     get_line(char *, int);      
int     atoi    (const char *);     
int     strindex(char *, char *);   
int     getop   (char *);
int     getch   (void);
long    atol    (const char *);     
double  atof    (const char *);     
char    buf[BUFSIZE];
int     bufp = 0;

int main()
{
    int len, i;
    char line[MAXLINE], a[MAXLINE];

    // test
    while ((len = get_line(line, MAXLINE)) > 0){
        get_line(a, MAXLINE);
        printf("%i\n", strindex(line, a));
        // i = atoi(line);
        // itoa(i, a);
        // printf("%s\n", a);
        // printf("%f\n", atof(line));
        // printf("%li\n", atol(line));

    }
}

long atol(const char *s)
{
    long int sign, n;

    // skip whitespace
    while (isspace(*s))
        s++;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') // skip sign
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10*n + (*s - '0');
    return sign * n;
}

/**
 * convert string s to double
 */
double atof(const char *s)
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(*s); s++) // skip white space
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (val = 0.0; isdigit(*s); ++s)
        val = 10.0 * val + (*s - '0');
    if (*s == '.')
        s++;
    for (power = 1.0; isdigit(*s); s++){
        val = 10.0 * val + (*s - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

/**
 * convert n to characters in s
 * FIX: converts n in reverse order
 * does not matter if reverse is called or not
 */
void itoa(int n, char *s)
{
    int sign;
    const char *s0 = s; // always points to first char of s

    if ( (sign = n) < 0 )       // record sign
        n = -n;                 // make n positive
    do{                         // generate digits in reverse order
        *s++ = n % 10 + '0';    // get next digit
    } while ( (n /= 10) > 0 );  // delete it
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(s0);
}

/**
 *  converts s to integer
 */
int atoi(const char *s)
{
    int sign, n;

    // skip whitespace
    while (isspace(*s))
        s++;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') // skip sign
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10*n + (*s - '0');
    return sign * n;
}

/**
 * read a line into s
 * return the length of s
 */
int get_line(char *s, int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        *s++ = c;
    if (c == '\n'){
        *s++ = c;
        ++i;
    }
    *s = '\0';
    return i;
}

void reverse(char *s)
{
    int c;
    char *t;

    for (t = s + strlen(s) - 1; s < t; s++, t--){
        c = *s;
        *s = *t;
        *t = c;
    }
}

/**
 * returns index of t in s if t is substring of s that starts at
 * some index of s and ends where s ends;
 *         -1 otherwise.
 * E.g. if s = "abc" and t = "b", returns -1;
 *      if               t = "bc", returns 1.
 */
int strindex(char *s, char *t)
{
    char *i, *j, *k;

    for (i = s; *i != '\0'; i++){
        for (j = i, k = t; *k != '\0' && *j == *k; j++, k++)
            ;
        if (k > t && *k == '\0')
            return i-s;
    }
    return -1;
}

/**
 * get next operator or numeric operand
 */
int getop(char *s)
{
    int c;

    // Skip blanks and tabs
    while ( (*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s+1) = '\0';
    // if the next char is not digit or decimal point, return it
    if (!isdigit(c) && c != '.')
        return c;
    // otherwise collect a string of digits
    if (isdigit(c)) // collect integer part
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.')   // collect fraction part
        while (isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    // and return number (the signal that a number has been collected)
    return NUMBER;
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
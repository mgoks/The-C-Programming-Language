#include <stdio.h>

#define SIZE 1000

int strlen(char *), strend(char *, char *);

int main()
{
    int ret;
    char s[SIZE] = "suh dudesss"; 
    char t[SIZE] = "sss";
    ret = strend(s, t);
    printf("%d\n", ret);
}

/**
 * returns 1, if the string t occurs at the end of the string s
 *         0, otherwise
 */
int strend(char *s, char *t)
{
    char *t0 = t; // ptr to 0th char of t

    // get to the end of s and t
    s = s + strlen(s);
    t = t + strlen(t);

    while (t >= t0){
        if (*s-- == *t--)
            ;
        else // t doesn't occur at end of s
            return 0;
    }
    return 1;
}

// returns length of string s
int strlen(char *s)
{
    char *p = s;

    while (*p)
        p++;
    return p-s;
}
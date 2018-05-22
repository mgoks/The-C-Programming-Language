/* Pointer version of the function strcat that is showed in Chapter 2:
strcat(s,t) copies the string t to the end of s. */

#include <stdio.h>

#define STR_BUFFER 10000

void strcat(char *, char *);

int main()
{
    // test
    char s1[STR_BUFFER] = "What A ";
    char s2[STR_BUFFER] = "Wonderful World!";
    char s3[STR_BUFFER] = "";

    strcat(s1, s2);
    strcat(s3, s2);
    printf("%s\n", s1);
    printf("%s\n", s3);
}

/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char *s, char *t)
{
    // find end of s
    while (*s) // *s == 0 if *s == s[i] == \0, *s > 0 otherwise
        ++s;
    // copy t
    while (*s++ = *t++)
        ;
}
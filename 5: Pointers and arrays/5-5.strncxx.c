#include <stdio.h>

#define NUL     '\0'
#define SIZE    100

/* The const declaration can be used with array arguments, to 
indicate that the function does not change that array. */
char *strncpy(char*, const char*, size_t);
char *strncat(char*, const char*, size_t);
int strncmp(const char*, const char*, size_t);
size_t strlen(const char *);

int main()
{
    char s1[SIZE] = "123";
    char s2[SIZE] = "123";
    char t[SIZE] = "lkasmdlfmaslfmask";
    char s3[SIZE] = "hopdirililaylay";
    char t3[SIZE] = "hopdiril";
    size_t n = 0;

    strncpy(s1, t, n);
    printf("copy: %s\n", s1);

    strncat(s2, t, n);
    printf("cat.: %s\n", s2);

    printf("comp: %d\n", strncmp(t3, s3, n));
}

/**
 * copy at most n characters of string t to s;
 * pad s with NUL if t has less than n characters
 * return s
 */
char *strncpy(char *s, const char *t, size_t n)
{
    size_t i;

    for(i = 0; i < n && (*s++ = *t++); ++i)
        ;
    if (strlen(t) < n)
        while(*s++ = NUL)
            ;
    return s;
}

/**
 * concatenate at most n characters of string t to string s,
 * terminate s with NUL
 * return s
 */
char *strncat(char *s , const char *t, size_t n)
{
    // get to the end of s
    while(*s)
        ++s;
    return strncpy(s, t, n);
}

/**
 * compare at most n characters of string s to string t
 * return   <0 if cs<ct
 *           0 if cs==ct
 *          >0 if cs>ct
 */
int strncmp(const char *s, const char *t, size_t n)
{
    size_t i;

    for(i = 0; i < n; ++i, s++, t++)
        if (*s != *t)
            return *s - *t;
    return 0;
}

size_t strlen(const char *s)
{
    const char *p = s;

    while (*p)
        p++;
    return p-s;
}
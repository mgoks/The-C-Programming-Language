/**
 * Rewrite the routines day_of_year and month_day with pointers instead of indexing
 */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    // non-leap
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    // leap
};

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

int main()
{
    printf("%d\n", day_of_year(2018, 05, 24));
    printf("%d\n", day_of_year(2018, 12, 31));
    
    int m, d;
    
    month_day(2018, 144, &m, &d);
    printf("%d/%d\n", m, d);
    month_day(2018, 365, &m, &d);
    printf("%d/%d\n", m, d);
}

int day_of_year(int year, int month, int day)
{
    int leap;
    char *p;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    p = *daytab+leap; // == &daytab[leap][0];
    while (--month)
        day += *++p;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap, i;
    char *p;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    p = *daytab + leap;
    for (i = 1; yearday > *++p; i++)
        yearday -= *p;
    *pmonth = i;
    *pday = yearday;
}
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
    // *(*(daytab+row)+col) == daytab[row][col]

    printf("%d\n", day_of_year(2018, 05, 22));
    printf("%d\n", day_of_year(2018, 12, 31));
    
    int m, d;
    
    month_day(2018, 142, &m, &d);
    printf("%d/%d\n", m, d);
    month_day(2018, 365, &m, &d);
    printf("%d/%d\n", m, d);
}

int day_of_year(int year, int month, int day)
{
    int leap, i;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    for (i = 1; i < month; i++)
        day += *(*(daytab+leap)+i);
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    for (i = 1; yearday > *(*(daytab+leap)+i); i++)
        yearday -= *(*(daytab+leap)+i);
    *pmonth = i;
    *pday = yearday;
}
/**
 * There is no error checking in day_of_year or month_day. Remedy this defect.
 */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

int main()
{
    printf("%d\n", day_of_year(2016, 2, 29));
}

// set day of year from month & day
int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (year < 1){
        printf("error: year %i is not a positive number\n", year);
        return -1;
    }
    if (month < 1 || month > 12){
        printf("error: month %i is not between 1 and 12\n", month);
        return -2;
    }
    if (day < 1 || day > 31){
        printf("error: day %i is not a between 1 and 31\n", day);
        return -3;
    }
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (month == 2){
        if (!leap && day > 28){
            printf("error: Feb %d has at most 28 days\n", year);
            return -4;
        }
        if (leap && day > 29){
            printf("error: Feb %d has at most 29 days\n", year);
            return -5;
        }
    }
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

// set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    if (year < 1){
        printf("error: year %i is not a positive number\n", year);
        return -1;
    }
    if (yearday < 1){
        printf("error: day of the year (%i) must be > 0\n", yearday);
        return -2;
    }
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (!leap && yearday > 365){
        printf("error: day of the year (%i) must be <= 365\n", yearday);
        return -3;
    }
    if (leap && yearday > 366){
        printf("error: day of the year (%i) must be <= 366 (leap year)\n", yearday);
        return -4;
    }
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
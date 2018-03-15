/* Modify the temp. conversion program to print the table in reverse order */

#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 300, 180, ..., 0 */

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() 
{
    int fahr;

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
        printf("%4d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
/* Modify the the temperature conversion program to print a header above the table. */

#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
int main() 
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0;      /* lower limit of temperature scale */ 
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    printf("Fahrenheit Celcius\n");
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9; 
        printf("%10.0f %7.1f\n", fahr, celsius); 
        fahr = fahr + step;
    }
}
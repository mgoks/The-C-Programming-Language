/*
Write a program to print the corresponding Celsius to Fahrenheit table
*/

#include <stdio.h>

int main()
{
    int lower, upper, step;
    float fahr, celsius;

    lower = -17;
    upper = 150;
    step = 20;

    celsius = lower;
    printf("Celcius Fahrenheit\n");
    while (celsius <= upper){
        fahr = (9.0/5.0)*celsius + 32;
        printf("%7.0f %10.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
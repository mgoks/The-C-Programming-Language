/**
 * Write the program expr, which evaluates a reverse Polish expression from the command
 * line, where each operator or operand is a separate argument. For example.
 * 
 *      expr 2 3 4 + *
 * 
 * evaluates 2 x (3+4).
 */

#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>

#define NUMBER  '0' // signal that a number was found

void push(double);
double pop(void);
int getop(char *);

// reverse Polish calculator
int main(int argc, char *argv[])
{
    int type;
    double op2;

    while (--argc > 0){
        /* if 1st char of argument (*argv) is digit or decimal point, type = NUMBER
           else type = 1st char of the argument */
        type = isdigit((*++argv)[0]) || (*argv)[0] == '.' ? NUMBER : (*argv)[0];
        switch(type){
            case NUMBER:
                push(atof(*argv));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else   
                    printf("error: zero divisor\n");
                break;
            default:
                printf("error: unknown command %s\n", *argv);
                break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}

#define MAXVAL  100     // max depth of val stack

double val[MAXVAL];     // value stack
int sp = 0;             // next free stack position

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else   
        printf("error: stack full, cant push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
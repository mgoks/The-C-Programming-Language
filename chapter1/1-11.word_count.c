/* Revise the word count program to use a better definition of "word" for example, a sequence of 
   letters, digits, and apostrophes that begin with a letter.

   Here the string "123abc" is not considered a word but the substring "abc" is,
   since it fits the definition. 
   
   To run this program run the executable, type input, hit enter
   an press control + D. */

#include <stdio.h>

int main()
{
    int c, nw;

    nw = 0;
    while ((c = getchar()) != EOF){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){ // if the sequence begins with a letter
            while ( (                       c != EOF                   ) && 
                    ( ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) || 
                      (              c >= '0' && c <= '9'              ) ||
                                            c == '\''                      ))
                c = getchar();
            ++nw;
        }
    }
    printf("%d words\n", nw);
}
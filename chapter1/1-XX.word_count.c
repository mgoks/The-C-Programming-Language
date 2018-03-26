/* From the first edition:

   Revise the word count program to use a better definition of "word" for example, a sequence of 
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
        // if the sequence begins with a letter
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        // while (c is not EOF) and (c is a letter or a digit or an apostrophe)
           while ((c != EOF) && (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) || (c >= '0' && c <= '9') || c == '\''))
                c = getchar();
            ++nw; // increment word count when EOF is reached or if c is none of the above
        }
    }
    printf("%d words\n", nw);
}

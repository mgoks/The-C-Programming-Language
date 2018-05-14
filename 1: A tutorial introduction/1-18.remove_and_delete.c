/* Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines. */

#include <stdio.h>
#define MAXLEN 1000

int getLine(char s[], int lim);
int isBlank(char s[], int len);

int main()
{
    int len, i;
    char line[MAXLEN];

    while ((len = getLine(line, MAXLEN)) > 0){
        if (isBlank(line, len))
            ;
        else if (len > 1){
            if (line[len-2] == ' ' || line[len-2] == '\t'){
                i = len-2;
                while (i >= 0 && (line[i] == ' ' || line[i] == '\t')){
                    line[i] = '\n';
                    line[i+1] = '\0';
                    // for testing purposes
                    // line[i] = '.';
                    // line[i+1] = '\n';
                    // line[i+2] = '\0';
                    --i;
                }
            }
            printf("%s", line);
        }
    }
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
}

int isBlank(char s[], int len)
{
    int i, isBlank;

    isBlank = 1;
    for (i = 0; i < len && isBlank == 1; ++i){
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\0')
            isBlank = 0;
    }
    return isBlank;
}

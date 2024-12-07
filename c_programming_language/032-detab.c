/*
    Exercise 1.20
    Write a program <detab> that replaces tabs in the input with the proper number of blanks to space the next tab stop. Assume a fixed set of tab stops, every n columns.
*/

#include <stdio.h>
#define MAXLINE 100

int getlines(char line[], int maxline);

int main()
{
    char line[MAXLINE];
    int len;
    while ((len = getlines(line, MAXLINE)) > 0) {
        printf("%s", line);
    }
    return 0;
}

int getlines(char line[], int maxline)
{
    int i, c;
    int tabstop = 8;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c == '\t') {
            //printf("tabstop detected!\n");
            for (int j = 1; j <= tabstop; ++j) {
                //printf("c: %c, i: %i, line: %s\n", c, i, line);
                line[i] = ' ';
                ++i;
            }
            --i;
        } else {
            //printf("not a tabstop -carry on...");
            line[i] = c;
            //printf("c: %c, i: %i, line: %s\n", c, i, line);
        }
    }
    if (i > 0) {
        line[i] = '\n';
        ++i;
        line[i] = '\0';
    }
    return i;
}
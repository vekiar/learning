/*
    Exercise 1.21
    Write a program <entab> that replaces strings of blanks by the minimum of tabs and blanks to avhieve the same spacing.
    Use the same tab stops as in <detab>.
*/

#include <stdio.h>
#define MAXLINE 100

int getlines(char lines[], int maxlines);

int main()
{
    int len;
    char line[MAXLINE];
    while (len = getlines(line, MAXLINE) > 0) {
        printf("%s", line);
    }
    return 0;
}

int getlines(char line[], int maxlines)
{
    int i, c;
    for (i = 0; i < maxlines && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (i > 0) {
        line[i] = '\n';
        ++i;
        line[i] = '\0';
    }
    return i;
}
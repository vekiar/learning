/*
    Exercise 1.18
    Write a program to remove trailing blanks and tabs from each lineof input, and to delete entirely blank lines.
*/

#include <stdio.h>
#define MAXLINE 150

int getlines(char line[], int maxline);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getlines(line, MAXLINE)) > 0)
        printf("%s", line);
    return 0;
}

int getlines(char line[], int maxline)
{
    int i, c;
    char previous;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if ((c == ' ' || c == '\t') && (line[i-1] == ' ' || line[i-1] == '\t')) {
            --i;
        } else {
            line[i] = c;
        }
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

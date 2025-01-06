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
        printf("%s\n", line);
    }
    return 0;
}

int getlines(char line[], int maxline)
{
    int i, c;
    int tabstop = 8;
    int tabs = 0;
    int len_in = 0;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        printf("%d: ", i);
        if (c == '\t') {
            ++tabs;
            line[i] = ' ';
            printf("tab detected! Adding %d spaces and offsetting array index to %d", tabstop, i + tabstop);
            for (int j = 0; j < tabstop; ++j) {
                line[i] = ' ';
                ++i;
            }
            --i; // WHY do I need to do this? FIXME
        } else {
            line[i] = c;
            for (int j = 0; j <= i; ++j) {
                printf("%c", line[j]);
            }
        }
        printf("\n");
        ++len_in;
    }
    // Close out the array
    if (i > 0) {
        line[i] = '\0';
    }
    printf("Tabs detected: %d\nLength in: %d\nLen out: %d\n", tabs, len_in, i);
    return i;
}
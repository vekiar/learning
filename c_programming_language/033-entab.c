/*
    Exercise 1.21
    Write a program <entab> that replaces strings of blanks by the minimum of tabs and blanks to achieve the same spacing.
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
        printf("%s\n", line);
    }
    return 0;
}

int getlines(char line[], int maxlines)
{
    int i, c;
    int spaces = 0;
    int tabstop = 8;
    for (i = 0; i < maxlines && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c != ' ') {
            line[i] = c;
            spaces = 0;
            printf("%d:\t%c -> ", i, c);
            for (int j = 0; j <= i; ++j) {
                printf("%c", line[j]);
            }
            printf("\n");
        } else if (c = ' ') {
            ++spaces;
            printf("%d:\tSpace detected -> %d sequential spaces (%d left for tabstop)\n", i, spaces, tabstop - spaces);
            if (spaces >= tabstop) {
                int offset = i - (spaces - 1);
                printf("%d:\tInserting tabstop in position: %d\n", i, offset);
                i = offset;
                while (spaces >= tabstop) {
                    line[i] = '\t';
                    ++i;
                    spaces = spaces - tabstop;
                }
                --i; // WHY do we need to do this ugly arse thing here?
            } else {
                line[i] = c;
            }
        }
    }
    if (i > 0) {
        line[i] = '\0';
    }
    printf("Array is %d characters long (including null terminator)\n", i);
    return i;
}
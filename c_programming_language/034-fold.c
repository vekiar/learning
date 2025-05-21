/*
 * Exercise 1.22
 * Write a program to fold long input lines into two or more shorter lines after the last non-blank character that occurs before the nth column of input
*/

#include <stdio.h>
#define MAXLINE 1000
#define LIMIT 20

int getlines(char lines[], int maxlines);

int main()
{
    char line[MAXLINE];
    int len;

    while ((len = getlines(line, MAXLINE)) > 0) {
        if (len < LIMIT) {
            printf("%s", line);
        } else {
            int chunks = len/LIMIT;
            int modulo = len % LIMIT;
            //printf("L: %d, C: %d, M: %d\n", len, chunks, modulo);
            for (int i = 0; i < chunks; ++i) {
                for (int j = i * LIMIT; j < ((i * LIMIT) + LIMIT); ++j)
                    printf("%c", line[j]);
                printf("\n");
            }
            int offset = chunks * LIMIT;
            for (int i = offset; i < (offset + modulo); ++i)
                printf("%c", line[i]);
        }
    }

    return 0;
}

int getlines(char line[], int maxline)
{
    int c, i;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    line[i] = '\0';
    return i;
}

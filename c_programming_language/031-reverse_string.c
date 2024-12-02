/*
    Exercise 1.19
    Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.
*/

#include <stdio.h>
#define MAXLINE 1000

int getlines(char line[], int maxline);
void reverse_line(char line[], int line_len);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getlines(line, MAXLINE)) > 0) {
        char reverse[len];
        int i;
        for (i = 0; i < len - 1; ++i) {
            reverse[i] = line[len-2-i];
        }
        reverse[i] = '\n';
        ++i;
        reverse[i] = '\0';
        printf("%s", reverse);
    }
    return 0;
}

int getlines(char line[], int maxline)
{
    int i, c;
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

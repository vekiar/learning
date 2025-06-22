/*
 * Exercise 3.6
 *
 * Write a version of <itoa> that accepts three arguments instead of two. The
 * third argument is a minimum field width. The converted number must be
 * padded with blanks on the left if necessary to make it wide enough.
 *
 */

#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main()
{
    int n1 = 10;
    char s1[10];
    itoa(n1, s1, 0);
    printf("%s\n", s1);

    int n2 = 10;
    char s2[10];
    itoa(n2, s2, 5);
    printf("%s\n", s2);

    return 0;
}

void itoa(int n, char s[], int w)
{
    int i, sign;

    if ((sign =n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    while (i < w)
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
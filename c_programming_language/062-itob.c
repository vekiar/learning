/*
 * Exercise 3.5
 * Write a function <itob(n, s, b)> that converts the integer n into a base b
 * character representation in string s.
 *
 */

#include <stdio.h>

void itob(int n, char s[], int b);
void print_string(char s[]);
void reverse(char s[]);
int string_length(char s[]);

int main()
{
    int n;

    char s1[10];
    n = 3462;
    itob(n, s1, 16);
    print_string(s1);

    char s2[10];
    n = 10;
    itob(n, s2, 2);
    print_string(s2);

    char  s3[10];
    n = 100;
    itob(n, s3, 8);
    print_string(s3);

    return 0;
}

void itob(int n, char s[], int b) {
    int i = 0;
    int digit;

    if (n == 0) {
        s[i++] = '0';
    } else {
        while (n > 0) {
            digit = n % b;
            if (digit < 10) {
                s[i++] = digit + '0';
            } else {
                s[i++] = digit - 10 + 'A';
            }
            n /= b;
        }
    }
    s[i] = '\0';
    reverse(s);
}

void print_string(char s[])
{
    int i = 0;
    while (s[i] != '\0') {
        printf("%c", s[i]);
        i++;
    }
    printf("\n");
}

void reverse(char s[])
{
    int i, j = string_length(s), c;
    for (i = 0; i < (j / 2); i++) {
        c = s[i];
        s[i] = s[j - 1 - i];
        s[j - 1 -i] = c;
    }
}

int string_length(char s[])
{
    int i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    return i;
}
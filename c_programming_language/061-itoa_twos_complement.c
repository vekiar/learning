/*
 * Exercise 3.4
 * In a two's complement number representation, our version of <itoa> does not
 * handle the largest negative numner (-2 ^ (wordsize - 1)). Modify it to
 * print the value correctly.
 *
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLEN 30
void reverse(char s[]);
void itoa(signed long long int n, char s[]);

int main()
{
    //int n = -124;
    signed long long int n1 = LLONG_MAX;
    char s1[MAXLEN];
    itoa(n1, s1);
    printf("Number %lld is String '%s'\n", n1, s1);

    signed long long int n2 = LLONG_MIN;
    char s2[MAXLEN];
    itoa(n2, s2);
    printf("Number %lld is String '%s'\n", n2, s2);

    return 0;
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

void itoa(signed long long int n, char s[])
{
    printf("Breaking down: %lld\n", n);
    int i, r = 0;
    signed long long int sign;

    if ((sign = n) < 0) {
        printf("Make n positive: ");
        if (n == LLONG_MIN) {
            n = LLONG_MAX;
            r = 1;
        }
        else
            n = -n;
        printf("%lld\n", n);
    }

    i = 0;
    do {
        printf("%d %lld\n", i, n);
        if (r == 1) {
            printf("LLONG_MIN detected! Changing %c to %c\n", (char) (n % 10 + '0'), (char) (n % 10 + '1'));
            s[i++] =  n % 10 + '1';
            r = 0;
        }
        else
            s[i++] =  n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
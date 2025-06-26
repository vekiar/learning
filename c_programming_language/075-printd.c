/*
 * Exercise 4.12
 * Adapt the ideas of <printd> to write a recursive vesion of <itoa>. Convert
 * an integer into a string by calling a recursive routine.
 *
 */

#include <stdio.h>

void printd(int n);
void itoa(int n, char s[]);

int main()
{
    int a = 948;
    char b[10];
    printf("n = %d\n", a);
    printf("c = ");
    itoa(a, b);
    printf("\n");
    return 0;
}

void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

void itoa(int n, char s[])
{
    if (n < 0) {
        putchar('-');
        n = -n;
    } else if (n == 0) {
        putchar('0');
        return;
    } else if (n < 10) {
        putchar(n + '0');
        return;
    } else {
        itoa(n / 10, s);
        putchar((n % 10) + '0');
    }
}
#include <stdio.h>

int main()
{
    int n = 124;
    char s[10];

    for (int i = 0; i < 10; i++)
        printf("%c", s[i]);
    printf("\n");

    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    //reverse(s);
}
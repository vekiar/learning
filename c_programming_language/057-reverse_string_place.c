#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main()
{
    char s[] = {'t', 'u', 'v', 'i', 'e', 'j', 'a'};

    printf("Original: ");
    for (int i = 0; i < strlen(s); i++)
        printf("%c", s[i]);

    reverse(s);

    printf("\nReversed: ");
    for (int i = 0; i < strlen(s); i++)
        printf("%c", s[i]);
    printf("\n");
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
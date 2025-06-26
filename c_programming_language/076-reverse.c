#include <stdio.h>
#include <string.h>

void reverse(char s[], int lower, int upper);

int main()
{
    char s1[] = "tu vieja en tanga";
    printf("%s\n", s1);
    reverse(s1, 0, strlen(s1) - 1);
    printf("%s\n", s1);

    char s2[] = "hay algo que hace explotar esto";
    printf("%s\n", s2);
    reverse(s2, 0, strlen(s2) - 1);
    printf("%s\n", s2);

    return 0;
}

void reverse(char s[], int lower, int upper)
{
    if (lower == upper) {
        char n = '\0';
        printf("%c", n);
    }
    else {
        //printf("Swapping: %c and %c.\n", s[lower], s[upper]);
        char c = s[lower];
        s[lower] = s[upper];
        s[upper] = c;
        ++lower;
        --upper;
        reverse(s, lower, upper);
    }
}
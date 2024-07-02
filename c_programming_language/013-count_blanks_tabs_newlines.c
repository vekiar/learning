#include <stdio.h>

int main()
{
    int b = 0;
    int t = 0;
    int n = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            b += 1;
        if (c == '\t')
            t += 1;
        if (c == '\n')
            n += 1;
    }
    printf("Blanks: %d, Tabs: %d, Newlines: %d\n", b, t, n);
}
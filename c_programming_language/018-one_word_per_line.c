#include <stdio.h>

/* TODO
    - "One word per line" -> ignore spacing that will create blank lines
*/

int main()
{
    int c;
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t')
            putchar('\n');
        else
            putchar(c);
    return 0;
}
#include <stdio.h>

int main()
{
    int c, p;

    while ((c = getchar()) != EOF) {
        if (c != ' ' ) {
            putchar(c);
            p = c;
        }
        else if (c == ' ') {
            if (p == ' ') {
                p = c;
            } else {
                putchar (c);
                p = c;
            }
        }
    }
    return 0;
}
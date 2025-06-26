#include <stdio.h>

#define swap(t, x, y) {         \
            if (t == 'int') {   \
                x = x + y;      \
                y = x - y;      \
                x = x - y;      \
            }                   \
        }

int main()
{
    int a = 10;
    int b = 20;
    printf("a = %d, b = %d\n", a, b);
    swap('int', a, b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
#include <stdio.h>

#if !defined(swap)
#define swap(t, x, y) do { t _tmp = (x); (x) = (y); (y) = _tmp;} while (0)
#endif

int main()
{
    int a = 10;
    int b = 20;
    printf("a = %d, b = %d\n", a, b);
    swap(int, a, b);
    printf("a = %d, b = %d\n", a, b);

    char c = 'a';
    char d = 'b';
    printf("c = %c, d = %c\n", c, d);
    swap(char, c, d);
    printf("c = %c, d = %c\n", c, d);

    return 0;
}
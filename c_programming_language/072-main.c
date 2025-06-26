#include <stdio.h>
#include "072-static_test.h"

int main()
{
    register int x = 2;
    printf("%d\n", multiply(x, 10));
    printf("%d\n", NUMBER);
    return 0;
}
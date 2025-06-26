#include "072-static_test.h"

static int times(int x, int y);
static int x = 10;
int multiply(int x, int y);

int times(int x, int y)
{
    return x * y;
}

int multiply(int x, int y)
{
    return times(x, y);
}

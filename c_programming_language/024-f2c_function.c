#include <stdio.h>

float f2c(int f);

int main()
{
    for (int f = 0; f <= 300; f = f + 20)
        printf("%3d\t%6.1f\n", f, f2c(f));
    return 0;
}

float f2c(int f)
{
    int c;
    c = (5.0/9.0)*(f - 32);
    return c;
}
#include <stdio.h>

int main()
{
    int c;
    printf("C\tF\n");
    for (c = 0; c <= 200; c = c + 10)
        printf("%d\t%6.1f\n", c, (c * (9.0/5.0) + 32));
    return 0;
}

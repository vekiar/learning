#include <stdio.h>

int main() {
    int f;
    printf("F\tC\n");
    for (f = 0; f <= 300; f = f + 20)
        printf("%3d\t%6.1f\n", f, (5.0/9.0)*(f - 32));
    return 0;
}

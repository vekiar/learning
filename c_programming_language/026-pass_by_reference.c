#include <stdio.h>

int n_times(int* x, int times);

int main()
{
    int x = 10;
    int y = 20;

    printf("Outside the function x = %d\n", x);
    printf("Inside the function x = %d\n", n_times(&x, y));
    printf("Outside the function x = %d\n", x);

}

int n_times(int* x, int times)
{
    *x = *x * times;
    return *x;
}
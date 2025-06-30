#include <stdio.h>

void swap(int *x, int *y);

int main()
{
    //printf("Hola!\n");
    int x =1, y = 2, z[10];
    int *ip;

    ip = &x;
    y = *ip;
    printf("Value of ip = %p, dereferenced value of ip (*ip) = %d\n", ip, *ip);
    *ip = 0;
    ip = &z[0];
    printf("Value of ip = %p, dereferenced value of ip (*ip) = %d\n", ip, *ip);

    printf("x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);

    return 0;
}

void swap(int *px, int *py)
{
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}

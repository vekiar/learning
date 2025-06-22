#include <stdio.h>

#define MAXLEN 100

int max(int a, int b);
int max_fast(int a, int b);
void print_array(int n, int a[]);

int main()
{
  int a = 4;
  int b = 8;
  printf("Max of (%d, %d) is %d\n", a, b, max(a,b));
  printf("Max of (%d, %d) is %d\n", a, b, max_fast(a,b));

  int z[MAXLEN];
  for (int i = 0; i < MAXLEN; i++)
    z[i] = 1;
  printf("Array printed in 3 columns:\n");
  print_array(3, z);
  printf("Array printed in 5 columns:\n");
  print_array(5, z);
  printf("Array printed in 20 columns:\n");
  print_array(20, z);
  return 0;
}

int max(int a, int b)
{
  if (a > b)
    return a;
  else
    return b;
}

int max_fast(int a, int b)
{
  return (a > b) ? a : b;
}

void print_array(int n, int a[])
{
  int i;
  for (i = 0; i < MAXLEN; i++)
    printf("%6d%c", a[i], (i%n==(n-1) || i==MAXLEN-1) ? '\n' : ' ');
}

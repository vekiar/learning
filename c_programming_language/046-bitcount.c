#include <stdio.h>

unsigned bitcount(unsigned x);

int main()
{
  printf("bitcount of %d = %d\n", 1, bitcount(1)); // = 1
  printf("bitcount of %d = %d\n", 1, bitcount(2)); // = 1
  printf("bitcount of %d = %d\n", 1, bitcount(3)); // = 2
  printf("bitcount of %d = %d\n", 1, bitcount(4)); // = 1
  printf("bitcount of %d = %d\n", 1, bitcount(5)); // = 2
  printf("bitcount of %d = %d\n", 1, bitcount(6)); // = 2
  return 0;
}

unsigned bitcount(unsigned x)
{
  int b;
  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}

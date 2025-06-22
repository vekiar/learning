/*
 * Exercise 2.6
 * Write a function <setbits(x, p, n, y)> that returns x with the n bits that
 * begin at position p set to the rightmost n bits of y.
 *
 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

int main()
{
  printf("setbits of %d = %d\n", 4, setbits(4, 3, 2, 1));
  return 0;
}

unsigned setbits(unsigned x, int p, int n, int y)
{
  unsigned mask = ((1 << n) - 1) << (p + 1 -n);
  x &= ~mask;
  y = (y & ((1 << n) - 1)) << (p + 1 - n);
  return x | y;
}


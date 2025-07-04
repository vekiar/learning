/*
 * Exercise 2.8
 * Write a function <rightrot(x,n)> that returns the value of the integer x
 * rotated to the right by n bit positions.
 *
 */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main()
{
  printf("rightrot(%d) = %d\n", 2, rightrot(2,2));
  return 0;
}

unsigned rightrot(unsigned x, int n)
{
  int word_len = sizeof(x) * 8;
  n %= word_len;
  return (x >> n) | (x << (word_len - n));
}

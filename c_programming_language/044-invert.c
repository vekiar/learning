/*
 * Exercise 2.7
 * Write a function <invert(x,p,n)> that returns x with the n bits that begin
 * at position p inverted.
 *
 */

unsigned invert(unsigned x, int p, int n);

int main()
{
  return 0;
}

unsigned invert(unsigned x, int p, int n)
{
  unsigned mask = ((1 << n) - 1) << (p + 1 - n);
  return x ^ mask;
}

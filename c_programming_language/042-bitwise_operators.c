#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main()
{
  int a = 1;
  int b = 2;
  int c = a&b;
  int d = a|b;
  int e = a^b;
  int f = a<<b;
  int g = a>>b;
  int h = ~a;

  signed int a2 = 1;

  printf("Bitwise AND: %d & %d = %d\n", a, b, c);
  printf("Bitwise inclusive OR: %d | %d = %d\n", a, b, d);
  printf("Bitwise exclusive OR: %d ^ %d = %d\n", a, b, e);
  printf("Left Shift: %d << %d = %d\n", a, b, f);
  printf("Right Shift: %d >> %d = %d\n", a, b, g);
  printf("One's Complement: ~%d = %d\n", a, h);
  printf("\n");
  printf("Masking off some set of bits: %d & 0177 = %d (Sets to zero all but the low-order 7 bits of a)\n", a, a & 0177);
  printf("Turn bits on with bitwise inclusive OR: %d | 0177 = %d (Set a one the bits that are on in the 2nd operand)\n", a, a | 0177);
  printf("Bitwise exclusive OR sets a 1 in each bit where operands have different bits, zero where they are the same: %d ^ 0177 = %d\n", a, a ^ 0177);
  printf("Do not confuse %d && %d = %d, with %d & %d = %d\n", a, b, a && b, a, b, a & b);
  printf("%d << %d = %d because bits _shift_ left, so 0001 -> 0100\n", a, b, a << b);
  printf("%d >> %d = %d because bits _shift_ right, so 0001 -> 0000 \n", a, b, a >> b);
  printf("Beware of _signed_ quantities and shifts: %d >> %d = %d\n", a2, b, a2 >> b);
  printf("The urinary (~) operator converts each 1-bit into a 0-bit and vice versa: ~%d = %d\n", b, ~b);
  printf("getbits of %d = %d\n", 8, getbits(8, 4, 3));
  printf("\n");
  return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

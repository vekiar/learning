/*
 * Exercise 2.10
 * Rewrite the function <lower>, which converts upper case letters to lower
 * case, with a conditional expression instead of <if-else>.
 *
 */

#include <stdio.h>

int lower(int a);

int main()
{
  char a = 'a';
  char b = 'A';
  printf("%c: %d\n%c: %d\n", a, a, b, b);
  printf("%c, %c, %c\n", ('A' + 32), ('B' + 32), ('C' + 32));
  printf("%c: %d\n%c: %d\n", 'z', 'z', 'Z', 'Z');
  printf("Lower of %c is %c\n", 'A', lower('A'));
  printf("Lower of %c is %c\n", 'H', lower('H'));
  printf("Lower of %c is %c\n", 'P', lower('P'));
  printf("Lower of %c is %c\n", 'Z', lower('Z'));
  printf("Lower of %c is %c\n", 9, lower(9));
  printf("Lower of %c is %c\n", '!', lower('!'));
  return 0;
}

int lower(int a)
{
  return (a >= 65 && a <= 90) ? a + 32 : a;
}

/*
 * Exercise 5.6
 * Rewrite appropriate programs from earlier chapters with pointers instead of
 * array indexing.
 *
 */

#include <stdio.h>

int atoi_pointer(char *s);

int main()
{
  char a[] = "1234";
  printf("%d\n", atoi_pointer(a));
  return 0;
}

int atoi_pointer(char *s)
{
  int n = 0;
  for ( ; *s >= '0' && *s <= '9'; *s++)
    n = 10 * n + (*s - '0');
  return n;
}

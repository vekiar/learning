/*
 * Exercise 5.6
 * Rewrite appropriate programs from earlier chapters with pointers instead of
 * array indexing.
 *
 */

#include <stdio.h>

void itoa_pointer(int n, char *s);
void reverse(char *s);
void print_string(char *s);

int main()
{
  int n = -1234;
  char s[10];
  itoa_pointer(n, s);
  print_string(s);
  return 0;
}

void itoa_pointer(int n, char *s)
{
  int sign;
  char *start = s;

  if ((sign = n) < 0)
    n = -n;

  do {
    *s++ = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
    *s++ = '-';
  *s++ = '\0';
  reverse(start);
}

void reverse(char *s)
{
  char *start = s;
  char *end = s;
  char temp;

  while (*end)
    end++;
  end--;

  while (start < end) {
    temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }
}

void print_string(char *s)
{
  while (*s)
    printf("%c", *s++);
  printf("\n");
}

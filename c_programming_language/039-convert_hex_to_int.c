/*
 * Exercise 2.3
 * Write the function htoi(s), which converts a string of hexadecimal digits
 * including an optional 0x or 0X into its equivalent integer value.
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int atoi(char s[]);
int lower(int c);
long int htoi(char h[]);

int main(int argc, char *argv[])
{
  char h1[] = "0xDEADBEEF";
  printf("Hex string; %s is equivalent to integer %ld\n", h1, htoi(h1));
  char h2[] = "200";
  printf("Hex string; %s is equivalent to integer %ld\n", h2, htoi(h2));
  char h3[] = "0x6B2";
  printf("Hex string; %s is equivalent to integer %ld\n", h3, htoi(h3));
  return 0;
}

long int htoi(char h[])
{
  enum hex_codes {A = 10, B, C, D, E, F};
  int i, offset;
  long int n = 0, v;

  if (h[0] == '0' && (h[1] == 'x' || h[1] == 'X'))
    offset = 2;
  else
    offset = 0;

  int exp, length = strlen(h);

  for (i = offset; i < strlen(h); ++i) {
    if (h[i] >= '0' && h[i] <= '9') {
      int a = h[i] - '0';
      exp = length - i - 1;
      v = (a * pow(16, exp));
      n = n + v;
      printf("Found item: %d in position %d, with value: %ld (%d * 16^%d).\n", a, i, v, a, exp);
      printf("%ld\n", n);
    } else if (h[i] == 'A') {
      exp = length - i - 1;
      v = (A * pow(16, exp));
      n = n + v;
      printf("Found item: %d in position %d, with value: %ld (%d * 16^%d).\n", A, i, v, A, exp);
      printf("%ld\n", n);
    } else if (h[i] == 'B') {
      exp = length - i - 1;
      v = (B * pow(16, exp));
      n = n + v;
      printf("Found item: %d in position %d, with value: %ld (%d * 16^%d).\n", B, i, v, B, exp);
      printf("%ld\n", n);
    } else if (h[i] == 'C') {
      exp = length - i - 1;
      v = (C * pow(16, exp));
      n = n + v;
      printf("Found item: %d in position %d, with value: %ld (%d * 16^%d).\n", C, i, v, C, exp);
      printf("%ld\n", n);
    } else if (h[i] == 'D') {
      exp = length - i - 1;
      v = (D * pow(16, exp));
      n = n + v;
      printf("Found item: %d in position %d, with value: %ld (%d * 16^%d).\n", D, i, v, D, exp);
      printf("%ld\n", n);
    } else if (h[i] == 'E') {
      exp = length - i - 1;
      v = (E * pow(16, exp));
      n = n + v;
      printf("Found item: %d in position %d, with value: %ld (%d * 16^%d).\n", E, i, v, E, exp);
      printf("%ld\n", n);
    } else if (h[i] == 'F') {
      exp = length - i - 1;
      v = (F * pow(16, exp));
      n = n + v;
      printf("Found item: %d in position %d, with value: %ld (%d * 16^%d).\n", F, i, v, F, exp);
      printf("%ld\n", n);
    }
  }
  return n;
}

int examples()
{
  // atoi
  char s[] = "4096";
  printf("%d\n", atoi(s));

  // lower
  char a = 'V';
  printf("%c %c\n", a, lower(a));
  return 0;
}

int atoi(char s[])
{
  printf("String of digits passed into <atoi> function: %s\n", s);
  int i, n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
    n = 10 * n + (s[i] - '0');
    //printf("%d %d\n", n, s[i]);
  }
  printf("Going to return: %d\n", n);
  return n;
}

int lower(int c)
{
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}

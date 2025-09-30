/*
 * Exercose 5.5
 * Write a version of <strcat> which operates on at most the first n characters
 * of their argument strings.
 */

#include <stdio.h>

void print_string(char *s, int debug);
void string_cat(char *s, char *t, int n, int offset);
int string_length(char *s);

int main()
{
  char s[] = "Tu vieja ";
  char t[] = " en tanga!";

  print_string(s, 1);
  string_cat(s, t, 3, 4);
  print_string(s, 1);

  return 0;
}

void string_cat(char *s, char *t, int n, int offset)
{
  // FIXME:
  // - boundaries check for offset
  // - boundaries check for n + offset

  while (*s)
    *s++;

  while (offset > 0) {
    *t++;
    offset--;
  }

  while (n > 0) {
    *s++ = *t++;
    n--;
  }
}

void print_string(char *s, int debug)
{
  if (debug)
    printf("String: ");

  while (*s)
    printf("%c", *s++);
  printf("\n");
}

int string_length(char *s)
{
  int i = 0;
  while (*s++)
    i++;
  return i;
}

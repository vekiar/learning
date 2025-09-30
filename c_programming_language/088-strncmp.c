/*
 * Exercose 5.5
 * Write a version of <strcmp> which operates on at most the first n characters
 * of their argument strings.
 */


#include <stdio.h>

int string_compare(char *s, char *t, int n);
void print_string(char *s, int debug);

int main()
{
  char s[] = "Tu vieja en tanga!";
  char t[] = "Peanuts";
  char u[] = "Tu";

  print_string(s, 1);
  print_string(t, 1);
  print_string(u, 1);

  if (string_compare(s, t, 3))
    printf("t is a subset of s\n");
  else
    printf("t is *not* a subset of s\n");
    
  if (string_compare(s, u, 2))
    printf("u is a subset of s\n");
  else
    printf("u is *not* a subset of s\n");

  return 0;
}

int string_compare(char *s, char *t, int n)
{
  while (n > 0) {
    if (*s++ != *t++)
      return 0;
    n--;
  }
  return 1;
}

void print_string(char *s, int debug)
{
  if (debug)
    printf("String: ");

  while (*s)
    printf("%c", *s++);
  printf("\n");
}

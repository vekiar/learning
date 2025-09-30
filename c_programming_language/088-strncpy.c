/*
 * Exercose 5.5
 * Write a version of <strcpy> which operates on at most the first n characters
 * of their argument strings.
 */

#include <stdio.h>

void string_copy(char *s, char *t, int n, int offset);
void print_string(char *s, int debug);
int string_length(char *s);

int main()
{
  char s[] = "Tu vieja en tanga!";
  char t[string_length(s)];

  string_copy(s, t, 7, 3);

  print_string(s, 1);
  print_string(t, 1);

  return 0;
}

void string_copy(char *s, char *t, int n, int offset)
{
  while (offset > 0) {
    s++;
    offset--;
  }

  while (n > 0) {
    *t++ = *s++;
    n--;
  }
}

void print_string(char *s, int debug)
{
  if (debug)
    printf("String: ");
  while (*s != '\0')
    printf("%c", *s++);
  printf("\n");
}

int string_length(char *s)
{
  int i = 0;
  while (*s++ != '\0')
    i++;

  return i;
}

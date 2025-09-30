/*
 * Exercise 5.4
 * Write the function <strend> which returns 1 if the string t occurs at the
 * end of the string s, and zero otherwise.
 *
 */

#include <stdio.h>

int strend(char *s, char *t);
void print_string(char *s, int debug);

int main()
{
  char s[] = "Tu vieja en tanga!";
  char t[] = "peanut";
  char u[] = "tanga!";

  if (strend(s, t))
    printf("t occurs at the end of s\n");
  else
    printf("t does not occur at the end of s\n");

  if (strend(s, u))
    printf("u occurs at the end of s\n");
  else
    printf("u does not occur at the end of s\n");

  return 0;
}

int strend(char *s, char *t)
{
  char *so = s;
  char *to = t;

  while (*s)
    *s++;

  while (*t)
    *t++;

  while (t > to) {
    s--;
    t--;
    if (*s != *t)
      return 0;
  }

  return 1;
}

void print_string(char *s, int debug)
{
  if (debug == 1)
    printf("String: ");

  while (*s != '\0')
    printf("%c", *s++);

  printf("\n");
}

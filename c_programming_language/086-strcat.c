/*
 * Exercise 5.3
 * Write a pointer version of the function <strcat> from Chapter 2.
 *
 */

#include <stdio.h>

void strcat_old(char *s, char *t);
void strcat_pointer(char *s, char *t);
void print_string(char *s, int debug);

int main()
{
  char s1[] = "Tu vieja";
  char s2[] = " en tanga!";
  strcat_old(s1, s2);
  print_string(s1, 1);
  print_string(s2, 1);
  
  char t1[] = "Tu vieja";
  char t2[] = " en tanga!";
  strcat_pointer(t1, t2);
  print_string(t1, 1);
  print_string(t2, 1);

  return 0;
}

void strcat_old(char *s, char *t)
{
  int i, j;
  i = j = 0;
  while (s[i] != '\0')
    i++;
  while ((s[i++] = t[j++]) != '\0')
    ;
}

void strcat_pointer(char *s, char *t)
{
  while (*s != '\0')
    *s++;
  while ((*s++ = *t++) != '\0')
    ;
}

void print_string(char *s, int debug)
{
  if (debug == 1)
    printf("String: ");
  while (*s != '\0')
    printf("%c", *s++);
  printf("\n");
}

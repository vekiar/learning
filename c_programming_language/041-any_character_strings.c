/*
 * Exercise 2.5
 * Write a function <any(s1, s2)> that returns the first location in the string
 * s1 where any character fron the string s2 occurs, or -1 if s1 contains no
 * characters from s2. 
 *
*/

#include <stdio.h>
#define MAXLEN 100

int is_char_in(char c, char s[]);

int main()
{
  char s1[MAXLEN] = "ubercalifagrilisticoespialidoso";
  char s2[MAXLEN] = "ananas";
  signed int index = -1;

  for (int i = 0; i < MAXLEN - 1 && s1[i] != '\0'; ++i) {
    if (is_char_in(s1[i], s2) == 0 && index == -1) {
      index = i + 1; // Because the char array starts at 0
    }
  }
  if (index > -1) {
    printf("Position %d\n", index);
  } else {
    printf("Not found\n");
  }
  return 0;
}

int is_char_in(char c, char s[])
{
  for (int i = 0; i < MAXLEN - 1; ++i) {
    if (c == s[i])
      return 0;
  }
  return 1;
}

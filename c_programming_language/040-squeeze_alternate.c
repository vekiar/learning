/*
 * Exercise 2.4
 * Write an alternate version of <squeeze(s1, s2)> that deletes each character
 * in s1 that matches any character in the string s2.
 *
*/

#include <stdio.h>
#define MAXLEN 100

int is_char_in(char c, char s[]);

int main()
{
  char s1[MAXLEN] = "verxeculer";
  char s2[MAXLEN] = "ananas";
  for (int i = 0; i < MAXLEN - 1 && s1[i] != '\0'; ++i) {
    if (is_char_in(s1[i], s2) == 1)
      printf("%c", s1[i]);
  }
  printf("\n");
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

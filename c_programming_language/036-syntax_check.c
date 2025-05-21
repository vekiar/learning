/*
 * Exercise 1.24 
 * Write a program to check for rudimantary syntax:
 * - Unbalanced parenthesis, brackets, braces
 * - Quotes, single and double
 * - Escape sequences and comments
 * (This program is hard in full generality)
 */

#include <stdio.h>
#define MAXLINE 1000

int getlines(char line[], int maxline);

int main()
{
  char line[MAXLINE];
  int len;

  int parens = 0, brackets = 0, braces = 0; // 0 is "balanced"
  int quotes_double = 0, quotes_single = 0, escape = 0; // 0 is "balanced" !FIXME: escapes?
  int comment = 0; // are we inside a comment?
  int c;

/*
  printf("Parenthesis: %d\n", parens);
  printf("Brackets: %d\n", brackets);
  printf("Braces: %d\n", braces);
  printf("Double Quotes: %d\n", quotes_double);
  printf("Single Quotes: %d\n", quotes_single);
*/

  while ((len = getlines(line, MAXLINE)) > 0) {
    for (int i = 0; i < len - 1; ++i) {
      c = line[i];
      if (c == '(')
        //printf("OPEN_PAREN\n");
        parens -= 1;
      if (c == ')')
        //printf("CLOSE_PAREN\n");
        parens += 1;
      if (c == '{')
        //printf("OPEN_BRACE\n");
        braces -= 1;
      if (c == '}')
        //printf("CLOSE_BRACE\n");
        braces += 1;
      if (c == '[')
        //printf("OPEN_BRACKET\n");
        brackets -= 1;
      if (c == ']')
        //printf("CLOSE_BRACKET\n");
        brackets += 1;
      if (c == '"')
        quotes_double += 1;
      if (c == '\'')
        quotes_single += 1;
    }
  }

/*
  printf("Parenthesis: %d\n", parens);
  printf("Brackets: %d\n", brackets);
  printf("Braces: %d\n", braces);
  printf("Double Quotes: %d\n", quotes_double);
  printf("Single Quotes: %d\n", quotes_single);
*/

  if (parens != 0) {
    if (parens > 0)
      printf("You have closed too many parens!\n");
    if (parens < 0)
      printf("You have open parens you need to close!\n");
  }

  if (braces != 0) {
    if (braces > 0)
      printf("You have closed too many braces!\n");
    if (braces < 0)
      printf("You have open braces you need to close!\n");
  }

  if (brackets != 0) {
    if (brackets > 0)
      printf("You have closed too many brackets!\n");
    if (brackets < 0)
      printf("You have open brackets you need to close!\n");
  }

  if ((quotes_double % 2) != 0) {
      printf("You are missing \"s somewhere!\n");
  }

  if ((quotes_single % 2) != 0) {
      printf("You are missing \'s somewhere!\n");
  }

  return 0;
}

int getlines(char lines[], int maxline)
{
  int c, i;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF; ++i) {
    lines[i] = c;
  }
  return i;
}

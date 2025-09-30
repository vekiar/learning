/*
 * Exercise 5.6
 * Rewrite appropriate programs from earlier chapters with pointers instead of
 * array indexing.
 *
 */

#include <stdio.h>

#define MAX 1000

int getline_pointer(char *s);
void print_string(char *s);

int main()
{
  char s[MAX];
  while (getline_pointer(s) > 0) {
    print_string(s);
  }
  return 0;
}

int getline_pointer(char *s)
{
  int i = 0, c; 
  for ( ; *s < MAX - 1 && (c = getchar()) != EOF && c != '\n'; *s++) {
    *s = c;
  }

  if (c == '\n') {
    *s++ = c;
    i++;
  }

  *s++ = '\0';
  i++;

  return i;
}

void print_string(char *s)
{
  while (*s)
    printf("%c", *s++);
  printf("\n");
}

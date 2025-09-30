/*
 * Exercise 5.6
 * Rewrite appropriate programs from earlier chapters with pointers instead of
 * array indexing.
 *
 */

#include <stdio.h>
#include <ctype.h>

#define BUFFSIZE 100
#define NUMBER '0'
#define MAXLINE 100

int getop_array(char s[]);
int getop_pointer(char *s);
int getch(void);
void ungetch(int c);

char buf[BUFFSIZE];
int bufp = 0;

int main()
{
  char s[MAXLINE];
  int type1 = getop_array(s);
  printf("%c\n", type1);
  // Below "fails" at runtime because these both pull from the same stack (ponéle).
  int type2 = getop_pointer(s);
  printf("%c\n", type2);
  return 0;
}

int getop_array(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  
  s[1] = '\0';
  
  if (!isdigit(c) && c != '.')
    return c;
  
  i = 0;
  
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  
  s[i] = '\0';

  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

int getop_pointer(char *s)
{
  int c;
  while ((*s = c = getch()) == ' ' || c == '\t')
    ;

  *(s+1) = '\0';

  if (!isdigit(c) && c != '.')
    return c;

  if (isdigit(c))
    while (isdigit(*s++ = c = getch()))
      ;

  if (c == '.')
    while (isdigit(*s++ = c = getch()))
      ;
  
  *s = '\0';
  if (c != EOF)
    ungetch(c);

  return NUMBER;
}

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
  
}

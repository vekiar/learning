#include <stdio.h>
#include <ctype.h>

#define BUFFSIZE 100

int getint(int *n);
int getch(void);
void ungetch(int);
void print_array(int n[]);
void init_array(int n[]);

char buf[BUFFSIZE];
int bufp = 0;

int main()
{
  int n, array[BUFFSIZE];
  init_array(array);
  print_array(array);
  for (n = 0; n < BUFFSIZE && getint(&array[n]) != EOF; n++)
    ;
  print_array(array);

  return 0;
}

int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
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

void print_array(int n[])
{
  for (int i = 0; i < BUFFSIZE - 1; i++)
    printf("%d ", n[i]);
  printf("\n");
}

void init_array(int n[])
{
  for (int i = 0; i < BUFFSIZE - 1; i++)
    n[i] = 0;
}

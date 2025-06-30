/*
 * Exercise 5.2
 * Write <getfloat>, the floating point analog of <getint>.
 *
 */

#include <stdio.h>
#include <ctype.h>

#define BUFFSIZE 100

double getfloat(double *pf);
int getch(void);
void ungetch(int);
void print_array(double f[]);
void init_array(double f[]);

char buf[BUFFSIZE];
int bufp = 0;

int main()
{
  double array[BUFFSIZE];
  int n;
  init_array(array);
  print_array(array);
  for (n = 0; n < BUFFSIZE && getfloat(&array[n]) != EOF; n++)
    ;
  print_array(array);
  return 0;
}

double getfloat(double *pf)
{
  int c, sign;
  double power;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  
  if (c == '+' || c == '-') {
    char next = getch();
    if (!isdigit(next)) {
      ungetch(next);
      ungetch(c);
      return 0;
    }
    c = next;
  }

  *pf = 0.0;

  // Whole Part
  while (isdigit(c)) {
    *pf = 10.0 * *pf + (c - '0');
    c = getch();
  }

  // Fraction part
  if (c == '.') {
    c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
      *pf = 10.0 * *pf + (c - '0');
      power *= 10.0;
    }
    *pf /= power;
  }

  *pf *= sign;

  if (c != EOF)
    ungetch(c);

  return c;
}

void print_array(double array[])
{
  for (int i = 0; i < BUFFSIZE - 1; i++)
    printf("%.2f ", array[i]);
  printf("\n");
}

void init_array(double array[])
{
  for (int i = 0; i < BUFFSIZE - 1; i++)
    array[i] = 0.0;
  printf("\n");
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

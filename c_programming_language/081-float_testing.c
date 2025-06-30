#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int getlines(char line[], int limit);
double getfloat(char line[]);

int main()
{
  char line[MAXLINE];
  while ((getlines(line, MAXLINE)) > 0) {
    printf("Value = %f\n", getfloat(line));
  }
  return 0;
}

double getfloat(char line[])
{
  char c;
  double f = 0.0, fraction = 0.0, sign;
  for (int i = 0; i < MAXLINE - 1 && line[i] != '\0'; i++) {
    c = line[i];

    if (c == '+' || c == '-') {
      sign = (c == '-') ? -1 : 1;
      continue;
    }

    if (c == '.') {
      printf("PERIOD!\n");
      int dp = 1;
      for (i++; i < MAXLINE - 1 && line[i] != EOF && line[i] != '\0'; i++, dp++) {
        c = line[i];
        fraction = 10 * fraction + (c - '0');
        printf("Whole = %f, Fraction = %f\n", f, fraction);
      }
      if (dp > 0)
        printf("Adjusting fractional part to %d decimal places:\n", dp);
      for (int j = 1; j < dp; j++) {
        fraction = fraction / 10.0;
        printf("%d: %f\n", j, fraction);
      }
      break;
    }
    f = 10 * f + (c - '0');
    printf("Whole = %f, Fraction = %f\n", f, fraction);
  }

  printf("Whole = %f, Fraction = %f\n", f, fraction);
  f = f + fraction;
  f *= sign;
  return f;
}

int getlines(char line[], int limit)
{
  int i, c;
  for (i = 0; (c = getchar()) != EOF && i < limit - 1 && c != '\n'; i++)
    line[i] = c;
  line[i] = '\0';
  return i;
}

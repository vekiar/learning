/*
 * Exercise 4.2
 * Extend <atof> to handle scientific notation of the form:
 * 123.45e-6
 * where a floating point number may be followed by e or E and an optionally
 * signed exponent.
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 1000

int getlines(char line[], int lim);
double atof(char line[]);

int main()
{
   double sum, atof(char []);
   char line[MAXLINE];

   sum = 0;
   while (getlines(line, MAXLINE) > 0)
      printf("\t%g\n", sum += atof(line));
   return 0;
}

int getlines(char line[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
     line[i++] = c;
  if (c == '\n')
     line[i++] = c;
  line[i] = '\0';

  return i;
}

double atof(char line[])
{
   double val, power;
   int i, sign;

   for (i = 0; isspace(line[i]); i++) // skip whitespace
      ;
   sign = (line[i] == '-') ? -1 : 1;

   if (line[i] == '+' || line[i] == '-')
      i++;

   for (val = 0.0; isdigit(line[i]); i++)
      val = 10.0 * val + (line[i] - '0');
   
   if (line[i] == '.')
      i++;

   for (power = 1.0; isdigit(line[i]); i++) {
      val = 10.0 * val + (line[i] - '0');
      power *= 10.0;
   }

   if (line[i] == 'e' || line[i] == 'E') {
      int exp_sign;
      double exponent;
      double base = 10.0; // base is hardcoded
      i++;
      
      if (line[i] == '-') {
         exp_sign = -1;
         i++;
      } else {
         exp_sign = 1;
      }

      for (exponent = 0.0; isdigit(line[i]); i++) {
         exponent = 10.0 * exponent + (line[i] - '0');
         //printf("Position: %d, Value: %d, Exponent: %f\n", i, line[i] - '0', exponent);
      }
      if (exp_sign == 1)
         val = val * pow(base, exponent);
      else if (exp_sign == -1)
         val = val / pow(base, exponent);
      else
         printf("ERROR: Something went wrong!\n");
   }
   return sign * val / power;
}
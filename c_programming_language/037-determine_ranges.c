/*
 * Exercise 2.1
 * Write a program to determine the ranges of char, short, int, and long variables.
 * You can print (easy) or compute (hard)
 *
 */


#include <stdio.h>
#include <limits.h>
#include <float.h>

void print_values();
void compute_values();

int main()
{
  print_values();
  compute_values();
  return 0;
}

void print_values()
{
  printf("## PRINT\n");

  printf("### CHAR\n");
  // char
  char char_max = CHAR_MAX;
  char char_min = CHAR_MIN;
  printf("Char Max: %d \t Char Min: %d \n", char_max, char_min);

  // Usigned char
  unsigned char char_umax = UCHAR_MAX;
  unsigned char char_umin = CHAR_MIN;
  printf("Unsigned Char Max: %u \t Unsigned Char Min: %u \n", char_umax, char_umin);

  // Signed char
  signed char char_smax = SCHAR_MAX;
  signed char char_smin = SCHAR_MIN;
  printf("Signed Char Max: %d \t Signed Char Min: %d \n", char_smax, char_smin);

  printf("### INT\n");
  // int
  int int_max = INT_MAX;
  int int_min = INT_MIN;
  printf("Int Max: %i \t Int Min: %i \n", int_max, int_min);

  // Unsigned int
  unsigned int int_umax = UINT_MAX;
  unsigned int int_umin = 0;
  printf("Unsigned Int Max: %u \t Unsigned Int Min: %u \n", int_umax, int_umin);

  // Signed int
  signed int int_smax = INT_MAX;
  signed int int_smin = INT_MIN;
  printf("Signed Int Max: %d \t Signed Int Min: %d \n", int_smax, int_smin);

  printf("### SHORT INT\n");
  // Short int
  short int sint_max = SHRT_MAX;
  short int sint_min = SHRT_MIN;
  printf("Short Int Max: %hi \t Short Int Min: %hi \n", sint_max, sint_min);

  // Unsigned short int
  short int sint_umax = USHRT_MAX;
  short int sint_umin = 0;
  printf("Unsigned Short Int Max: %hu \t Unsigned Short Int Min: %hu \n", sint_umax, sint_umin);

  // Signed short int
  short int sint_smax = SHRT_MAX;
  short int sint_smin = SHRT_MIN;
  printf("Signed Short Int Max: %hd \t Signed Short Int Min: %hd \n", sint_smax, sint_smin);

  printf("### LONG INT\n");
  // Long int
  long int lint_max = LONG_MAX;
  long int lint_min = LONG_MIN;
  printf("Long Int Max: %li \t Long Int Min: %li \n", lint_max, lint_min);

  // Unsigned long int
  unsigned long int lint_umax = ULONG_MAX;
  unsigned long int lint_umin = 0;
  printf("Unsigned Long Int Max: %lu \t Unsigned Long Int Min: %lu \n", lint_umax, lint_umin);

  // Signed long int
  signed long int lint_smax = LONG_MAX;
  signed long int lint_smin;
  printf("Signed Long Int Max: %ld \t Signed Long Int Min: %ld \n", lint_smax, lint_smin);

  // long long int
  long long int llint_max = LLONG_MAX;
  long long int llint_min = LLONG_MIN;
  printf("Long Long Int Max: %lli \t Long Long Int Min: %lli \n", llint_max, llint_min);

  // unsigned long long int
  unsigned long long int llint_umax = ULLONG_MAX;
  unsigned long long int llint_umin = 0;
  printf("Unsigned Long Long Int Max: %llu \t Unsigned Long Long Int Min: %llu \n", llint_umax, llint_umin);

  // signed long long int
  signed long long int llint_smax = LLONG_MAX;
  signed long long int llint_smin = LLONG_MIN;
  printf("Signed Long Long Int Max: %lld \t Signed Long Long Int Min: %lld \n", llint_smax, llint_smin);

  // float
  float float_max = FLT_MAX;
  float float_min = FLT_MIN_EXP;
  printf("Float Max: %f \t Float Min: %f \n", float_max, float_min);

  // double
  double double_max = DBL_MAX;
  double double_min = DBL_MIN;
  printf("Double Max: %lf \t Double Min: %lf \n", double_max, double_min);

  // long double
  long double ldouble_max = LDBL_MAX;
  long double ldouble_min = LDBL_MIN;
  printf("Long Double Max: %Lf \t Long Double Min: %Lf \n", ldouble_max, ldouble_min);

}

void compute_values()
{
}

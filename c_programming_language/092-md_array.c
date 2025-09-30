/*
 * C provides rectangular, multi-dimensional arrays, although they are less
 * used than arrays of pointers.
 *
 */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main()
{
  int day, month;
  int *pday = &day;
  int *pmonth = &month;

  month_day(2025, 268, pmonth, pday);
  printf("The 268th day of 2025 is the %dth day of the %dth month.\n", day, month);
  printf("26/09/2025 is the %dth day of the year.\n", day_of_year(2025, 9, 25));

  return 0;
}

int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}

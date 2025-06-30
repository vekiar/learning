#include "084-slice.h"

int main()
{
  char s1[] = "Tu vieja en tanga!";
  slice(s1, 0, -1);
  slice(s1, 3, 11);
  slice(s1, -1, 0);
  slice(s1, -2, 15);
  slice(s1, 2, 150);
  return 0;
}

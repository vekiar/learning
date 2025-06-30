#include <stdio.h>

int vv_strlen(char *s);

int main()
{
  char s[] = "Tu vieja en tanga!";
  printf("String Length = %d\n", vv_strlen(s));
  return 0;
}

int vv_strlen(char *s)
{
  char *p = s;

  while (*p != '\0')
    p++;

  return p - s;
}

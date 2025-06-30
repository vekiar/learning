#include <stdio.h>

#undef v_strlen

int v_strlen(char *s);

int main()
{
  char s[] = "Tu Vieja En Tanga!";
  printf("String Length = %d\n", v_strlen(s));
  return 0;
}

int v_strlen(char *s)
{
  int n;
  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}

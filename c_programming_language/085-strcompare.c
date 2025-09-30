#include <stdio.h>

int strcompare_array(char *s, char *t);
int strcompare_pointer(char *s, char *t);

int main()
{
  char s1[] = "Tu Vieja En Tanga!";
  char s2[] = "Tu Vieja En Tanga!";
  printf("s1 and s2 compare = %d\n", strcompare_array(s1, s2));
  printf("s1 and s2 compare = %d\n", strcompare_pointer(s1, s2));
  return 0;
}

int strcompare_array(char *s, char *t)
{
  int i;

  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

int strcompare_pointer(char *s, char *t)
{
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}

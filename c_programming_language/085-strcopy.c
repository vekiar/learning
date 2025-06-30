#include <stdio.h>

void strcopy_array(char *s, char *t);
void strcopy_pointer(char *s, char *t);
int strlength(char *s);
void print_string(char *s);

int main()
{
  char s[] = "Tu vieja en tanga!";
  int s_len = strlength(s);

  char t1[s_len];
  char t2[s_len];

  strcopy_array(s, t1);
  strcopy_pointer(s, t2);

  print_string(s);
  print_string(t1);
  print_string(t2);

  return 0;
}

void strcopy_array(char *s, char *t)
{
  int i;
  i = 0;

  while ((t[i] = s[i]) != '\0')
    i++;
}

void strcopy_pointer(char *s, char *t)
{
  while (*t++ = *s++)
    ;
}

int strlength(char *s)
{
  int n = 0;
  while (*s++ != '\0')
    n++;
  return n;
}

void print_string(char s[])
{
  while (*s != '\0')
    printf("%c", *s++);
  printf("\n");
}

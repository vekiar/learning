#include <stdio.h>

void slice(char *s, int start, int end);
int v_strlen(char *s);

int main()
{
  char s1[] = "Tu vieja en tanga!";
  slice(s1, 0, v_strlen(s1));
  slice(s1, 3, 7);
  slice(s1, 9, 11);
  slice(s1, v_strlen(s1), 0);
  return 0;
}

void slice(char *s, int start, int end)
{
  printf("Start: %d, End: %d\t=> \"", start, end);

  if (start < end) {
    --start;
    while (start < end) {
      printf("%c", s[start]);
      start++;
    }
  } else if (start > end) {
    while ((start + 1) > end) {
      printf("%c", s[start]);
      start--;
    }
  } else {
    printf("Something went wrong!\n");
  }
//  for (int i = start - 1; i < end; i++ )
//    printf("%c", s[i]);
  printf("\"\n");
}


int v_strlen(char *s)
{
  int n = 0;
  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}

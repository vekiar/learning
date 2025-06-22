#include <stdio.h>

int main()
{
  int i, c, lim = 1000;
  char s[lim];

  for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;

  for (i = 0; i < lim - 1; ++i) {
    c = getchar();
    if (c == '\n') {
      break;
    } else if (c == EOF) {
      break;
    } else {
      s[i] = c;
    }
  }
  return 0;
}

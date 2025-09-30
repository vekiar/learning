/*
 * Exercise 5.6
 * Rewrite appropriate programs from earlier chapters with pointers instead of
 * array indexing.
 *
 */

#include <stdio.h>

int strindex_pointer(char *s, char *t);
int strindex_array(char s[], char t[]);

int main()
{
  char s[] = "Tu vieja en tanga!";
  char t[] = "Peanuts";
  char u[] = "vieja";

  printf("Array Indexing: \n");
  printf("%d\n", strindex_array(s, t));
  printf("%d\n", strindex_array(s, u));

  printf("Pointers: \n");
  printf("%d\n", strindex_pointer(s, t));
  printf("%d\n", strindex_pointer(s, u));

  return 0;
}

int strindex_pointer(char *s, char *t)
{
  int position;

  for (position = 0; *s != '\0'; position++) {
    char *s1 = s;
    char *t1 = t;
    for ( ; *t != '\0' && *s1 == *t1; ) {
      //printf("%c, %c\n", *s1, *t1);
      s1++;
      t1++;
    }
    if (*t1 == '\0')
      return position;
    s++;
  }

  return -1;
}

int strindex_array(char s[], char t[])
{
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;  
}

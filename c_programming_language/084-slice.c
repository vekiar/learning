#include <stdio.h>
#include "084-slice.h"

void slice(char s[], int start, int end)
{
  if (slice_boundaries_check(s, start, end)) {
    printf("Start: %d, End: %d\t=>\t", start, end);
    if (start == -1)
      start = v_arraylen(s);

    if (end == -1)
      end = v_arraylen(s);

    if (start < end) {
      while (start <= end)
        printf("%c", s[start++]);
    } else if (start > end) {
      while (start >= end)
        printf("%c", s[start--]);
    } else {
      printf("ERROR: something went wrong.");
    }
    printf("\n");
  }
}

int slice_boundaries_check(char s[], int start, int end)
{
  int l = v_arraylen(s);

  if (!(l > 0)) {
    printf("ERROR: You passed a 0 length array.\n");
    return 0;
  }

  if (start < -1 || start > l || end < -1 || end > l) {
    printf("ERROR: Requested slice is out of array bounds.\n");
    return 0;
  }
}

int v_arraylen(char s[])
{
  int n;
  for (n = 0; s[n] != '\0' && s[n] != EOF; n++)
    ;

  return n;
}

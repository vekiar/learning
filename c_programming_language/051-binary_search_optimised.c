/*
 * Exercise 3.1
 * Our binary search makes two tests inside the loop. Write a version with
 * only one test inside the loop and measure the difference in runtime.
 *
 */


#include <stdio.h>

int binarysearch(int x, int v[], int n);

int main()
{
  int a[100];
  for (int i = 0; i < 100; i++)
    a[i] = i + 1;
  printf("%d\n", binarysearch(15, a, 100));
  return 0;
}

int binarysearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  mid = (low + high) / 2;

  while (low <= high && x != v[mid]) {
    mid = (low + high) / 2;
    (x < v[mid]) ? (high = mid - 1) : (low = mid + 1);
  }
  if (x == v[mid])
    return mid;
  else
    return -1;
}

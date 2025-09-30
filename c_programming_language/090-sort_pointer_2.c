#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000
#define MAX 1000

int readlines(char *lineptr[], int nlines, char s[], char *p);
void writelines(char *lineptr[], int nlines);
int getlines(char *s, int limit);
//char *alloc(int);
void qsort(char *lineptr[], int left, int right);
void print_array(char s[]);
void init_array(char s[]);

char *lineptr[MAXLINES];
//static char allocbuf[ALLOCSIZE];
//static char *allocp = allocbuf;

int main()
{
  printf("===MAIN===\n");
  int nlines;
  char s[ALLOCSIZE];
  char *p = s;
  init_array(s);

  if ((nlines = readlines(lineptr, MAXLINES, s, p)) >= 0) {
    printf("nlines: %d\n", nlines); 
    //print_array(s);
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("nlines: %d\n", nlines); 
    printf("ERROR: input too big to sort.\n");
    return 1;
  }

  return 0;
}

int readlines(char *lineptr[], int maxlines, char s[], char *p)
{
  printf("===READLINES===\n");
  int len, nlines;
  char line[MAXLEN];

  nlines = 0;
  while ((len = getlines(line, MAXLEN)) > 0)
    if (nlines >= maxlines) 
      return -1;
    else {
      line[len - 1] = '\0';
      printf("Copying line into s position: %p\n", p);
      strcpy(p, line);
      printf("Adding position %p into line pointer registry\n", p);
      lineptr[nlines++] = p;
      p += len;
    }
  return nlines;
}

void writelines(char *lineptr[], int nlines)
{
  printf("===WRITELINES===\n");
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right)
{
  printf("===QSORT===\n");
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
  printf("===SWAP===\n");
  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

//char *alloc(int n)
//{
//  printf("===ALLOC===\n");
//  if (allocbuf + ALLOCSIZE - allocp >= n) {
//    allocp += n;
//    return allocp - n;
//  } else {
//    return 0;
//  }
//}

int getlines(char *s, int limit)
{
  printf("===GETLINES===\n");
  int c;
  char *start = s;

  while (--limit > 0 && (c = getchar()) != EOF && c != '\n')
    *s++ = c;

  if (c == '\n')
    *s++ = c;

  *s = '\0';
  return s - start;
}

void print_array(char s[])
{
  printf("===PRINT_ARRAY===\n");
  int i;
  for (i = 0; i < ALLOCSIZE - 1; i++) {
    printf("%c", s[i]);
  }
  printf("\n");
}

void init_array(char s[])
{
  for (int i = 0; i < ALLOCSIZE - 1; i++) {
    s[i] = ' ';
  }
  s[0] = '\0';
}

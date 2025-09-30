#include <stdio.h>
#include <string.h>

#define MAXLINES 5000                                     // max number of lines to be sorted

char *lineptr[MAXLINES];                                  // pointers to text lines

int readlines(char *lineptr[], int nlines, char buffer[], int buffer_size);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main()
{
  int nlines; // number of input lines read
  int allocsize = 10000;
  char buffer[allocsize];

  if ((nlines = readlines(lineptr, MAXLINES, buffer, allocsize)) >= 0) {     // if your input is >= 0 lines
    qsort(lineptr, 0, nlines - 1);                        // sort them
    writelines(lineptr, nlines);                          // write them
    return 0;                                             // end the program
  } else {
    printf("Error: input too big to sort\n");             // else throw an error
    return 1;                                             // end the program wit an error code
  }
}

#define MAXLEN 1000                                       // max length of any one input line
int getlines(char *, int);
//char *alloc(int);

int readlines(char *lineptr[], int maxlines, char buffer[], int buffer_size)              // read input lines
{
  int len, nlines;
  char line[MAXLEN], *p = buffer;

  nlines = 0;
  while ((len = getlines(line, MAXLEN)) > 0)              // as long as the line as a length > 0
    if (nlines >= maxlines || ((p + len) > (buffer + buffer_size)))   // if the number of lines exceeds maxlines, or allocating <len> in the pointer array is not possible
      return -1;                                          // end the program with an error
    else {
      line[len - 1] = '\0';                               // delete newline
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len;
    }
  return nlines;
}

void writelines(char *lineptr[], int nlines)              // write output lines
{
  int i;
  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

int getlines(char s[], int lim)                            // read a line into an array, return length
{
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

//#define ALLOCSIZE 10000                                   // size of available space
//static char allocbuf[ALLOCSIZE];                          // storage for alloc
//static char *allocp = allocbuf;                           // next free position (starts at the start of allocbuf)
//
//char *alloc(int n)                                        // return pointer to n characters
//{
//  if (allocbuf + ALLOCSIZE - allocp >= n) {               // if it fits
//    allocp += n;
//    return allocp - n;                                    // return a pointer to the start position
//  } else {
//    return 0;
//  }
//}

void qsort(char *v[], int left, int right)                       // sort v[lef] ... v[right] into increasing order
{
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)                                      // if array contains fewer than two elements
    return;                                               // do nothing

  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)                        // interchange v[i] and v[j]
{
  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

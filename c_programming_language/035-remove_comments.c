/*
 * Exercise 1.23
 * Write a program to remove all comments from a C program.
 */

#include <stdio.h>
#define MAXLINE 1000

int getlines(char line[], int maxline);

int main()
{
  char line[MAXLINE];
  int len;

  while ((len = getlines(line, MAXLINE)) > 0) {
    printf("%s", line);
  }
  return 0;
}

int getlines(char line[], int maxline)
{
  int c, p, i;
  int comment = 0;
  int track = 0;
  int nested = 0;
  
  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF; ++i) {
    if (c == '/' && p == '/') {
      comment = 1;
      track = i;
    }

    if (c == '*' && p == '/' && nested == 0) {
      //printf("NESTED\n");
      comment = 1;
      nested = 1;
      track = i;
    }

    if (c == '/' && p == '*') {
      if (comment == 1 && nested == 1) {
        //printf("END NESTED\n");
        comment = 0;
        nested = 0;
        i = track - 1;
        c = ' '; // HACK !!FIXME
      } else if (comment == 0) {
        line[i] = c;
      }
    }

    if (c == '\n') {
      if (comment == 1 && nested == 0) {
        comment = 0;
        i = track - 1;
      } 
    }

    if (comment == 0) {
      line[i] = c;
    }

    p = c;
  }

  line[i] = '\0';
  return i;
}

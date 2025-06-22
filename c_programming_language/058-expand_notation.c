/*
 * Exercise 3.3
 * Write a function <expand(s1, s2)> that expands shorthand noation like a-z
 * in the string s1 into the equivalent complete list abc...xyz in s2. Allow
 * for letters of either case and digits, handle cases like a-b-c and
 * a-z0-9 or -a-z. A leading or trailing - is taken literally.
 *
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void expand(char s1[], char s2[]);
void print_string(char s[]);
void print_block(char s[], char es[]);

int main()
{
    char s1[] = "a-z";
    char s2[] = "A-Z";
    char s3[] = "0-9";
    char s4[] = "A-z";
    char s5[] = "a-b-c";
    char s6[] = "a-z0-9";
    char s7[] = "-a-z";
    char es[MAXLEN];

    print_block(s1, es);
    print_block(s2, es);
    print_block(s3, es);
    print_block(s4, es);
    print_block(s5, es);
    print_block(s6, es);
    print_block(s7, es);

    return 0;
}

void expand(char s1[], char s2[])
{
    int order, i, j, nstrings;
    int start[2], end[2];
    
    order = 0;

    int l = strlen(s1);
    printf("String Length: %d\n", l);
    switch (strlen(s1)) {
        case 3:
            // FIXME: implement checks
            nstrings = 1;
            start[0] = s1[0];
            end[0] = s1[2];
            break;
        case 4:
            nstrings = 1;
            if (s1[0] == '-') {
                order = 1;
                start[0] = s1[1];
                end[0] = s1[3];
            }
            else
                printf("This looks like a malformed string\n");
            break;
        case 5:
            nstrings = 2; // a-b is one string, b-c is another
            start[0] = s1[0];
            end[0] = s1[2];
            start[1] = s1[2];
            end[1] = s1[4];
            break;
        case 6:
            nstrings = 2;
            start[0] = s1[0];
            end[0] = s1[2];
            start[1] = s1[3];
            end[1] = s1[5];
            break;
        default:
            printf("You need to enter one or more consecutive strings in the format a-z / A-Z0-9.\n");
    }

    for (i = 0; i < nstrings; i++) {
        printf("String %d, start: %c, end: %c\n", i + 1, start[i], end[i]);
    }
   
    int s = j = 0;
    while (s < nstrings) {
        if (order) {
            for (i = end[s]; i >= start[s]; i--, j++)
                s2[j] = i;
        } else {
            for (i = start[s]; i <= end[s]; i++, j++)
                s2[j] = i;
        }
        s++;
    }
    s2[j] = '\0';
}

void print_string(char s[])
{
    int i = 0;
    while (s[i] != '\0') {
        printf("%c", s[i]);
        ++i;
    }
    printf("\n");
}

void print_block(char s[], char es[])
{
    printf("String: ");
    print_string(s);
    expand(s, es);
    printf("Expanded: ");
    print_string(es);
    printf("\n");
}
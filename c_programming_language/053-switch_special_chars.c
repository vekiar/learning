/*
 * Exercise 3.2
 * Write a function <escape(s, t)> that converts characters like newline and
 * tab into visible escape sequences line \n and \t as it copies the string
 * t to s. Use a <switch>. Write a function for the other directiona s well.
 *
 */

#include<stdio.h>

void escape(int source[], int target[]);
void reverse_escape(int source[], int target[]);

# define MAXLEN 100

int main()
{
    int c;
    int source[MAXLEN], target[MAXLEN], reverse_source[MAXLEN];
    for (int i = 0; i < MAXLEN - 1; i++) {
        source[i] = target[i] = reverse_source[i] = 0;
    }

    for (int i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF; i++) {
        source[i] = c;
    }

    printf("===OUTPUT===\n");

    printf("Source: ");
    for (int i = 0; i < MAXLEN - 1; i++)
        printf("%c", source[i]);
    printf("\n");
    
    escape(source, target);

    printf("Target: ");
    for (int i = 0; i < MAXLEN - 1; i++)
        printf("%c", target[i]);
    printf("\n");

    reverse_escape(target, reverse_source);
    
    printf("R_Source: ");
    for (int i = 0; i < MAXLEN - 1; i++)
        printf("%c", reverse_source[i]);
    printf("\n");

    return 0;
}

void escape(int source[], int target[])
{
    int i, j;
    j = i = 0;

    for (i = 0; i < MAXLEN - 1; i++) {
        switch(source[i]) {
            case '\n':
                target[j] = '\\';
                j++;
                target[j] = 'n';
                j++;
                break;
            case '\t':
                target[j] = '\\';
                j++;
                target[j] = 't';
                j++;
                break;
            default:
                target[j] = source[i];
                j++;
        }
    }
}

void reverse_escape(int source[], int target[])
{
    int i, j;
    j = i = 0;

    for (i = 0; i < MAXLEN - 1; i++) {
        switch (source[i]) {
            case '\\':
                switch (source[i+1]) {
                    case 'n':
                        target[j] = '\n';
                        ++i;
                        ++j;
                        break;
                    case 't':
                        target[j] = '\t';
                        ++i;
                        ++j;
                        break;
                }
                break;
            default:
                target[j] = source[i];
                ++j;
        }
    }
}
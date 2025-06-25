/*
 * Exercise 4.1
 * Write the function <strindex(s, t)> which returns the position of the
 * rightmost occurrence of t in s, or -1 if there is none.
 *
 */

#include <stdio.h>

int strindex(char s[], char t[]);

int main()
{
    char source[] = "Tu vieja en tanga! Ha pasado tanto tiempo culia!";
    char target[] = "tan";

    int position = strindex(source, target);

    if (position == -1)
        printf("%s does not occur in %s\n", target, source);
    else
        printf("%s occurs in %s at position %d\n", target, source, position);
    return 0;
}

// The exercise does not say whether t is a single char or more than 1.
// Assuming both can be the case.
int strindex(char s[], char t[])
{
    printf("strindex called!\n");
    int p, i, k, j;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            p = i;
    }
    return p;
}
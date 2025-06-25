/*
 * Theory - Stack
 * (1 - 2) * (4 + 5)
 * can be entered as:
 * 1 2 - 4 5 + *
 * Read operands
 * When operator comes, "pop" operands
 *
 */

#include <stdio.h>
#include <string.h> // FIXME: because '\0' does not work

int pop(char s[], int p);
void parse(char s[]);
int isoperator(char c);

int main()
{
    char s[] = "1 2 - 4 5 + *";
    //char s[] = "1 2 -";

    for (int i = 0; i < strlen(s); i++) {
        printf("%c", s[i]);
    }
    printf("\n");

    parse(s);

    return 0;
}

int pop(char s[], int p)
{
    int n = (s[p] - '0');
    printf("%c = %d\n", s[p], n);
    return n;
}

void parse(char s[])
{
    // FIXME: this does not parse the "between expressions" operator correctly
    //  - we need to replance the operands and operators in the stack
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            int x, y;
            case '+':
                x = pop(s, i - 4);
                y = pop(s, i - 2);
                printf("%d + %d = %d\n", x, y, x + y);
                break;
            case '-':
                x = pop(s, i - 4);
                y = pop(s, i - 2);
                printf("%d - %d = %d\n", x, y, x - y);
                break;
            case '*':
                x = pop(s, i - 4);
                y = pop(s, i - 2);
                printf("%d * %d = %d\n", x, y, x * y);
                break;
            case '/':
                x = pop(s, i - 4);
                y = pop(s, i - 2);
                printf("%d / %d = %d\n", x, y, x / y);
                break;
        }
    }
}

int isoperator(char c)
{
    printf("Is %c an operator?\n", c);
    char operators[] = "+-*/";
    for (int i = 0; i < strlen(operators); i++)
        if (c == operators[i]) {
            printf("Operator Found: %c\n", c);
            return 1;
        }
    return 0;
}
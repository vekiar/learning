/*
 * Since we cannot wrap our head around the stack concept, we are going to
 * implement the calculator from scratch, with no guidance from the book. All
 * of the requirements in Exercises 4.{3-10} will be added in here.
 * 
 * Look at:
 * 070-PLAN.md for more high level implementation information
 * 070-SPEC.md for a detailed specification of files and components
 *
 */

#include <stdio.h>

#define MAXLINE 1000
#define MAXSTACK 100

int getlines(char line[], int limit);
int pop(int stack[]);
void push(int n, int stack[]);
void parse(char line[], int stack[]);
int isoperator(char c);
int run_operation(char operator, int stack[]);
int atoi(char c);
void print_stack(int stack[]);

int stack[MAXSTACK];
int stack_index = 0;
char line[MAXLINE];
int memory = 0;
int most_recently_printed = 0;

int main()
{
    while ((getlines(line, MAXLINE) > 0)) { // this will never escape because we are inserting '\0' into the array
        parse(line, stack);
        // return result from line (if any)
        ;
    }

    return 0;
}

void parse(char line[], int stack[])
{
    int i, r, sign = 1;
    char operator;
    for (i = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ') {
            ;
        } else if (line[i] == '-') {
            if (!(line[i + 1] == ' ' || line[i + 1] == '\0')) // its a negative sign
                sign = -1;
            else { // its an operator #FIXME: this is ugly and duplicated
                operator = line[i];
                r = run_operation(operator, stack);
                printf("%d\n", r);
            }
        } else if (isoperator(operator = line[i])) {
            //print_stack(stack);
            r = run_operation(operator, stack);
            printf("%d\n", r);
        } else {
            //printf("Sign: %d, Value: %d, Put: %d\n", sign, atoi(line[i]), sign * atoi(line[i]));
            push(sign * atoi(line[i]), stack);
            //print_stack(stack);
            sign = 1;
        }
    }
}

int isoperator(char c) // FIXME: this is broken, we have operators in two places (it is broken because we are not using ctypes.h)
{
    switch (c) {
        case '+': case '-': case '*': case '/': case '%': case 't': case 'p': case 's': case 'c': case 'm': case 'v':
            return 1;
    }
    return 0;
}

int run_operation(char operator, int stack[])
{
    // FIXME: check whether the operator supports the number of operands
    int r, op2;
    switch (operator) {
        case '+':
            r = pop(stack) + pop(stack);
            break;
        case '*':
            r = pop(stack) * pop(stack);
            break;
        case '-':
            op2 = pop(stack);
            r = pop(stack) - op2;
            break;
        case '/':
            op2 = pop(stack);
            r = pop(stack) / op2;
            break;
        case '%':
            op2 = pop(stack);
            r = pop(stack) % op2;
            break;
        case 'p':
            print_stack(stack);
            r = 0;
            break;
        case 't':
            if (stack_index > 0)
                r = stack[stack_index - 1];
            else {
                printf("ERROR: stack is empty.\n");
                r = 0;
            }
            break;
        case 'd':
            if (stack_index > 0) {
                int n = stack[stack_index - 1];
                push(n, stack);
                printf("%d duplicated in the stack\n", n);
            } else {
                printf("ERROR: stack is empty\n");
            }
            break;
        case 's':
            int s = stack[stack_index - 1];
            stack[stack_index - 1] = stack[stack_index - 2];
            stack[stack_index - 2] = s;
            r = 0;
            break;
        case 'c':
            stack[0] = '\0';
            r = 0;
            break;
        case 'm': // FIXME: we should be able to add support for multiple variables
            if (memory == 0) { // FIXME: what happens if we want to store 0?
                memory = pop(stack);
                r = memory;
            } else {
                printf("Memory: %d\n", memory);
                r = memory;
                memory = 0;
            }
            break;
        case 'v':
            r = most_recently_printed;
            break;
    }
    most_recently_printed = r;
    return r;
}

int atoi(char s)
{
    int r = s - '0';
    return r;
}

int getlines(char line[], int limit)
{
    int i, c;
    for (i = 0; (c = getchar()) != EOF && i < limit - 1 && c != '\n'; i++) {
    // printf("%d:\t%c\n", i, c);
        line[i] = c;
    }
    // printf("%d:\t%c\n", i, 'A');
    line[i++] = '\0';

    return i;
}

int pop(int stack[])
{
    int i = stack[stack_index - 1];
    --stack_index;
    return i;
}

void push(int n, int stack[])
{
    stack[stack_index++] = n;
}

void print_stack(int stack[])
{
    for (int i = 0; stack[i] != '\0'; i++)
        printf("%d ", stack[i]);
    printf("\n");
}
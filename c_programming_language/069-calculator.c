#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                //printf("Pushed %f\n", atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("ERROR: Division by zero\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: Unknown Command %s\n", s);
                break;
        }
    }
    return 0;
}

void push(double f)
{
    if (sp < MAXVAL) {
    //    printf("sp: %d, maxval: %d\n", sp, MAXVAL);
        val[sp++] = f;
    //    printf("sp: %d, maxval: %d\n", sp, MAXVAL);
    }
    else
        printf("ERROR: Stack full, cannot push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("ERROR: Stack Empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c; // not a number
    i = 0;
    if (isdigit(c)) // collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ERROR: ungetch, too many characters\n");
    else
        buf[bufp++] = c;
}
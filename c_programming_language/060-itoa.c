#include <stdio.h>

void print_string(char s[]);
void itoa(int n, char s[]);
int string_length(char s[]);
void reverse_string(char s[], int n);

int main()
{
    int n[] = {212, 420, 527, 737, 674, 438, 957, 328, 409, 284, 591, 424, 684, 786, 950, 533, 816, 914, 101, 423, 639, 143, 910, 43, 456, 88, 586, 624, 916, 553, 414, 471, 381, 802, 207, 84, 333, 452, 547, 336, 305, 892, 409, 553, 50, 765, 876, 807, 124, 27};

    for (int i = 0; i < 50; i++) {
        if (n[i] < 0) {
            printf("ERROR: This function does not support negative numbers.\n");
        } else if (n[i] > 999) {
            printf("ERROR: n cannot be greater than 3 digits.\n");
            return 1;
        } else {
            char s[4];
                printf("Number: %d is String: '", n[i]);
                itoa(n[i], s);
                print_string(s);
                printf("'\n");
        }
    }

    return 0;
}

void itoa(int n, char s[])
{
    int i = 0;
    do {
//        printf("%d %d\n", n, n % 10);
        s[i] = n % 10 + '0';
        i++;
    } while ((n /= 10) > 0);
    s[i] = '\0';
    reverse_string(s, string_length(s));
}

void print_string(char s[])
{
    int i = 0;
    while (s[i] != '\0') {
        printf("%c", s[i]);
        i++;
    }
}

int string_length(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    i++;
    return i;
}

void reverse_string(char s[], int n)
{
    char x[n];

    x[n-1] = '\0';
    for (int i = 0; i < n - 1; i++) {
//        printf("%d %d %c\n", i, n-2-i, s[n-2-i]);
        x[i] = s[n-2-i];
    }

//    print_string(x);
//    printf("\n");

    for (int i = 0; i <= n - 1; i++) {
        s[i] = x[i];
    }
}
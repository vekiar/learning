#include <stdio.h>
#include <stdbool.h>

#define CHARSET 26
#define OFFSET_UPPER 65
#define OFFSET_LOWER 97

bool is_bigger(int a, int b)
{
    return a > b;
}

int main()
{
    int c;
    int c_lower[CHARSET];
    int c_upper[CHARSET];

    for (int i = 0; i < CHARSET; i++) {
        c_lower[i] = 0;
        c_upper[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        int cc = (int) c;
        if (cc >= OFFSET_UPPER && cc <= (OFFSET_UPPER + CHARSET))
            c_upper[cc - OFFSET_UPPER] += 1;
        if (cc >= OFFSET_LOWER && cc <= (OFFSET_LOWER + CHARSET))
            c_lower[cc - OFFSET_LOWER] += 1;
    }

    int max_count = 0;
    for (int i = 0; i < CHARSET; i++) {
        if (c_lower[i] > max_count)
            max_count = c_lower[i];
        if (c_upper[i] > max_count)
            max_count = c_upper[i];
    }

    for (int i = max_count; i >= 0; i--) {
        for (int j = 0; j < CHARSET; j++) {
            if (is_bigger(c_lower[j], i))
                printf(" + ");
            else
                printf("   ");
            //printf(" %d ", is_bigger(c_lower[j], i));
        }
        printf("\n");
                
    }

    for (int j = 0; j < CHARSET; j++) {
        printf("---");
    }

    printf("\n");

    for (int j = 0; j < CHARSET; j++) {
        printf(" %c ", (char) (OFFSET_LOWER + j));
    }
    printf("\n");
/*
    printf("\n");

    for (int j = 0; j < CHARSET; j++) {
        printf("%c: %d, ", (char) OFFSET_LOWER + j, c_lower[j]);
    }

    printf("\n");
    printf("\n");

    printf("max_count: %d\n", max_count);
*/

    return 0;
}
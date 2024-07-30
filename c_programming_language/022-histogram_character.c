#include <stdio.h>

#define CHARSET 26
#define OFFSET_UPPER 65
#define OFFSET_LOWER 97

int main()
{
    int c_lower[CHARSET];
    int c_upper[CHARSET];
    int i, c;

    for (i = 0; i < CHARSET; i++) {
        c_lower[i] = 0;
        c_upper[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        int cc = (int) c;
        if (cc >= OFFSET_UPPER && cc <= (OFFSET_UPPER + 26))
            c_upper[cc - OFFSET_UPPER] += 1;
        if (cc >= OFFSET_LOWER && cc <= (OFFSET_LOWER + 26))
            c_lower[cc - OFFSET_LOWER] +=1;
    }

    for (i = 0; i < CHARSET; i++) {
        printf("%c: ", (char) (OFFSET_UPPER + i));
        for (int j = 0; j < c_upper[i]; j++)
            printf("|");
        printf("\n");
    }

    for (i = 0; i < CHARSET; i++) {
        printf("%c: ", (char) (OFFSET_LOWER + i));
        for (int j = 0; j < c_lower[i]; j++)
            printf("|");
        printf("\n");
    }

    return 0;
}
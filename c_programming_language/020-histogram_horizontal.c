#include <stdio.h>

int main()
{
    int WORD_LENGTHS = 50;
    int words[WORD_LENGTHS];
    int i, c;
    int cc = 0;

    for (i = 0; i < WORD_LENGTHS; i++) {
        words[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (cc > 0)
                words[cc] += 1;
            cc = 0;
        }
        else {
            cc += 1;
        }
    }

    for (i = 0; i < WORD_LENGTHS; i++) {
            if (words[i] > 0) {
            printf("%d:\t", i);
            for (int j = 0; j < words[i]; j++)
                printf("|");
            printf("\n");
        }
    }
    return 0;
}
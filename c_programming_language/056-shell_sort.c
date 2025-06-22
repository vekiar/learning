#include <stdio.h>

void shellsort(int v[], int n);

int main()
{
    int a[] = {91, 77, 44, 56, 2, 94, 9, 26, 1, 41, 47, 16, 11, 4, 78, 10, 60, 19, 46, 56, 34, 30, 89, 33, 39, 50, 26, 21, 13, 23, 3, 12, 76, 88, 41, 55, 62, 57, 84, 46, 92, 46, 17, 17, 37, 95, 11, 58, 75, 72, 43, 18, 10, 29, 55, 63, 72, 79, 30, 50, 55, 62, 67, 24, 92, 54, 49, 76, 1, 78, 56, 26, 65, 66, 9, 1, 59, 49, 78, 100, 100, 41, 83, 83, 99, 21, 36, 19, 46, 26, 28, 35, 5, 74, 96, 55, 82, 26, 28, 13};
    printf("Original: ");
    for (int i = 0; i < 99; i++)
        printf("%d ", a[i]);
    printf("\nSorted: ");
    shellsort(a, 100);
    for (int i = 0; i < 99; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}

void shellsort(int v[], int n)
{
    int gap, i, j, tmp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
                tmp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = tmp;
        }
}
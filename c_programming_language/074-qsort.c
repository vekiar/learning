#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);
void print_array(int n[], int s);

int main()
{
    int a[30] = {76, 18, 31, 34, 58, 26, 61, 49, 17, 96, 33, 26, 41, 30, 56, 12, 40, 59, 83, 57, 90, 92, 20, 58, 30, 61, 87, 73, 43, 79};
    print_array(a, 30);
    qsort(a, 0, 29);
    print_array(a, 30);
    return 0;
}

void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void print_array(int n[], int s)
{
    for (int i = 0; i < s; i++)
        printf("%d ", n[i]);
    printf("\n");
}
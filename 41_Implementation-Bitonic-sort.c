/* This program works only when the size of input is in the power of 2. */
#include <stdio.h>
/*In this function the parameter 'd' represents the sorting direction*/
void exchange(int a[], int i, int j, int d)
{
    int temp;
    if (d == (a[i] > a[j]))
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
void merge(int a[], int beg, int c, int d)
{
    int k, i;
    if (c > 1)
    {
        k = c / 2;
        for (i = beg; i < beg + k; i++)
            exchange(a, i, i + k, d);
        merge(a, beg, k, d);
        merge(a, beg + k, k, d);
    }
}
void bitonicSort(int a[], int beg, int c, int d)
{
    int k;
    if (c > 1)
    {
        k = c / 2;
        bitonicSort(a, beg, k, 1);     // sort in ascending order
        bitonicSort(a, beg + k, k, 0); // sort in descending order
        merge(a, beg, c, d);           // merge the sequence in ascending order
    }
}

/* function to call the bitonicSort() function to sort the given array in ascending order */
void sort(int a[], int n, int order)
{
    bitonicSort(a, 0, n, order);
}
void print(int a[], int n) // function to print array elements
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int a[] = {30, 70, 40, 80, 60, 20, 10, 50};
    int n = sizeof(a) / sizeof(a[0]);
    int order = 1; // It means sorting in increasing order
    printf("Before sorting array elements are - \n");
    print(a, n);
    sort(a, n, order);
    printf("\nAfter sorting array elements are - \n");
    print(a, n);
    return 0;
}
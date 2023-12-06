// Title – Write a program to perform merge sort.
#include <stdio.h>
#include <conio.h>
#define max 10
int a[11] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0};
int b[11]; // Size of 'b' should be same as 'a'
void merging(int low, int mid, int high)
{
    int m1, m2, i;
    for (m1 = low, m2 = mid + 1, i = low; m1 <= mid && m2 <= high; i++)
    {
        if (a[m1] <= a[m2])
            b[i] = a[m1++];
        else
            b[i] = a[m2++];
    }
    while (m1 <= mid)
        b[i++] = a[m1++];
    while (m2 <= high)
        b[i++] = a[m2++];
    for (i = low; i <= high; i++)
        a[i] = b[i];
}
void sort(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        sort(low, mid);
        sort(mid + 1, high);
        merging(low, mid, high);
    }
    else
    {
        return;
    }
}
int main()
{
    int i;
    printf("List Before Sorting\n");
    for (i = 0; i <= max; i++)
        printf("%d ", a[i]); // Fixed the print format specifier and added space
    sort(0, max);
    printf("\n\nList After Sorting\n");
    for (i = 0; i <= max; i++)
        printf("%d ", a[i]); // Fixed the print format specifier and added space
    getch();
    return 0;
}

/*
Output List Before Sorting
10 14 19 26 27 31 33 35 42 44 0
List After Sorting
0 10 14 19 26 27 31 33 35 42 44
*/

// Title – Write a program to demonstrate the bubble sort algorithm.
#include <stdio.h>
#include <conio.h>
int main()
{
    int arr[100], n, c, d, swap;
    printf("Enter the number of elements =\n");
    scanf("%d", &n);
    printf("Enter %d integers =\n", n);
    for (c = 0; c < n; c++)
    {
        scanf("%d", &arr[c]);
    }
    for (c = 0; c < n - 1; c++)
    {
        for (d = 0; d < n - c - 1; d++)
        {
            if (arr[d] > arr[d + 1])
            {
                swap = arr[d];
                arr[d] = arr[d + 1];
                arr[d + 1] = swap;
            }
        }
    }
    printf("Sorted list in ascending order:\n");
    for (c = 0; c < n; c++)
    {
        printf("%d\n", arr[c]);
    }
    getch();
    return 0;
}
// Output Enter the number of elements =
//     5 Enter 5 integers =

//         59 23 1 6 32 Sorted list in ascending order : 1 6 23 32 59 * /

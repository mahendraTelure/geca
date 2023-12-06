// Title – Write a program to perform heap sort.
#include <stdio.h>
#include <conio.h>
int main()
{
    int heap[10], n, i, j, c, root, temp;
    printf("Enter the number of elements = ");
    scanf("%d", &n);
    printf("\nEnter the numbers = ");
    for (i = 0; i < n; i++)
        scanf("%d", &heap[i]);
    for (i = 1; i < n; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;
            if (heap[root] < heap[c])
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
    printf("Heap array = \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", heap[i]);
    }
    for (j = n - 1; j >= 0; j--)
    {
        temp = heap[0];
        heap[0] = heap[j];
        heap[j] = temp;
        root = 0;
        do
        {
            c = 2 * root + 1;
            if ((heap[c] < heap[c + 1]) && c < j - 1)
                c++;

            if (heap[root] < heap[c] && c < j)
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < j);

        printf("\n\nThe sorted array is = \n");
        for (i = 0; i < n; i++)
            printf("%d\n", heap[i]);
        printf("\n\nComplexity : Best case = Avg case = Worst case = 0(n log n )\n");
        getch();
        return 0;
    }

}
    /*
    Output Enter the number of elements = 7
    Enter the numbers = 78
    45
    67
    3
    98
    5
    34
    Heap array =
    98
    78
    67
    3
    45
    5
    34
    The sorted array is =
    3
    5
    34
    45
    67
    78
    98

    Complexity : Best case = Avg case = Worst case = 0(n log n )
    */

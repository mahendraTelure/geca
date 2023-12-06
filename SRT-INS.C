// Title – Write a program for Insertion Sort.
#include <stdio.h>
int main()
{
  int n, array[1000], c, d, t, flag = 0;
  printf("Enter number of elements\n");
  scanf("%d", &n);
  printf("Enter %d integers\n", n);
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);
  for (c = 1; c <= n - 1; c++)
  {
    t = array[c];
    for (d = c - 1; d >= 0; d--)
    {
      if (array[d] > t)
      {
        array[d + 1] = array[d];
        flag = 1;
      }
      else
        break;
    }
    if (flag)
      array[d + 1] = t;
  }
  printf("Sorted list in ascending order:\n");
  for (c = 0; c <= n - 1; c++)
  {
    printf("%d\n", array[c]);
  }
  return 0;
}

/*
OUTPUT:
Enter number of elements 5
Enter 5 integers
11 14 12 15 12
Sorted list in ascending order:
11
12
12
14
15

Process returned 0 (0x0)	execution time : 9.063 s Press any key to continue.
*/

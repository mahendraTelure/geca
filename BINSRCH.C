// Title – Write a program for Binary Search to search an element in the given sequence.
#include <stdio.h> 
int main()
{
  int c, first, last, middle, n, search, array[100]; printf("Enter number of elements\n");
  scanf("%d", &n);
  printf("Enter %d integers\n", n); for(c=0;c<n;c++)
  scanf("%d", &array[c]); printf("Enter value to find\n"); scanf("%d", &search);
  first=0; last=n-1;
  middle=(first+last)/2; while(first<=last)
  {
   if(array[middle]<search) first=middle+1;
   else if(array[middle]==search)
   {
    printf("%d found at location %d.\n", search, middle+1); break;
   }
   else
   last=middle-1; middle=(first+last)/2;
  }
 if(first>last)
 printf("Not found! %d isn't present in the list.\n", search); return 0;
}

/*
OUTPUT:
Enter number of elements 5
Enter 5 integers
11
12
13
14
15
Enter value to find 14
14 found at location 4.

Process returned 0 (0x0)	execution time : 8.998 s Press any key to continue.
*/


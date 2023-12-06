// Title – Write a program to perform a singly linked list
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node
{
    int e;
    Position next;
};
void Insert(int x, List l, Position p)
{
    Position TmpCell;
    TmpCell = (struct Node *)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        printf("Memory out of space\n");
    else
    {
        TmpCell->e = x;
        TmpCell->next = p->next;
        p->next = TmpCell;
    }
}
int isLast(Position p)
{
    return (p->next == NULL);
}
Position FindPrevious(int x, List l)
{
    Position p = l;
    while (p->next != NULL && p->next->e != x)
        p = p->next;
    return p;
}
void Delete(int x, List l)
{

    Position p, TmpCell;
    p = FindPrevious(x, l);
    if (!isLast(p))
    {
        TmpCell = p->next;
        p->next = TmpCell->next;
        free(TmpCell);
    }
    else
        printf("Element does not exist!!!!\n");
}
void Display(List l)
{
    printf("The List Elements Are :: ");
    Position p = l->next;
    while (p != NULL)
    {
        printf("%d -> ", p->e);
        p = p->next;
    }
}
void Merge(List l, List l1)
{
    int i, n, x, j;
    Position p;
    printf("Enter The Number Of Elements To Be Merged :: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        p = l1;
        scanf("%d", &x);
        for (j = 1; j <= n; j++)
            p = p->next;
        Insert(x, l1, p);
    }
    printf("The New List :: ");
    Display(l1);
    printf("The Merged List ::");
    p = l;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = l1->next;
    Display(l);
}
int main()

{
    int x, pos, ch, i;
    List l, l1;
    l = (struct Node *)malloc(sizeof(struct Node));
    List p = l;
    printf("LINKED LIST IMPLEMENTATION OF LIST ADT.");
    do
    {
        printf("\n INSERT\t 2. DELETE\t 3. MERGE\t 4. PRINT\t 5.QUIT\n Enter The Choice ::");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            p = l;
            printf("Enter The Element To Be Inserted ::");
            scanf("%d", &x);
            printf("Enter The Position Of The Element ::");
            scanf("%d", &pos);
            for (i = 1; i < pos; i++)
            {
                p = p->next;
            }
            Insert(x, l, p);
            break;
        case 2:
            p = l;
            printf("Enter The Element To Be Deleted ::");
            scanf("%d", &x);
            Delete(x, p);
            break;
        case 3:
            l1 = (struct Node *)malloc(sizeof(struct Node));
            l1->next = NULL;
            Merge(l, l1);
            break;
        case 4:
            Display(l);
            break;
        }
    } while (ch < 5);
    getch();
    return 0;
}

/*
Output -

LINKED LIST IMPLEMENTATION OF LIST ADT.
1. INSERT
2. DELETE
3. MERGE
Enter The Choice :: 1
Enter The Element To Be Inserted :: 11
Enter The Position Of The Element :: 1

4. PRINT

5. QUIT

1. INSERT
2. DELETE
3. MERGE
Enter The Choice :: 1
Enter The Element To Be Inserted :: 12
Enter The Position Of The Element :: 2

4. PRINT

5. QUIT

1. INSERT
2. DELETE
3. MERGE
Enter The Choice :: 1
Enter The Element To Be Inserted :: 13
Enter The Position Of The Element :: 2

4. PRINT

5. QUIT

1. INSERT
2. DELETE
3. MERGE
Enter The Choice :: 1
Enter The Element To Be Inserted :: 14
Enter The Position Of The Element :: 3

4. PRINT

5. QUIT

1. INSERT
2. DELETE
3. MERGE
Enter The Choice :: 1
Enter The Element To Be Inserted :: 15
Enter The Position Of The Element :: 4

4. PRINT

5. QUIT

1. INSERT
2. DELETE
3. MERGE
4. PRINT
Enter The Choice :: 4
The List Elements Are :: 15 -> 14 -> 13 -> 12 -> 11 -> NULL

5. QUIT

1. INSERT
2. DELETE
Enter The Choice :: 5

5. QUIT

3. MERGE

4. PRINT
*/

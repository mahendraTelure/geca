// Title – To implement stack & operations on stack.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define maxsize 10
struct stack
{
    int top;
    int item[maxsize];
};
void push(struct stack *ps, int x);
int pop(struct stack *ps);
void showstack(struct stack *ps);
void main()
{
    int choice, ele;
    struct stack s;
    s.top = -1;
    printf("Available choices are: \n Choice1:PUSH \nChoice2:POP \n Choice3:Display stack \n Choice4:Exit\n");
    while (choice != 4)
    {
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("\n Enter the element to be inserted:");
            scanf("%d", &ele);
            push(&s, ele);
        }
        if (choice == 2)
        {
            int item = pop(&s);
            printf("\n The deleted item is: %d\n", item);
        }
        if (choice == 3)
        {
            showstack(&s);
        }
        if (choice == 4)

        {
            exit(0);
        }
    }
    getch();
}
void push(struct stack *ps, int x)
{
    ps->top++;
    ps->item[ps->top] = x;
}
int pop(struct stack *ps)
{
    int y;
    y = ps->item[ps->top];
    ps->top--;
    return y;
}
void showstack(struct stack *ps)
{
    int i;
    if (ps->top == -1)
    {
        printf("Stack is empty...");
    }
    else
    {
        printf("Elements of stack:-\n");
        for (i = ps->top; i >= 0; i--)
        {
            printf("%d\n", ps->item[i]);
        }
    }
}

/*
Output Available choices are:
Choice1:PUSH
Choice2:POP
Choice3:Display stack
Choice4:Exit
Enter your choice:1
Enter the element to be inserted:5
Enter your choice:1
Enter the element to be inserted:7
Enter your choice:1
Enter the element to be inserted:9
Enter your choice:3
Elements of stack:9
7

5
Enter your choice:2
The deleted item is: 9
Enter your choice:3
Elements of stack:7
5
Enter your choice:4
Process returned 0 (0x0)
execution time: 34.187 s
Press any key to continue.
*/

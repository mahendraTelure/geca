// Title – Write a program for evaluation of postfix expression using stack.
#include <stdio.h>
#include <ctype.h>
#include <math.h>
struct stack
{
    int top;
    int operand[20];
};
void push(struct stack *, int);
void pop(struct stack *);
int main()
{
    struct stack s;
    char strl[40];
    int i = 0, result, op1, op2;
    s.top = -1;
    printf("Enter an expression in Postfix form: \n");
    while ((strl[i] = getchar()) != '\n')
    {
        if (isdigit(strl[i]))
        {
            push(&s, strl[i] - '0');
        }
        else
        {
            op2 = s.operand[s.top];
            pop(&s);
            op1 = s.operand[s.top];
            pop(&s);
            switch (strl[i])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;

            case '/':
                result = op1 / op2;
                break;
            }
            printf("Intermediate Result : %d \n", result);
            push(&s, result);
        }
        i++;
    }
    printf("The value of expression : %d\n", result);
    return 0;
}
void push(struct stack *ps, int n)
{
    ps->top++;
    ps->operand[ps->top] = n;
}
void pop(struct stack *ps)
{
    ps->top--;
}
// Output Enter an expression in Postfix form : 35 + 42 - *Intermediate Result : 8 Intermediate Result : 2 Intermediate Result : 16 The value of expression : 16

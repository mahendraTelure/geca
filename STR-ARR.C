// Title – Write a program for an array of structures.
#include <stdio.h>
#include <conio.h>
struct invent
{
    char name[10];
    int number;
    int price;
};
int main()
{
    struct invent product[3];
    struct invent *p;
    int i = 1;
    p = product;
    printf("Enter the product name, number, and price:\n");
    for (p = product; p < product + 3; p++)
    {
        printf("Product %d:\n", i);
        scanf("%s %d %d", p->name, &p->number, &p->price);
        i++;
    }
    printf("\nProducts entered:\n");
    printf("Name\tNumber\tPrice\n");
    for (p = product; p < product + 3; p++)
    {
        printf("%s\t%d\t%d\n", p->name, p->number, p->price);
    }
    getch();
    return 0;
}

/*
Output Enter the product name, number, and price:

Product 1:
Fan
2
1000
Product 2:
LED
3
5000
Product 3:
PC
6
29999
Products entered:
Name
Number Price
Fan
2
1000
LED
3
5000
PC
6
29999
*/

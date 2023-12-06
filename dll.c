#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct DoublyLinkedList
{
    struct Node *head;
};

void insertAtBeginning(struct DoublyLinkedList *list, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = list->head;

    if (list->head != NULL)
    {
        list->head->prev = newNode;
    }

    list->head = newNode;
}

void insertAtEnd(struct DoublyLinkedList *list, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        newNode->prev = NULL;
        list->head = newNode;
        return;
    }

    struct Node *current = list->head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void deleteNode(struct DoublyLinkedList *list, int data)
{
    struct Node *current = list->head;

    while (current != NULL)
    {
        if (current->data == data)
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                list->head = current->next;
            }

            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }

            free(current);
            return;
        }

        current = current->next;
    }
}

void display(struct DoublyLinkedList *list)
{
    struct Node *current = list->head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    struct DoublyLinkedList dll;
    dll.head = NULL;

    clrscr();

    insertAtBeginning(&dll, 1);
    insertAtBeginning(&dll, 2);
    insertAtEnd(&dll, 3);
    insertAtEnd(&dll, 4);

    display(&dll);

    deleteNode(&dll, 2);
    display(&dll);

    deleteNode(&dll, 4);
    display(&dll);

    getch();
    return 0;
}

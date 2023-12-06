#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <alloc.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
    }
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node *current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

void deleteNode(struct Node **head, int data) {
    if (*head == NULL) {
        printf("Circular linked list is empty. Cannot delete.\n");
        return;
    }

    struct Node *current = *head;
    struct Node *prev = NULL;

    while (current->data != data) {
        if (current->next == *head) {
            printf("Node with data %d not found.\n", data);
            return;
        }
        prev = current;
        current = current->next;
    }

    if (current->next == *head) {
        *head = NULL;
    } else {
        if (current == *head) {
            *head = current->next;
        }
        prev->next = current->next;
    }

    free(current);
}

int main() {
    struct Node *head = NULL;

    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    printf("Circular linked list after insertion: ");
    display(head);

    deleteNode(&head, 2);

    printf("Circular linked list after deletion: ");
    display(head);

    getch();
    return 0;
}

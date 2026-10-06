#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void insertBeginning() {
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("%d inserted at beginning.\n", value);
    display();
}

void insertEnd() {
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("%d inserted at end.\n", value);
    display();
}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("%d deleted from beginning.\n", head->data);

    head = head->next;
    free(temp);

    display();
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("%d deleted from end.\n", head->data);
        free(head);
        head = NULL;
        display();
        return;
    }

    struct Node *temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    printf("%d deleted from end.\n", temp->next->data);

    free(temp->next);
    temp->next = NULL;

    display();
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
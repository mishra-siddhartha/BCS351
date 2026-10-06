#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Circular List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

void insertAtBeginning() {
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node *temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    printf("%d inserted at beginning.\n", value);
    display();
}

void insertAtEnd() {
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node *temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    printf("%d inserted at end.\n", value);
    display();
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        printf("%d deleted from beginning.\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        struct Node *last = head;

        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;

        printf("%d deleted from beginning.\n", temp->data);
        free(temp);
    }

    display();
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        printf("%d deleted from end.\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;

        while (temp->next->next != head) {
            temp = temp->next;
        }

        printf("%d deleted from end.\n", temp->next->data);

        free(temp->next);
        temp->next = head;
    }

    display();
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
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
                insertAtBeginning();
                break;

            case 2:
                insertAtEnd();
                break;

            case 3:
                deleteFromBeginning();
                break;

            case 4:
                deleteFromEnd();
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
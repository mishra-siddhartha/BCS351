#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void display() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");

    temp = top;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void push() {
    int value;

    printf("Enter value to push: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed to stack.\n", value);
    display();
}

void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }

    temp = top;

    printf("%d popped from stack.\n", top->data);

    top = top->next;

    free(temp);

    display();
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element: %d\n", top->data);
    display();
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
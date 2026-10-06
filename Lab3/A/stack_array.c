#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void display() {
    int i;

    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");

    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

void push() {
    int value;

    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }

    printf("Enter value to push: ");
    scanf("%d", &value);

    stack[++top] = value;

    printf("%d pushed to stack.\n", value);
    display();
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }

    printf("%d popped from stack.\n", stack[top]);
    top--;

    display();
}

void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
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
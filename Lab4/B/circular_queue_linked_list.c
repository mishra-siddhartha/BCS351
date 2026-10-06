#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

void enqueue() {
    int value;

    if (front == (rear + 1) % MAX) {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;

    printf("%d inserted into queue.\n", value);
    display();
}

void dequeue() {
    int value;

    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }

    value = queue[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    printf("%d deleted from queue.\n", value);
    display();
}

void peek() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element: %d\n", queue[front]);
    display();
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
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
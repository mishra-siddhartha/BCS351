#include <stdio.h>
#include <stdlib.h>

// Structure for each node
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    return newNode;
}

// Function to insert an element into the priority queue
void enqueue(struct Node** head, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    // Insert at beginning if queue is empty
    // or new node has higher priority
    if (*head == NULL || priority < (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        struct Node* current = *head;

        while (current->next != NULL &&
               current->next->priority <= priority) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to remove highest priority element
int dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Priority queue is empty.\n");
        exit(1);
    }

    struct Node* temp = *head;
    int data = temp->data;

    *head = (*head)->next;

    free(temp);

    return data;
}

// Function to check if queue is empty
int isEmpty(struct Node* head) {
    return head == NULL;
}

// Function to display priority queue
void display(struct Node* head) {
    if (head == NULL) {
        printf("Priority queue is empty.\n");
        return;
    }

    printf("Priority queue elements:\n");

    while (head != NULL) {
        printf("Data: %d, Priority: %d\n",
               head->data, head->priority);

        head = head->next;
    }

    printf("\n");
}

int main() {
    struct Node* pq = NULL;
    int choice, data, priority;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter data and priority to enqueue: ");
                scanf("%d %d", &data, &priority);

                enqueue(&pq, data, priority);
                display(pq);
                break;

            case 2:
                if (!isEmpty(pq)) {
                    printf("Dequeued element: %d\n",
                           dequeue(&pq));
                    display(pq);
                }
                else {
                    printf("Priority queue is empty.\n");
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
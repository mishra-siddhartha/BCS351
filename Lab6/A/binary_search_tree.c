#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node* createNode(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *node, int value) {
    if (node == NULL) {
        return createNode(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    }
    else if (value > node->data) {
        node->right = insert(node->right, value);
    }
    else {
        printf("Duplicate value not allowed.\n");
    }

    return node;
}

struct Node* search(struct Node *node, int value) {
    if (node == NULL || node->data == value) {
        return node;
    }

    if (value < node->data) {
        return search(node->left, value);
    }

    return search(node->right, value);
}

void inorder(struct Node *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void display() {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    printf("BST (Inorder): ");
    inorder(root);
    printf("\n");
}

int main() {
    int choice;
    int value;
    struct Node *result;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                root = insert(root, value);

                printf("After insertion:\n");
                display();
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);

                result = search(root, value);

                if (result != NULL)
                    printf("%d found in BST.\n", value);
                else
                    printf("%d not found in BST.\n", value);

                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
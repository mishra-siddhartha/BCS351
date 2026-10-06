#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* buildTree() {
    int data;

    printf("Enter data (or -1 for empty node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node *root = createNode(data);

    printf("Enter left child of %d:\n", data);
    root->left = buildTree();

    printf("Enter right child of %d:\n", data);
    root->right = buildTree();

    return root;
}

void preOrder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct Node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node *root = NULL;

    printf("Enter the elements of the binary tree:\n");

    root = buildTree();

    printf("\nBinary Tree Traversals:\n");

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}
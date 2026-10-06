#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

void insertTerm(struct Node **head, int coefficient, int exponent) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;

    if (*head == NULL || (*head)->exponent < exponent) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL && temp->next->exponent > exponent) {
        temp = temp->next;
    }

    if (temp->exponent == exponent) {
        temp->coefficient += coefficient;
        free(newNode);
    } else if (temp->next != NULL && temp->next->exponent == exponent) {
        temp->next->coefficient += coefficient;
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

struct Node *addPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;

    while (poly1 != NULL && poly2 != NULL) {

        if (poly1->exponent == poly2->exponent) {
            int sum = poly1->coefficient + poly2->coefficient;

            if (sum != 0) {
                insertTerm(&result, sum, poly1->exponent);
            }

            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        }
        else {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%dx^%d", temp->coefficient, temp->exponent);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    printf("\n");
}

void freeList(struct Node *head) {
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *result = NULL;

    int terms, coefficient, exponent;
    int i;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &terms);

    printf("Enter coefficient and exponent:\n");

    for (i = 0; i < terms; i++) {
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);
    }

    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &terms);

    printf("Enter coefficient and exponent:\n");

    for (i = 0; i < terms; i++) {
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);
    }

    printf("\nFirst polynomial: ");
    display(poly1);

    printf("Second polynomial: ");
    display(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Result of addition: ");
    display(result);

    freeList(poly1);
    freeList(poly2);
    freeList(result);

    return 0;
}
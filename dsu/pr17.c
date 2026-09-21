#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\n\t--Stack Overflow--");
        printf("\n\tUnable to allocate memory.");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("\n\tElement %d pushed into stack.", value);
}

void pop() {
    struct Node *temp;
    if (top == NULL) {
        printf("\n\t--Stack Underflow--");
        printf("\n\tNo element present to remove.");
        return;
    }
    temp = top;
    printf("\n\tElement %d popped from stack.", temp->data);
    top = top->next;
    free(temp);
}

void display() {
    struct Node *temp;
    if (top == NULL) {
        printf("\n\t--Stack Underflow--");
        printf("\n\tNo element present to display.");
        return;
    }
    printf("\n\t--Stack (Top to Bottom)--");
    temp = top;
    while (temp != NULL) {
        printf("\n\t||  %d  ||", temp->data);
        temp = temp->next;
    }
    printf("\n\t___________");
    printf("\n\t-----------");
}

int main() {
    int c, value;
    while (1) {
        printf("\n\n\t--Enter Operation to perform--");
        printf("\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Exit");
        printf("\n\t: ");
        scanf("%d", &c);
        switch (c) {
        case 1:
            printf("\n\tEnter value to push : ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n\tExiting program...\n");
            exit(0);
        default:
            printf("\n\tInvalid choice! Please select 1-4.");
            break;
        }
    }
    return 0;
}


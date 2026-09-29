#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void insert() {
    int value;
    struct Node *newNode;
    printf("\n\tEnter value to insert : ");
    if (scanf("%d", &value) != 1) {
        printf("\n\tInvalid input.");
        return;}
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\n\t--Queue Overflow--");
        printf("\n\tUnable to allocate memory.");
        return;}
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;}
    printf("\n\tElement %d inserted into queue.", value);
}

void deleteElement() {
    struct Node *temp;
    int value;
    if (front == NULL) {
        printf("\n\t--Queue Underflow--");
        printf("\n\tNo element present to remove.");
        return;}
    temp = front;
    value = temp->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;}
    free(temp);
    printf("\n\tElement %d deleted from queue.", value);
}

void display() {
    struct Node *temp;
    if (front == NULL) {
        printf("\n\t--Queue Underflow--");
        printf("\n\tNo element present to display.");
        return;}
    printf("\n\t--Linear Queue (Front to Rear)--");
    temp = front;
    while (temp != NULL) {
        printf("\n\t||  %d  ||", temp->data);
        temp = temp->next;}
    printf("\n\t___________");
    printf("\n\t-----------");
}

int main() {
    int choice;
    while (1) {
        printf("\n\n\t--Enter Operation to perform--");
        printf("\n\t1. Insert\n\t2. Delete\n\t3. Display\n\t4. Exit");
        printf("\n\t: ");
        if (scanf("%d", &choice) != 1) {
            printf("\n\tInvalid input.");
            break;}
        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            deleteElement();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n\tExiting program...\n");
            while (front != NULL) {
                struct Node *temp = front;
                front = front->next;
                free(temp);}
            rear = NULL;
            return 0;
        default:
            printf("\n\tInvalid choice! Please select 1-4.");
            break;}}
    return 1;
}

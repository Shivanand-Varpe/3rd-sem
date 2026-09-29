#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void insert() {
    int value;
    if (rear == MAX - 1) {
        printf("\n\t--Queue Overflow--");
        printf("\n\tQueue is full. No element can be inserted.");
        return;}
    printf("\n\tEnter value to insert : ");
    if (scanf("%d", &value) != 1) {
        printf("\n\tInvalid input.");
        return;}
    if (front == -1) {
        front = 0;}
    queue[++rear] = value;
    printf("\n\tElement %d inserted into queue.", value);
}

void deleteElement() {
    int value;
    if (front == -1) {
        printf("\n\t--Queue Underflow--");
        printf("\n\tNo element present to remove.");
        return;}
    value = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;}
    printf("\n\tElement %d deleted from queue.", value);
}

void display() {
    int i;
    if (front == -1) {
        printf("\n\t--Queue Underflow--");
        printf("\n\tNo element present to display.");
        return;}
    printf("\n\t--Linear Queue (Front to Rear)--");
    for (i = front; i <= rear; i++) {
        printf("\n\t||  %d  ||", queue[i]);}
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
            return 1;}
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
            exit(0);
        default:
            printf("\n\tInvalid choice! Please select 1-4.");
            break;}}
    return 0;
}
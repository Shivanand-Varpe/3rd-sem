#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    if (newNode == NULL) {
        printf("\n\tMemory allocation failed!");
        return;}
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;}
        temp->next = newNode;}
    printf("\n\tNode with value %d inserted at the end.", value);}

void insertAfter(int target, int value) {
    struct Node *temp = head;
    struct Node *newNode;

    if (head == NULL) {
        printf("\n\tList is empty! Cannot insert.");
        return;}
    while (temp != NULL && temp->data != target) {
        temp = temp->next;}
    if (temp == NULL) {
        printf("\n\tElement %d not found in the list!", target);
        return;}
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\n\tMemory allocation failed!");
        return;}
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    printf("\n\tNode with value %d inserted after %d.", value, target);}

void deleteNode(int value) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head == NULL) {
        printf("\n\tList is empty! Nothing to delete.");
        return;}
    if (head->data == value) {
        head = head->next;
        free(temp);
        printf("\n\tNode with value %d deleted from the list.", value);
        return;}
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;}
    if (temp == NULL) {
        printf("\n\tElement %d not found in the list!", value);
        return;}
    prev->next = temp->next;
    free(temp);
    printf("\n\tNode with value %d deleted from the list.", value);}
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("\n\tList is empty!");
        return;}
    printf("\n\tLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;}
    printf("NULL\n");}

int main() {
    int choice, value, target;

    while (1) {
        printf("\n\n\t-- Singly Linked List Operations --");
        printf("\n\t1. Insert at End");
        printf("\n\t2. Insert After an Element");
        printf("\n\t3. Delete an Element");
        printf("\n\t4. Display");
        printf("\n\t5. Exit");
        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n\tEnter value to insert at end: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 2:
            printf("\n\tEnter target element after which to insert: ");
            scanf("%d", &target);
            printf("\tEnter value to insert: ");
            scanf("%d", &value);
            insertAfter(target, value);
            break;
        case 3:
            printf("\n\tEnter value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\n\tExiting program...\n");
            exit(0);
        default:
            printf("\n\tInvalid choice! Please select 1-5.");
            break;}}
    return 0;}


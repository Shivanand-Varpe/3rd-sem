#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\n\tMemory allocation failed!");
        return;}
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("\n\tNode with value %d inserted at the beginning.", value);}
void search(int key) {
    struct Node *temp = head;
    int pos = 1, found = 0;
    if (head == NULL) {
        printf("\n\tList is empty! Nothing to search.");
        return;}
    while (temp != NULL) {
        if (temp->data == key) {
            printf("\n\tElement %d found at position %d.", key, pos);
            found = 1;
            break;}
        temp = temp->next;
        pos++;}
    if (!found) {
        printf("\n\tElement %d not found in the list.", key);}}
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
    int choice, value;
    while (1) {
        printf("\n\n\t-- Singly Linked List Operations --");
        printf("\n\t1. Insert at Beginning");
        printf("\n\t2. Search");
        printf("\n\t3. Display");
        printf("\n\t4. Exit");
        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\n\tEnter value to insert: ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 2:
            printf("\n\tEnter value to search: ");
            scanf("%d", &value);
            search(value);
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
return 0;}

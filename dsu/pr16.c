#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX],top =-1;
void push(int value) {
    if (top == MAX - 1) {
        printf("\n\t--Stack Overflow--");
    } else {
        top = top + 1;
        stack[top] = value;
        printf("\n\tElement %d pushed into stack at position %d.", value, top + 1);}}
void pop() {
    if (top == -1) {
        printf("\n\t--Stack Underflow--");
        printf("\n\tNo element present to remove");
    } else {
        printf("\n\tElement %d popped from stack at position %d.", stack[top], top + 1);
        top = top - 1;}}
void display() {
    int i;
    if (top == -1) {
        printf("\n\t--Stack Underflow--");
        printf("\n\tNo element present to display");
    } else {
        printf("\n\t--Stack--");
        for (i = top; i >= 0; i--) {
            printf("\n\t||  %d  ||", stack[i]);
        }
        printf("\n\t___________");
        printf("\n\t-----------");}}
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
            push(value); break;
        case 2:
            pop(); break;
        case 3:
            display(); break;
        case 4:
            printf("\n\tExiting program...\n"); exit(0);
        default:
            printf("\n\tInvalid choice! Please select 1-4.");
            break;}}
    return 0;}
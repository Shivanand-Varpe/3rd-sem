#include <stdio.h>
#include <string.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    char arr[n][10];
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);}
    // Selection sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j;}}
        if (minIndex != i) {
            char temp[100];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[minIndex]);
            strcpy(arr[minIndex], temp);}}
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);}
    printf("\n");
    return 0;}

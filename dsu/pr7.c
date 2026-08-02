#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    char arr[n][100];
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);}
    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);}}}
    printf("Sorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);}
    printf("\n");
    return 0;}

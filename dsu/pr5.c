#include <stdio.h>
#include <string.h>

int main() {
    char arr[][20] = {"apple", "banana", "grapes", "mango", "orange", "pineapple", "watermelon"};
    int n = 7, low = 0, high = n - 1, mid;
    char key[20];
    int found = 0;

    printf("Enter the string to search: ");
    scanf("%19s", key);

    while (low <= high) {
        mid = (low + high) / 2;
        int cmp = strcmp(key, arr[mid]);

        if (cmp == 0) {
            found = 1;
            break;
        } else if (cmp < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (found) {
        printf("String found at index %d.\n", mid);
    } else {
        printf("String not found.\n");
    }

    return 0;
}

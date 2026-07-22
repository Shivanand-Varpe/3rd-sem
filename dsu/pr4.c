#include <stdio.h>
int main() {
    int n, i, key, result;
    printf("Enter size of array :");
    scanf("%d",&n);
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i]=i+1+i;}
    printf("Array elements are:  ");
    for (i=0;i<n;i++){
        printf("%d ",arr[i]);}
    printf("\n Enter element to search: ");
    scanf("%d", &key);
    int low = 0, high = n - 1, mid;
    result = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            result = mid;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;}}
    if (result != -1) {
        printf("Element %d found at index %d at position %d.\n", key, result, result + 1);
    } else {
        printf("Element %d not found in the array.\n", key);}
    return 0;}

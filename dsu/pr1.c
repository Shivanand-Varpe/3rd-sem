#include <stdio.h>

int main()
{
    int array[100], size, position, value, i;

    printf("Enter size: ");
    scanf("%d", &size);
    printf("Enter elements: ");
    for (i = 0; i < size; i++)
        scanf("%d", &array[i]);

    printf("Enter insert position and value: ");
    scanf("%d%d", &position, &value);
    for (i = size; i >= position; i--)
        array[i] = array[i - 1];
    array[position - 1] = value;
    size++;

    printf("Enter delete position: ");
    scanf("%d", &position);
    for (i = position - 1; i < size - 1; i++)
        array[i] = array[i + 1];
    size--;

    printf("Array: ");
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);

    return 0;
}

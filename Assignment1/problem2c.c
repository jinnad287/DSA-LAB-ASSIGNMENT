#include <stdio.h>

void deleteElement(int arr[], int *size) {
    int pos = -1, x;

    printf("Enter the element you want to delete: ");
    scanf("%d", &x);

    for (int i = 0; i < *size; i++) {
        if (arr[i] == x) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("Value %d not found in array.\n", x);
        return;
    }

    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}

int main() {
    int arr[100];
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    //taking input
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    deleteElement(arr, &n);

    printf("\nArray after deletion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

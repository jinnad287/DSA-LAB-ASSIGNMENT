#include <stdio.h>

void deleteElement(int arr[], int *size) {
    int pos = -1, x;

    printf("Enter the element you want to delete: ");
    scanf("%d", &x);

    // Step 1: Find position of x
    for (int i = 0; i < *size; i++) {
        if (arr[i] == x) {
            pos = i;
            break;
        }
    }

    // If not found
    if (pos == -1) {
        printf("Value %d not found in array.\n", x);
        return;
    }

    // Step 2: Shift elements left
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Step 3: Decrease size
    (*size)--;

    printf("Element %d deleted successfully.\n", x);
}

int main() {
    int arr[100];
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Taking input
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

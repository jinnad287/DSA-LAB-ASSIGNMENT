#include <stdio.h>

void insertAtPosition(int arr[], int *size) {
    int pos, d;

    printf("Enter the position where you want to insert (1-based index): ");
    scanf("%d", &pos);

    // Validate position
    if (pos < 1 || pos > *size + 1) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter the new element to insert: ");
    scanf("%d", &d);

    // Step 1: Shift elements to the right
    for (int i = *size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Step 2: Insert the new element
    arr[pos - 1] = d;  // -1 because array is 0-indexed

    // Step 3: Increase size
    (*size)++;

    printf("Element %d inserted at position %d successfully.\n", d, pos);
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

    insertAtPosition(arr, &n);

    printf("\nArray after insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

#include <stdio.h>

void insertAfter(int arr[], int *size) {
    int pos = -1, x, d;

    printf("Enter the element After which you want to insert: ");
    scanf("%d", &x);

    printf("Enter the new element to insert: ");
    scanf("%d", &d);

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

    // Step 2: Shift elements to the right
    for (int i = *size; i > pos + 1; i--) {
        arr[i] = arr[i - 1];
    }

    // Step 3: Insert d after pos
    arr[pos + 1] = d;

    // Step 4: Increase size
    (*size)++;
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

    insertAfter(arr, &n);

    printf("\nArray after insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

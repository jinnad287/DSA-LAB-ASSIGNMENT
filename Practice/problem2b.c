#include <stdio.h>

void insertBefore(int arr[], int *size) {
    int pos = -1, x, d;

    printf("Enter the element before which you want to insert: ");
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

    // Step 2: Shift elements to the right starting from pos
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Step 3: Insert d at pos
    arr[pos] = d;

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

    insertBefore(arr, &n);

    printf("\nArray after insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

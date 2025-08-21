#include <stdio.h>

void insertBefore(int arr[], int *size) {
    int pos = -1, x, d;

    printf("Enter the element before which you want to insert: ");
    scanf("%d", &x);

    printf("Enter the new element to insert: ");
    scanf("%d", &d);

    for (int i = 0; i < *size; i++) {
        if (arr[i] == x) {
            pos = i;
            break;
        }
    }

    //Edge Case
    if (pos == -1) {
        printf("Value %d not found in array.\n", x);
        return;
    }

    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = d;

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

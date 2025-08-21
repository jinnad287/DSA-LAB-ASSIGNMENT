#include <stdio.h>

void insertAtPosition(int arr[], int *size) {
    int pos, d;

    printf("Enter the position where you want to insert (1-based index): ");
    scanf("%d", &pos);

    //checking position is correct or not
    if (pos < 1 || pos > *size + 1) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter the new element to insert: ");
    scanf("%d", &d);

    for (int i = *size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[pos - 1] = d;

    (*size)++;
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

    insertAtPosition(arr, &n);

    printf("\nArray after insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

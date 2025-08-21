#include <stdio.h>

void getNthFromEnd(int arr[], int size) {
    int n;

    printf("Enter n (to get the n-th element from the end): ");
    scanf("%d", &n);

    //cheaking position is valid or not
    if (n <= 0 || n > size) {
        printf("Invalid n! It should be between 1 and %d.\n", size);
        return;
    }

    int index = size - n;
    printf("The %d-th element from the end is: %d\n", n, arr[index]);
}

int main() {
    int arr[100];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nArray: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    getNthFromEnd(arr, size);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

int isEmpty() {
    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int peek() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return top->data;
}

void print() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return;
    }
    Node* temp = top;
    printf("Your Stack is:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Print the top Element\n4. Print all Elements in the Stack\n5. Quit\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Element to be pushed: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                data = pop();
                if (data != -1) {
                    printf("Element %d is Deleted Successfully!\n", data);
                }
                break;

            case 3:
                data = peek();
                if (data != -1) {
                    printf("The Top Element is : %d\n", data);
                }
                break;

            case 4:
                print();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

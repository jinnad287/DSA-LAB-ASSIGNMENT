#include <stdio.h>
#include <stdlib.h>


//-----------structure--------------
typedef struct Node {
    int data;
    struct Node* next;
}Node;


Node* top = NULL;


void push(int value){

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;

    newNode->next = top;

    top = newNode;
}


int pop() {
    if (top == NULL) {
        return -1;
    }
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}


int isEmpty() {
    return (top == NULL);
}

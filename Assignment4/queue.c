#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{

    char data;

    struct Node* next;

}Node;


typedef struct Queue{

    Node* front;

    Node* rear;

}Queue;


void initQueue(Queue* q){
    q->front = q->rear = NULL;
}


int isEmpty(Queue* q) {

    return (q->front == NULL);

}


void enqueue(Queue* q, char value){

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    }
    else {

        q->rear->next = newNode;
        q->rear = newNode;

    }
}


char dequeue(Queue* q){

    if (isEmpty(q)) return '\0';

    Node* temp = q->front;

    char value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return value;
}

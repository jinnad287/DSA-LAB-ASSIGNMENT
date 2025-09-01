#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}


void enqueue(Queue* q, int data) {
    Node* newNode = createNode(data);

    if(q->rear == NULL) { // Empty queue
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
    
}


int dequeue(Queue* q) {
    if(q->front == NULL) {
        printf("Queue is Empty. Cannot dequeue.\n");
        return -1;
    }

    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    if(q->front == NULL) { 
        q->rear = NULL;
    }

    free(temp);
    q->size--;
    return val;
}


int peek(Queue* q) {
    if(q->front == NULL) {
        printf("Queue is Empty.\n");
        return -1;
    }
    return q->front->data;
}


int isEmpty(Queue* q) {
    return (q->front == NULL);
}


int getSize(Queue* q) {
    return q->size;
}


void display(Queue* q) {
    if(q->front == NULL) {
        printf("Queue is Empty.\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    Queue q;
    initQueue(&q);

    int choice, value;

    while(1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. isEmpty\n");
        printf("5. Size\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                value = dequeue(&q);
                if(value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;

            case 3:
                value = peek(&q);
                if(value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;

            case 4:
                if(isEmpty(&q)) {
                    printf("Queue is Empty.\n");
                } else {
                    printf("Queue is not Empty.\n");
                }
                break;

            case 5:
                printf("Queue size: %d\n", getSize(&q));
                break;

            case 6:
                display(&q);
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

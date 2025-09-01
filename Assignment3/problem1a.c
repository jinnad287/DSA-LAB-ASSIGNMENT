#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
int top = -1;
int stack_arr[MAX];

int isFull(){
    if(top == MAX - 1){

        return 1;
    }else{
        return 0;
    }
}

int isEmpty(){
    if(top == -1){

        return 1;
    }else{
        return 0;
    }
}


void push(int data){
    if(isFull()){

        printf("Stack Overflow!");
        return;
    }

    top++;
    stack_arr[top] = data;

}

int pop(){
    int value;
    if(isEmpty()){

        printf("Stack Underflow!");
        exit(1);

    }

    value = stack_arr[top];
    top--;
    
    return value;
}

int peek(){
    if(isEmpty()){

        printf("Stack Underflow!");
        exit(1);

    }

    return stack_arr[top];
}

void print(){
    if(isEmpty()){

        printf("Stack Underflow!");
        exit(1);
    }

    for(int i = top; i>= 0 ; i--){
        printf("%d ",stack_arr[i]);

        printf("\n");
    }

    printf("\n");
}

int main(){
    int choice, data;
    while(1){
        printf("\n\n\n1. Push\n2. Pop\n3. Print the top Element\n4. print all Element in the Stack\n5. Quit\n\nEnter Your Choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1 :

            printf("\nEnter Element to be pushed: ");
            scanf("%d",&data);
            push(data);
            break;

            case 2 :

            printf("Element %d is Deleted Successfully!",pop());
            break;

            case 3 :
            printf("The Top Element is : %d\n",peek());

            break;

            case 4 :

            printf("Your Stack is :\n");
            print();
            break;

            case 5 :
            exit(1);


        }
    }
    return 0;

}

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* link;

}Node;

void takeData(Node** head, int data){
    //Memory Allocation for NewNode
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->link=NULL;

    
    if(*head==NULL){
        *head=newNode;
    }else{
       Node* temp = *head;
       while(temp->link != NULL){
           temp=temp->link;
       }
       temp->link = newNode;

    }
    
}

void insertAfter(Node** head){
    int x,data;

    printf("After which Node-Element You Want To Insert : ");
    scanf("%d",&x);

    //cheaking either the element is in the list or not
    int cheak= -1;
    Node* temp2= *head;
    while(temp2 != NULL){
        if(temp2->data == x){
            cheak++;
        }
        //update
        temp2=temp2->link;
    }
    if(cheak == -1){
        printf("\nElement Not Found in The List!! ");
        exit(1);
    }

    printf("\nEnter The Node-Element You Want To Insert : ");
    scanf("%d",&data);
    Node* temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->link=NULL;

    Node* ptr1= *head;
    Node* ptr2= *head;
    if(head==NULL){
        *head=temp;
        return;
    }
    else if(ptr1->data == x){
        ptr2=ptr2->link;
        temp->link = ptr2;
        (*head)->link=temp;
    }
    else{
        while(ptr1->data != x){
            ptr1=ptr2;
            ptr2=ptr2->link;
        }
        temp->link=ptr2;
        ptr1->link=temp;
     }

}

void insertBefore(Node** head){
    int x,data;

    printf("Before which Node-Element You Want To Insert : ");
    scanf("%d",&x);

    //cheaking either the element is in the list or not
    int cheak= -1;
    Node* temp2= *head;
    while(temp2 != NULL){
        if(temp2->data == x){
            cheak++;
        }
        //update
        temp2=temp2->link;
    }
    if(cheak == -1){
        printf("\nElement Not Found in The List!! ");
        exit(1);
    }

    printf("\nEnter The Node-Element You Want To Insert : ");
    scanf("%d",&data);
    Node* temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->link=NULL;

    Node* ptr1= *head;
    Node* ptr2= *head;
    if(head==NULL){
        *head=temp;
        return;
    }
    else if(ptr1->data == x){
        temp->link = *head;
        *head = temp;
    }
    else{
        while(ptr2->data != x){
            ptr1=ptr2;
            ptr2=ptr2->link;
        }
        temp->link = ptr2;
        ptr1->link = temp;
     }
}

void deleteNode(Node** head){
    int x;

    printf("Which Node You Want To Delete : ");
    scanf("%d",&x);

    //cheaking either the element is in the list or not
    int cheak= -1;
    Node* temp2= *head;
    while(temp2 != NULL){
        if(temp2->data == x){
            cheak++;
        }
        //update
        temp2=temp2->link;
    }
    if(cheak == -1){
        printf("\nElement Not Found in The List!! ");
        exit(1);
    }

    Node* ptr1 = *head;
    Node* ptr2 = *head;
    if(*head == NULL){
        printf("\nYour List is Already Empty!");
        return;
    }
    else if((*head)->data == x){

        ptr1 = ptr1->link;
        *head = ptr1;

        free(ptr2);
        ptr2 = NULL;
        

    }
    else{
        while(ptr2->data != x){
            ptr1=ptr2;
            ptr2 = ptr2->link;
        }

        ptr1->link = ptr2->link;
        free(ptr2);
        ptr2=NULL;

    }


}

void insertNthPosition(Node** head,int n){

    int position;
    printf("At Which Position You want To Insert: ");
    scanf("%d",&position);

    //cheaking The Position is Either a Valid Position or Not
    if( position > 1 && position <(n+2)){

        printf("Valid Position :) !\n");
    }else{
        printf("ERROR ! Invalid Position :( !\n\n");
        exit(1);
    }
    int data;
    printf("\nEnter The Node-Element You Want to Insert: ");
    scanf("%d",&data);

    Node* temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;

    Node* ptr1 = *head;
    Node* ptr2 = *head;

    if(position == 1){
        temp->link = *head;
        *head=temp;
    }else{
        while(position != 1){
            ptr1 = ptr2;
            ptr2 = ptr2->link;

            position--;
        }

        temp->link = ptr2;
        ptr1->link=temp;

    }


}

void middleData(Node* head, int n){

    if(n == 1){

        printf("Only One Middle Element and it is : %d\n",head->data);

    }
    else if(n%2 != 0){
        int middle=(n/2)+1;
        Node* temp = head;
        while(middle != 1){
            temp = temp->link;
            middle--;

        }


        printf("\nOnly One Middle Element and it is : %d\n",temp->data);

    }
    else{
        int middle1,middle2;
        middle1 = n/2;
        middle2 = (n/2)+1;

        Node* temp1 = head;
        Node* temp2 = head;

        //Fist Middle

        while(middle1 != 1){
            temp1 = temp1->link;
            middle1--;
        }
        //Second Middle
        while(middle2 != 1){
            temp2 = temp2->link;
            middle2--;

        }

        printf("\nThere are Two Middle Element and They are : %d  &  %d\n",temp1->data,temp2->data);


    }

}

void getNthDataFromEnd(Node* head, int n){

    int i;
    printf("Enter the Position From the End: ");
    scanf("%d",&i);
    //position from the first
    int position = n - (i-1);

    if(position > 0 && position < (n+1)){

       Node* temp = head;
       while(position != 1){
            
           temp = temp->link;
           position--;

    }

    printf("%d-th Data From The End is : %d\n",i,temp->data);
    }else{
        printf("ERROR! Invalid Position.\n");
        return;
    }
}



void printlist(Node* head){

    printf("Your Linked List is : ");
    Node* ptr=head;
    while(ptr != NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->link;

    }
    printf("NULL\n");

}


int main(){

    Node* head=NULL;
    int n,data;
    printf("Number of Node you Want to Insert: ");
    scanf("%d",&n);
    printf("Enetr Elements: \n");

    for(int i=0; i<n; i++){
        printf("Element %d : ",i+1);
        scanf("%d",&data);
        takeData(&head,data);
    }

    printlist(head);

    printf("-----Menu-----\n");
    printf("1. Insert After\n2. Insert Before\n3. Delete Node\n4. Insert Node At n-th  Position\n5. Middle Data of Linked List\n6. Get n-th Data From the End of Linked List\n\n\n");

    int choice;
    printf("\nEnter Your Choice: ");
    scanf("%d",&choice);


    switch(choice){
        case 1 :
        
        insertAfter(&head);
        printlist(head);

        break;

        case 2 :

        insertBefore(&head);
        printlist(head);
        break;

        case 3 :

        deleteNode(&head);
        printlist(head);

        break;

        case 4 :

        insertNthPosition(&head,n);
        printlist(head);
        break;

        case 5 :

        middleData(head,n);
        break;

        case 6 :

        getNthDataFromEnd(head,n);
        break;

        default:
        printf("Invalid Choice!! Please Enter A Valid Option.\n");
    }

    return 0;
    
}
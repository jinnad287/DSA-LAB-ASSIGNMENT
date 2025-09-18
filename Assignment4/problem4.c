#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "queue.c"



//----------------------------------------------------w#w---------------------------------------------------------
int check_w_hash_w(char str[]) {
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    int i = 0;
    while (str[i] != '#' && str[i] != '\0'){

        enqueue(&q1, str[i]);

        i++;
        
    }
    if (str[i] != '#') return 0;
    i++;

    while (str[i] != '\0'){

        enqueue(&q2, str[i]);

        i++;
    }

    while (!isEmpty(&q1) && !isEmpty(&q2)) {

        if (dequeue(&q1) != dequeue(&q2)) return 0;
    }
    return (isEmpty(&q1) && isEmpty(&q2));
}

//--------------------------------------------------------ww-----------------------------------------------------
int check_ww(char str[]) {

    int len = strlen(str);

    if (len % 2 != 0) return 0;

    Queue q1, q2;

    initQueue(&q1);
    initQueue(&q2);

    for (int i = 0; i < len/2; i++){

        enqueue(&q1, str[i]);

    }

    for (int i = len/2; i < len; i++){

        enqueue(&q1, str[i]);

    }

    while (!isEmpty(&q1) && !isEmpty(&q2)) {

        if (dequeue(&q1) != dequeue(&q2)) return 0;

    }

    return 1;
}

//---------------------------------------------------------w#w'--------------------------------------------------
int check_w_hash_w_reverse(char str[]) {

    Queue q1;

    initQueue(&q1);

    char s[100];

    int i = 0, j = 0;

    while (str[i] != '#' && str[i] != '\0') {

        enqueue(&q1,str[i]);

        i++;
    }

    if (str[i] != '#') return 0;

    i++;

    while (str[i] != '\0') {

        s[j++] = str[i];

        i++;
    }

    s[j] = '\0';

    for (int k = j - 1; k >= 0; k--) {

        if (isEmpty(&q1)) return 0;

        if (dequeue(&q1) != s[k]) return 0;

    }

    return isEmpty(&q1);
}


int main() {

    char input[100];

    int choice;

    while (1) {

        printf("\n----------------------------Menu------------------------------\n");
        printf("1. Check if string is of form w#w\n");
        printf("2. Check if string is of form ww\n");
        printf("3. Check if string is of form w#w'\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        if (choice == 4) {
            printf("Exit\n");
            break;
        }

        printf("Enter a string: ");
        scanf("%s",input);

        switch (choice) {

            case 1:

                if (check_w_hash_w(input))
                    printf("String is of the form w#w\n");
                else
                    printf("Not of the form w#w\n");
                break;

            case 2:

                if (check_ww(input))
                    printf("String is of the form ww\n");
                else
                    printf("Not of the form ww\n");
                break;

            case 3:

                if (check_w_hash_w_reverse(input))
                    printf("String is of the form w#w'\n");
                else
                    printf("Not of the form w#w'\n");
                break;

            default:
            
                printf("Invalid choice!Please Enter a Valid Choice.\n");
        }
    }

    return 0;
}

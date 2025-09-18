#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <string.h>

#include "stack.c"



int doOperation(char operation, int a, int b){

    switch (operation) {

        case '+': return a + b;

        case '-': return a - b;

        case '*': return a * b;

        case '/': return a / b;

        default:

            printf("Invalid Operator: %c\n",operation);
            exit(1);
    }
}


int evaluatePrefix(char* expr){

    int len = strlen(expr);

    
    for (int i = len - 1; i >= 0; i--) {

        char ch = expr[i];

        if (isspace(ch)) continue;

        if (isdigit(ch)) {

            
            push(ch - '0');

        } else {
            
            int a= pop();

            int b = pop();

            int result = doOperation(ch,a,b);

            push(result);

        }
    }

    return pop();
}

int main(){



    FILE* fp = fopen("operation.txt", "r");

    if(fp == NULL){

        printf("Error opening file.\n");

        return 1;
    }

    char s[100];

    fgets(s,sizeof(s),fp);
    

    fclose(fp);

    int result = evaluatePrefix(s);

    printf("Result = %d\n",result);



    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include "stack.c"

int isBalanced(char open, char close) {

    return ((open == '(' && close == ')') ||
            (open == '[' && close == ']') ||
            (open == '{' && close == '}'));

}


int main() {
    char pattern[100];

    printf("Enter a pattern: ");

    scanf("%s",pattern);

    for (int i = 0; pattern[i] != '\0'; i++) {

        char ch = pattern[i];

        if (ch == '(' || ch == '[' || ch == '{'){

            push(ch);
        } 
        else if(ch == ')' || ch == ']' || ch == '}'){

            if(isEmpty()){

                printf("Not Balanced\n");
                return 0;
            }
            
            char topChar = pop();

            if (!isBalanced(topChar, ch)){

                printf("Not Balanced\n");
                return 0;

            }
        }
    }

    if(isEmpty()) 
    {
        printf("Balanced\n");
    } 
    else {
        printf("Not Balanced\n");
    }

    return 0;
}

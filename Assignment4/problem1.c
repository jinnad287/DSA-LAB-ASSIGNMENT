#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "stack.c"



int isPrime(int n) {

    if (n < 2) return 0;

    for (int i = 2; i <= sqrt(n); i++) {

        if (n % i == 0) return 0;

    }

    return 1;
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d",&n);

    
    for (int i = n; i >= 2; i--) {

        if (n % i == 0 && isPrime(i)) {

            push(i);

        }
    }

    printf("Prime divisors in ascending order: ");

    while (!isEmpty()) {

        printf("%d ",pop());

    }
    printf("\n");

    return 0;
}

#include "stdio.h"

int reverse_number(int n) {
    int reversed_number = 0;

    while (n > 0) {

        int digit = n % 10;
        reversed_number = reversed_number * 10 + digit;
        n /= 10;
    }

    return reversed_number;
}


void main(){
    int x;

    printf("\nEnter a number: ");
    scanf("%d",&x);

    printf("\nReversed number: %d ",reverse_number(x));
    
}
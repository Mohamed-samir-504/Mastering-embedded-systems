#include "stdio.h"

void main(){
    int x;
    printf("\nEnter an integer: ");
    scanf("%d",&x);

    if(x<0){
        printf("\nError!!! factorial of a negative number does not exist.");
    }

    else if(x == 0){
        printf("\nFactorial = %d",1);
    }

    else{
        int result = 1;
        for(int i = 1; i<=x; i++){
            result*=i;
        }

        printf("\nFactorial = %d",result);

    }
    
}
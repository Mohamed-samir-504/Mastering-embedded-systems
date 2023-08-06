#include "stdio.h"

void prime(int a, int b){
    
    int f = 0;
    for(int i = a; i<=b; i++){

        for(int j = 2; j<=i-1; j++){
            if(i%j == 0 && i!=1){
                f = 1;
                break;
            }
        }

        if(!f){
            printf("%d ",i);
        }
        else f = 0;
    }
}
void main(){
    int a,b; 

    printf("\nEnter two numbers(intervals): ");
    scanf("%d%d",&a,&b);

    printf("\nPrime numbers between %d and %d are: ",a,b);
    prime(a,b);
}
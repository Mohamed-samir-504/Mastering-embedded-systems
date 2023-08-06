#include "stdio.h"

void main(){
    int x;
    printf("\nEnter an integer you want to check: ");
    scanf("%d",&x);
    
    if(x%2 == 0){
        printf("\n%d is even\n",x);
    }
    else{
        printf("\n%d is odd\n",x);
    }
}
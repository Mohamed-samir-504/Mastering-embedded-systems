#include "stdio.h"

void main(){
    float x;
    printf("\nEnter a number: ");
    scanf("%f",&x);
    
    if(x>0){
        printf("\n%f is positive\n",x);
        
    }
    else if(x<0){
        printf("\n%f is negative\n",x);
    }
    else{
        printf("\nYou entered zero");
    }
}
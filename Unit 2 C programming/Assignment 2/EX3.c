#include "stdio.h"

void main(){
    float x,y,z;
    printf("\nEnter three numbers: ");
    scanf("%f %f %f",&x,&y,&z);
    
    if(x>y){
        if(x>z){
            printf("\nLargest number = %f\n",x);
        }
        else{
            printf("\nLargest number = %f\n",z);
        }
        
    }
    else{
        if(y>z){
            printf("\nLargest number = %f\n",y);
        }
        else{
            printf("\nLargest number = %f\n",z);
        }
    }
}
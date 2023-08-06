#include "stdio.h"

void main(){
    float a,b;
    printf("\n");

    printf("Enter the value of a: ");
    scanf("%f",&a);

    printf("\nEnter the value of b: ");
    scanf("%f",&b);

    a += b; 
    b = a - b; 
    a -= b;    

    printf("\nAfter swapping, value of a = %f",a);
    printf("\nAfter swapping, value of b = %f",b);
}
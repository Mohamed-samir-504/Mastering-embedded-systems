#include "stdio.h"

void main(){
    float a,b,temp;
    printf("\n");

    printf("Enter the value of a: ");
    scanf("%f",&a);

    printf("\nEnter the value of b: ");
    scanf("%f",&b);

    temp = a;
    a = b;
    b = temp;

    printf("\nAfter swapping, value of a = %f",a);
    printf("\nAfter swapping, value of b = %f",b);
}
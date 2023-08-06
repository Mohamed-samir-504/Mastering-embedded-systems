#include "stdio.h"

void main(){
    float x,y;
    char c;
    printf("\nEnter operator either + or - or * or /: ");
    scanf("%c",&c);

    printf("\nEnter two operands: ");
    scanf("%f %f",&x,&y);

    switch (c)
    {
    case '+':
        printf("\n%f + %f = %f",x,y,x+y);
        break;
    
    case '-':
        printf("\n%f - %f = %f",x,y,x-y);
        break;
    
    case '*':
        printf("\n%f * %f = %f",x,y,x*y);
        break;

    case '/':
        printf("\n%f / %f = %f",x,y,x/y);
        break;
    
    default:
        printf("\nWrong choice");
        break;
    }
    //assignment 2 done
}
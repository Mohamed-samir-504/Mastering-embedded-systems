#include "stdio.h"

int fact(int x){
    if(x == 0 || x == 1)return 1;
    return x*fact(x-1);
}
void main(){

    int n;
    printf("\nEnter an positive integer: ");
   
    scanf("%d",&n);

    printf("\nFactorial of %d = %d",n,fact(n));
}
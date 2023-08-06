#include "stdio.h"
#include "math.h"

int sum = 0;

void summation(int n){
    if(n == 0)return;

    sum+=n;
    summation(n-1);
}

void main(){

    int x;
    printf("\nEnter a number: ");
    scanf("%d",&x);

    summation(x);
    printf("\nThe sum of numbers between 1 and %d = ",x);
    printf("%d",sum);
    
}
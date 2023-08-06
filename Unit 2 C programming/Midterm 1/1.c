#include "stdio.h"
#include "math.h"
#include "string.h"

void main(){
    int x,sum=0;
    printf("\nEnter a number: ");
    scanf("%d",&x);

    while(x!=0){
        sum+=x%10;
        x/=10;
    }

    printf("Sum = %d",sum);
}
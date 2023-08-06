#include "stdio.h"
#include "math.h"

void main(){
    int x,count=0;

    printf("\nEnter a number: ");
    scanf("%d",&x);

    int i = ceil(log2(x));
    int j = 0;

    while(i--){
        int y = x & (1<<j);
        if(y!= 0){
            count++;
        }
        j++;
    }
    printf("\nnumber of ones: %d ",count);
    
}
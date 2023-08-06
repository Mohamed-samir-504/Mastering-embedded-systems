#include "stdio.h"
#include "math.h"
#include "string.h"


void main() {
    int x,flag1 = 0,max = -1,count = 0,flag2 = 0;
    printf("\nEnter a number: ");
    scanf("%d",&x);
    
    for(int i = 0; i<ceil(log2(x))+1; i++){

        if((x&(1<<i)) == 0){
            if(flag1 == 0){
                flag2 = 1;
                flag1 = 1;
                continue;
            }
            else{
                max = max>count?max:count;
                count = 0;
            }
        }
        if(flag2 && (x&(1<<i)) != 0){
            count++;
        }

    }

    printf("output = %d",max);
    
}
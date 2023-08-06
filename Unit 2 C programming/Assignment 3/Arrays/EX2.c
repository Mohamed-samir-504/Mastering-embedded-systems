#include "stdio.h"

void main(){

    int n;
    float sum = 0;

    printf("\nEnter the number of data: ");
    scanf("%d",&n);

    float arr[n];
    
    for(int i = 0; i<n; i++){
        printf("Enter number: ");
        scanf("%f",&arr[i]);
        sum+=arr[i];
    }
    printf("\nAverage = %.2f\n",sum/n);

    
}
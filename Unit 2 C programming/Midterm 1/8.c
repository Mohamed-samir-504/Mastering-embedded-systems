#include "stdio.h"
#include "math.h"


void main(){

    int n;

    printf("\nRnter size of array: ");
    scanf("%d",&n);

    int arr[n];
    printf("\nEnter array elements: ");

    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);  
    }

    for(int i = 0,j=n-1; i!=j; i++,j--){
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for(int i = 0; i<n; i++){
        printf("%d ",arr[i]);
    }
}
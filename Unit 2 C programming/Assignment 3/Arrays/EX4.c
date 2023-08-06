#include "stdio.h"

void main(){
    
    int n,k,loc;
    
    printf("\nEnter number of elements: ");
    scanf("%d",&n);
    
    printf("\n");
    
    int arr[n+1];

    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
        
    }

    printf("\nEnter Element to be inserted: ");
    scanf("%d",&k);

    printf("\nEnter the location: ");
    scanf("%d",&loc);

    for(int i = n; i>=loc; i--){
        arr[i] = arr[i-1];
    }

    arr[loc-1] = k;

    for(int i = 0; i<n+1; i++){
        printf("%d ",arr[i]);
    }

}
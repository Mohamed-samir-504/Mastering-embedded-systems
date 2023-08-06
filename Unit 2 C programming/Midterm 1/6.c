#include "stdio.h"
#include "math.h"
#include "string.h"


void main()
{
    int n,flag=0,ans=-1;
   
    printf("\nEnter array size: ");
    scanf("%d",&n);

    int arr[n];
    printf("\nEnter array numbers: ");

    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);  
    }

    for(int i = 0; i<n; i++){

        int x = arr[i];
        for (int j = 0; j < n; j++){

            if(arr[j] == x && j!=i){
                flag = 1;
                break;
            }
           
        }
        if(!flag){
            ans = x;
            break;
        }
        else{
            flag = 0;
        }
          
    }

    printf("\nUnique element: %d",ans);
    
    
}
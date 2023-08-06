#include "stdio.h"

void main()
{
    int n,k;

    printf("\nEnter no of elements: ");

    scanf("%d",&n);

    int arr[n];

    printf("\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the element to be searched : ");
    scanf("%d",&k);

    for (int i = 0; i < n; i++)
    {
        if(arr[i]==k)
        {
            printf("\nNumber found at the location = %d",i+1);
            break;
        }
        if(i==n-1)
        {
            printf("Element not found");
        }
    }
    

}
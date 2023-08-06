#include "stdio.h"
#include "string.h"

void reverse(char arr[], int a, int b){
    
    if(a==b)return;
    else{
        char temp;
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
        reverse(arr,a+1,b-1);
    }
}
void main(){

    char arr[30];

    printf("\nEnter a sentence: ");
    gets(arr);

    reverse(arr,0,strlen(arr)-1);

    printf("\n%s",arr);
}
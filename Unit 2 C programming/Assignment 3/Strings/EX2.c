#include "stdio.h"
#include "string.h"

void main(){
    char str[50];
    int count = 0;

    printf("\nEnter a string: ");
    gets(str);

    
    for(int i = 0; str[i]!=0; i++){
        count++;
    }

    printf("\nLength of string = %d",count);
}
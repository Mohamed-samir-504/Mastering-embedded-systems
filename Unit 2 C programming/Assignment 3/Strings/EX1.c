#include "stdio.h"
#include "string.h"

void main(){
    char str[50];
    char c;
    int count = 0;

    printf("\nEnter a string: ");
    gets(str);

    printf("\nEnter a character to find frequency: ");
    scanf("%c",&c);
    for(int i = 0; i<strlen(str); i++){
        if(str[i] == c)count++;
    }

    printf("\nFrequency of %c = %d",c,count);
}
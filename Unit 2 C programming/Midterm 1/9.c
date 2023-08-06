#include "stdio.h"
#include "math.h"
#include "string.h"

void main(){
    char result[100][100];
    int c = 0,j=0,k=0;
    char str[100];

    printf("\nEnter string: ");
    gets(str);

    char temp[100];
    for(int i = 0; i<=strlen(str); i++){
        if(str[i] == ' ' || i == trlen(str)){
            c++;
            strcpy(result[j++],temp);
            k=0;
            memset(temp,0,strlen(temp));
        }
        else{
            temp[k++] = str[i];
        }
    }

    for(int i= c-1; i>=0; i++){
        printf("%s ",result[i]);
    }
}
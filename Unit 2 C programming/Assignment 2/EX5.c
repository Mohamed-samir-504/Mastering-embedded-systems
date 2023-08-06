#include "stdio.h"

void main(){
    char c;
    printf("\nEnter a character: ");
    scanf("%c",&c);
    
    if((c>=65 && c<=90) ||(c>=97 && c<=122)){
        printf("\n%c is an alphabet\n",c);
        
    }
   
    else{
        printf("\n%c is not an alphabet\n",c);
    }
}
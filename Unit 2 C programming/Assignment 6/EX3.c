#include "stdio.h"
#include "string.h"

void main()
{
    printf("Input a string: ");

    char* str;
    gets(str);    


    for (int i=strlen(str)-1; i>=0; i--){

        printf("%c", *(str+i));

    }


}
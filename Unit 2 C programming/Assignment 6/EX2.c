#include "stdio.h"

void main()
{
    char c = 'A';
    char* cp = &c;

    printf("\n");
    for(int i = 0; i<26; i++){
        printf("%c ",*cp+i);
    }
}
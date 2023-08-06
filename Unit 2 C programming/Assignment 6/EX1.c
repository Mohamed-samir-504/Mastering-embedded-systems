#include "stdio.h"

void main()
{
    int m = 29;

    printf("Address of m : %p\nValue of m : %d",&m,m);

    printf("\n\n\nNow ab is assigned with the address of m.\n");

    int *ab = &m; 

    printf("Address of pointer ab : %p\nContent of pointer ab: %d",ab,*ab);
    
    m = 34;

    printf("\n\n\nThe value of m is assigned to 34 now.\n");

    printf("Address of pointer ab: %p  \nContent of pointer ab : %d",ab,*ab);

    *ab =7;

    printf("\n\n\nThe pointer variable ab is assigned with the value 7 now.\n");

    printf("Address of m : %p\nValue of m : %d",&m,m);


}
#include <stdio.h>

int pow(int a, int b)
{
    if(b==0) return 1;
    
    else if(b==1) return a;

    else return a*pow(a,b-1);
}


int main()
{
    int a,b;

    printf("\nEnter base number: ");
    scanf("%d",&a);

    printf("\nEnter power number(positive integer : ");
    scanf("%d",&b);
    

    printf("%d^%d = %d",a,b,pow(a,b));
    
}
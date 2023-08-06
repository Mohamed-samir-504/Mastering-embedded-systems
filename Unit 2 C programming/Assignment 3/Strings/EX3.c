#include "stdio.h"
#include "string.h"

void main()
{
    char str[100], s;
    int i, j;

    printf("\nEnter the string :");
    gets(str);

    i = 0;
    j = strlen(str) - 1;

    while (i < j)
    {
        s = str[i];
        str[i] = str[j];
        str[j] = s;
        i++;
        j--;
    }
    printf("\nReverse string is: %s", str);
    
}

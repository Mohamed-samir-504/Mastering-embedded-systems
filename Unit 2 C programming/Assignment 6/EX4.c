#include "stdio.h"
#include "string.h"

int main()
{
    int n;
    int arr[15];

    printf("\nInput the number of elements to store in the array (max 15): ");
    scanf("%d", &n);


    for (int i = 0; i < n; i++)
    {
        printf("element - %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nThe elements of the array in reverse order \n");

    for (int i = n - 1; i >= 0; i--)
    {
        printf("element - %d : %d", i + 1, *(arr + i));
        printf("\n");
    }
}
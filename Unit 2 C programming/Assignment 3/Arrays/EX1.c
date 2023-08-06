#include "stdio.h"

void main(){
    
    float a[2][2];
    float b[2][2];
    
    printf("\nEnter the elements of the first matrix\n");

    for(int i = 0; i<2; i++){
        for(int j = 0; j<2;j++){
            printf("Enter a%d%d: ",i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }

    printf("\nEnter the elements of the second matrix\n");

    for(int i = 0; i<2; i++){
        for(int j = 0; j<2;j++){
            printf("Enter b%d%d: ",i+1,j+1);
            scanf("%f",&b[i][j]);
        }
    }

    printf("\nSum of matrix:\n");

    for(int i = 0 ; i<2; i++){
        printf("%.1f\t%.1f",a[i][0]+b[i][0],a[i][1]+b[i][1]);
        printf("\n");
        
    }
}
#include "stdio.h"

void main(){

    int r,c,tr,tc;

    printf("\nEnter rows and columns of matrix: ");
    scanf("%d %d",&r,&c);

    int a[r][c];
    tr=c; tc=r;
    int t[tr][tc];

    printf("\nEnter elements of matrix: \n");
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c;j++){
            printf("Enter a%d%d: ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nEntered matrix: \n");
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c;j++){
            printf("%d\t",a[i][j]);
            
        }
        printf("\n\n");
    }

    for(int i = 0; i<tr; i++){
        for(int j = 0; j<tc;j++){
            t[i][j] = a[j][i];          
        }
        
    }
    printf("\nTranspose of matrix: \n");
    
    for(int i = 0; i<tr; i++){
        for(int j = 0; j<tc;j++){
            printf("%d\t",t[i][j]);
            
        }
        printf("\n\n");
    }
    
}
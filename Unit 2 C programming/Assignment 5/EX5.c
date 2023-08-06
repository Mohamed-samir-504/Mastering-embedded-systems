#include <stdio.h>

#define PI 3.14
#define calc_area(r)(PI*r*r)

void main(){
    int r;
    float area;

    printf("\nEnter radius: ");
    scanf("%d",&r);

    area = calc_area(r);
    printf("\narea = %.1f ",area);
}

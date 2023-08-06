#include "stdio.h"

struct Distance {
   int feet;
   float inch;
};


void main() {
   struct Distance d1, d2, d3;
   printf("\nEnter information of first distance\n");

   printf("Enter feet: ");
   scanf("%d",&d1.feet);
   
   printf("Enter inches: ");
   scanf("%f",&d1.inch);

   printf("\nEnter information of second distance\n");

   printf("Enter feet: ");
   scanf("%d",&d2.feet);
   
   printf("Enter inches: ");
   scanf("%f",&d2.inch);

   d3.feet = d1.feet + d2.feet;
   d3.inch = d1.inch + d2.inch;

   if(d3.inch > 12) {
      d3.feet++;
      d3.inch = d3.inch - 12;
   }
   printf("\nSum of distances = %d feet and %.1f inches",d3.feet,d3.inch);
   
}
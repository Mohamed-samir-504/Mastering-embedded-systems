#include "stdio.h"

struct complex {
   float real;
   float img;
};


void main() {
   struct complex num1,num2,result;
   printf("\nFor 1st complex number\n");

   printf("Enter real and imaginary respectively: ");
   scanf("%f %f",&num1.real,&num1.img);
   
   printf("\nFor 2nd complex number\n");

   printf("Enter real and imaginary respectively: ");
   scanf("%f %f",&num2.real,&num2.img);

   result.real = num1.real+num2.real;
   result.img = num1.img+num2.img;

   
   printf("\nSum  = %.2f + %.2fi",result.real,result.img);
   
}
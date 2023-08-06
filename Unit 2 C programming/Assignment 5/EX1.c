#include "stdio.h"

struct Student
{
    char name[10];
    int roll;
    float marks;
};

struct Student read_data(){
    struct Student res;
    printf("\nEnter information of student: ");

    printf("\nEnter name: ");
    gets(res.name);

    printf("Enter roll number: ");
    scanf("%d",&res.roll);

    printf("Enter marks: ");
    scanf("%f",&res.marks);

    return res;
}

void display(struct Student res){
    printf("\nDisplaying information ");

    printf("\nname: %s",res.name);
    printf("\nRoll: %d",res.roll);
    printf("\nmarks: %f",res.marks);

}

void main(){

    struct Student st = read_data();
    display(st);
}

#include <stdio.h>
struct student
{
    char name[50];
    int roll;
    float marks;
};

void main()
{
    //assume size = 3 for simplicity of output
    struct student st[3];
    
    printf("Enter information of students:\n");
    for (int i = 0; i < 3; ++i)
    {
        st[i].roll = i + 1;
        printf("\nFor roll number %d\n", st[i].roll);

        printf("Enter name: ");
        scanf("%s", &st[i].name);

        printf("Enter mark: ");
        scanf("%f", &st[i].marks);

        
    }

    printf("\nDisplaying information of studentsn\n");

    for(int i = 0; i<3;i++){
        
        printf("\ninformation for roll number %d:\n", i+1);
        printf("Name:");

        puts(st[i].name);

        printf("Marks: %.1f", st[i].marks);
    }
    
}

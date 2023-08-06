#include "stdio.h"
#include "string.h"

struct emp
{

    char *name;
    int id;
};

void main()
{
    struct emp emp1 = {"mohamed", 15}, emp2 = {"hossam", 56};
    
    struct emp (*arr[]) = {&emp1, &emp2};

    struct emp *(*p)[] = &arr;

    printf("\nfirst employee name: %s", (*(*p))->name);
    printf("\nfirst employee id: %d", (**(*p)).id);

    printf("\nsecond employee name: %s", (*(*p+1))->name);
    printf("\nsecond employee id: %d", (**(*p+1)).id);
}

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct Sdata{

	int ID;
	char name[40];
	float height;
}Student;

typedef struct Node{

	Student st;
	struct Node* Next;
}St_node;

void AddStudent();
void fillStudentData(St_node* p);
void DeleteStudent();
void ViewAllStudents();
void DeleteAll();
void GetNTH();
int findLengthIterative();
int findLengthRecursive(St_node* curr);
void GetNthNodeFromEnd();

#define PRINT(...)		fflush(stdin);\
						fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdin);\
						fflush(stdout);


#endif

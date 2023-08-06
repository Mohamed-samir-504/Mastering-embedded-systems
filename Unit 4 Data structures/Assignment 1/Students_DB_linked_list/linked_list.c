#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"
#include "conio.h"

St_node *head = NULL;

void AddStudent(){

	St_node* newStudent;
	St_node* last;
	if(head == NULL){

		newStudent = (St_node*)malloc(sizeof(St_node));
		head = newStudent;
	}

	else{
		last = head;
		while(last->Next != NULL){
			last = last->Next;
		}
		newStudent = (St_node*)malloc(sizeof(St_node));
		last->Next = newStudent;

	}

	fillStudentData(newStudent);
	newStudent->Next = NULL;



}

void fillStudentData(St_node* p){
	char temp[12];
	PRINT("\nEnter Student ID: ");
	gets(temp);
	p->st.ID = atoi(temp);

	PRINT("\nEnter Student name: ");
	gets(p->st.name);

	PRINT("\nEnter Student height: ");
	gets(temp);
	p->st.height = atof(temp);
}

void DeleteStudent(){
	int selected_id;

	PRINT("\nEnter ID of student to be deleted: ");
	scanf("%d",&selected_id);

	St_node* selected_st = head;
	St_node* prev;

	if(head){

		if(selected_st->st.ID == selected_id){
			head = head->Next;
			free(selected_st);

		}

		else{

			while(selected_st){
				if(selected_st->st.ID == selected_id){
					prev->Next = selected_st->Next;
					free(selected_st);
					return;
				}
				prev = selected_st;
				selected_st = selected_st->Next;
			}
			PRINT("Student was not found\n");

		}
	}
	else{
		PRINT("List is empty\n");
	}

}

void ViewAllStudents(){
	St_node* current = head;
	int count = 0;
	if(head == NULL){
		PRINT("\nList is empty\n");
	}
	else{
		while(current){
			PRINT("\n record number %d\n",count+1);
			PRINT("ID %d\n",current->st.ID);
			PRINT("name %s\n",current->st.name);
			PRINT("height %f\n",current->st.height);

			current = current->Next;
			count++;
		}
	}
}

void DeleteAll(){
	St_node* current = head;
	if(head == NULL){
		PRINT("\nList is empty\n");
	}
	else{
		while(current){
			St_node* temp = current;
			current = current->Next;
			free(temp);
		}
		head = NULL;
	}
}

void GetNTH(){
	int index;
	PRINT("Enter index: ");
	scanf("%d",&index);
	if(head){
		if(index == 1){
			PRINT("\n record at index number %d\n",index);
			PRINT("ID %d\n",head->st.ID);
			PRINT("name %s\n",head->st.name);
			PRINT("height %f\n",head->st.height);
		}
		else{
			int count = 1;
			St_node* curr = head;
			while(head){
				if(count == index){
					PRINT("\n record at index number %d\n",index);
					PRINT("ID %d\n",curr->st.ID);
					PRINT("name %s\n",curr->st.name);
					PRINT("height %f\n",curr->st.height);
					return;
				}
				curr = curr->Next;
				count++;
			}

		}
	}
	else{
		PRINT("\nList is empty");
	}

}

int findLengthIterative(){
	int count = 0;
	St_node* curr = head;
	while(curr){
		count++;
		curr = curr->Next;
	}
	return count;
}

int findLengthRecursive(St_node* curr){
	if(curr == NULL)return 0;
	else return 1+findLengthRecursive(curr->Next);
}

void GetNthNodeFromEnd(){
	int n;
	PRINT("Enter n: ");
	scanf("%d",&n);

	St_node* p1 = head;
	St_node* p2 = p1;
	int len = findLengthIterative();
	if(n == len){
		PRINT("\n record at index number %d\n",n);
		PRINT("ID %d\n",p1->st.ID);
		PRINT("name %s\n",p1->st.name);
		PRINT("height %f\n",p1->st.height);
	}
	else if(n>len){
		PRINT("\n Invalid n");
	}
	else{
		for(int i = 0; i<n; i++){
				p1 = p1->Next;
		}


		while(p1){
			p1 = p1->Next;
			p2 = p2->Next;;
		}

		PRINT("\nrecord at index number %d from the end\n",n);
		PRINT("ID %d\n",p2->st.ID);
		PRINT("name %s\n",p2->st.name);
		PRINT("height %f\n",p2->st.height);
	}



}


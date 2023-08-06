#include "stdio.h"
#include "string.h"
#include "linked_list.h"


extern St_node *head;

int main(){

	int choice;

		do
		{
			PRINT("\n==================================================\n");
			PRINT("1.  Add a New Student.\n");
			PRINT("2.  Remove a Student.\n");
			PRINT("3.  Delete All Students.\n");
			PRINT("4.  View All Students Data.\n");
			PRINT("5.  Get data of Nth node.\n");
			PRINT("6.  Calculate Number Of the Students iteratively.\n");
			PRINT("7.  Calculate Number Of the Students recursively.\n");
			PRINT("8.  Get Nth Node From End.\n");
			PRINT("9. Exit.\n");
			PRINT("================================================\n");

			PRINT("Enter your choose: ");
			scanf("%d",&choice);

			switch(choice)
			{
				case 1:
					AddStudent();
				break;

				case 2:
					DeleteStudent();
				break;

				case 3:
					DeleteAll();
				break;

				case 4:
					ViewAllStudents();
				break;

				case 5:
					GetNTH();
				break;

				case 6:
					PRINT("\nNumber of Students: %d\n",findLengthIterative());
				break;

				case 7:
					PRINT("\nNumber of Students: %d\n",findLengthRecursive(head));
				break;

				case 8:
					GetNthNodeFromEnd();
				break;

				case 9:
				PRINT("\nThe Program is End.\n");
				exit(0);
				break;

				default:
				PRINT("Wrong choice !!!.\n");
				break;
			}

		}while(choice != 9);

		return 0;
}



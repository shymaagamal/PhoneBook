#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"utilities.h"
#include"PhoneBook.h"
#include"type.h"



void clear();
int main() {

	readFromFile() ;
	char selection[40];
	int choice;
	while (1) {
		puts("\n****************PhoneBook Application main menu****************\n");
		puts(" 1. Insert a new record");
		puts(" 2. Display All records");
		puts(" 3. search by name");
		puts(" 4. search by Email");
		puts(" 5. search by PhoneNumber");
		puts(" 6. Edit Name");
		puts(" 7. Edit Email");
		puts(" 8. Edit PhoneNum");
		puts(" 9. Delete a record by PhoneNumber ");
		puts(" 10. Exit");
		do {
			printf("Enter Your choice\n");
			gets(selection);
			choice = atoi(selection);
		} while (choice < 1 || choice > 10);

		switch (choice) {
		case 1:
			addElement();
			clear();
			break;
		case 2:
			displayALL();
			clear();
			break;
		case 3:
			printf("Enter Name to Search:");
			gets(selection);
			search(selection, NAME);
			clear();
			break;
		case 4:
			printf("Enter Email to Search:");
			gets(selection);
			search(selection, EMAIL);
			clear();
			break;
		case 5:
			printf("Enter PhoneNum to Search:");
			gets(selection);
			search(selection, PHONENUM);
			clear();
			break;
		case 6:
			printf("Enter Name to edit:");
			gets(selection);
			edit(selection,NAME);
			clear();
			break;
		case 7:
			printf("Enter Email to Edit:");
			gets(selection);
			edit(selection, EMAIL);
			clear();
			break;
		case 8:
			printf("Enter PhoneNum to Edit:");
			gets(selection);
			edit(selection, PHONENUM);
			clear();
			break;
		case 9:
			printf("Enter PhoneNum to delete:");
			gets(selection);
			removeElement(selection);
			clear();
			break;
		case 10:
			exit(0);
			break;
		default:
			break;

		}
	}

	return 0;
}

void clear()
{
	 system("PAUSE");
	 system("CLS");
}




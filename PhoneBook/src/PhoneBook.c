/*Function Defination*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"type.h"
#include"PhoneBook.h"
#include"utilities.h"

#define MAX_SIZE 100

/*array to hold records*/
struct record phonebook[MAX_SIZE];
/*Current size of phone book array*/
int currentsize = 0;

void addElement() {
	if (currentsize == MAX_SIZE) {
		puts("Error : PhoneBook is Full");
		return;
	}
	struct record element;
	printf("Enter Your Name: ");
	gets(element.Name);
	printf("Enter Your Email: ");
	gets(element.email);
	printf("Enter Your Phone Number: ");
	gets(element.PHoneNum);
	phonebook[currentsize] = element;
	currentsize++;
	SaveToFile();

}

void display(int index) {
	if (index < 0 || index >= currentsize) {
		puts("Invalid index");
		return;
	}
	struct record element = phonebook[index];
	printf("\nName: %s\n", element.Name);
	printf("Email: %s\n", element.email);
	printf("PhoneNumber: %s\n", element.PHoneNum);

}
void displayALL() {
	if (currentsize == 0) {
		puts("PhoneBook is Empty");
		return;
	}
	puts("Display All Elements in DataBase");
	for (int i = 0; i < currentsize; i++) {
		display(i);
		puts("");
	}
}
void search(char *key, search_t type) {
	int found = 0;
	int i;
	char content[40];
	if (type == NAME) {/*Search by name*/
		for (i = 0; i < currentsize; i++) {
			strcpy(content, phonebook[i].Name);
			strtolower(content);
			if (strcmp(content, key) == 0) {
				display(i);
				found = 1;
			}
		}

	}

	else if (type == EMAIL) {
		/*search by email*/
		for (i = 0; i < currentsize; i++) {

			strcpy(content, phonebook[i].email);
			strtolower(content);
			if (strcmp(content, key) == 0) {
				display(i);
				found = 1;
			}
		}
	} else if (type == PHONENUM) {/*search by PhoneNumber*/
		for (i = 0; i < currentsize; i++) {
			strcpy(content, phonebook[i].PHoneNum);
			strtolower(content);
			if (strcmp(content, key) == 0) {
				display(i);
				found = 1;
			}
		}

	}

	else {
		puts("Error : Invalid search type");
		return;
	}
	if (!found) {
		puts("\nNot Found in phone book");
	}
}
void edit(char *element, search_t type) {
	int found = 0;
	int i;
	char content[40];
	struct record Edit_element;

	if (type == NAME) {
		for (i = 0; i < currentsize; i++) {
			strcpy(content, phonebook[i].Name);
			strtolower(content);
			if (strcmp(content, element) == 0) {
				puts("Edit Name to => ");
				gets(Edit_element.Name);
				strcpy(phonebook[i].Name,Edit_element.Name);
				display(i);
				found = 1;
			}
		}

	} else if (type == EMAIL) {
		for (i = 0; i < currentsize; i++) {
			strcpy(content, phonebook[i].email);
			strtolower(content);
			if (strcmp(content, element) == 0) {
				puts("Edit Email to => ");
				gets(Edit_element.email);
				strcpy(phonebook[i].email,Edit_element.email);

				display(i);
				found = 1;
			}
		}
	} else if (type == PHONENUM)
	{
		for (i = 0; i < currentsize; i++) {
			strcpy(content, phonebook[i].PHoneNum);
			strtolower(content);
			if (strcmp(content, element) == 0) {
				puts("Edit PhonNum to => ");
				gets(Edit_element.PHoneNum);
				strcpy(phonebook[i].PHoneNum,Edit_element.PHoneNum);
				display(i);
				found = 1;
			}
		}
	}
	else {
		puts("Error : Invalid Edit type");
		return;
	}
	if (!found) {
		puts("\nNot Found in phone book");
	}
	SaveToFile();

}
void removeElement(char *PhoneNum) {

	if (currentsize == 0) {
		puts("PhoneBook is empty! Nothing to delete");
		return;
	}
	int i, j;
	int count = 0;
	for (i = 0; i < currentsize; i++) {
		if (strcmp(phonebook[i].PHoneNum, PhoneNum) == 0) {
			for (j = i; j < currentsize - 1; j++) {
				phonebook[j] = phonebook[j + 1];
			}
			strcpy(phonebook[j].Name, "");
			strcpy(phonebook[j].email, "");
			strcpy(phonebook[j].PHoneNum, "");
			currentsize -= 1;
			count++;
		}
	}
	if (count == 0) {
		puts("No Element Deleted");
	} else {
		printf("%d Elements Deleted", count);
	}
	SaveToFile();
}

void readFromFile() {
	FILE *fp;
	if ((fp = fopen("phonebook.db", "rb")) == NULL) {
		puts("Error: can't read data ");
		return;

	}
	if (fread(&currentsize, sizeof(currentsize), 1, fp) != 1) {
		puts("Error: Can't read data");
		return;

	}
	if (fread(phonebook, sizeof(phonebook), 1, fp) != 1) {
		puts("Error: Can't read data");
		return;
	}

}

void SaveToFile() {
	FILE *fp;
	if ((fp = fopen("phonebook.db", "wb")) == NULL) {
		puts("Error: cant create a database file");
		return;
	}
	if (fwrite(&currentsize, sizeof(currentsize), 1, fp) != 1) {
		puts("Error: Can't save data");
		return;

	}
	if (fwrite(phonebook, sizeof(phonebook), 1, fp) != 1) {
		puts("Error: Can't save data");
		return;
	}

}


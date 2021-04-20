/*
 * PhoneBook.h
 *
 *  Created on: Apr 20, 2021
 *      Author: shyma
 */

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_
#include"type.h"
/*Function ProtoType*/
void addElement();
void display(int index);
void displayALL();
void search(char *key, search_t type);
void edit(char *element,search_t type);
void removeElement(char *PhoneNum);
void readFromFile();
void SaveToFile();

#endif /* PHONEBOOK_H_ */

/*
 * utilities.c
 *
 *  Created on: Apr 20, 2021
 *      Author: shyma
 */
#include<ctype.h>
#include<string.h>

#include"utilities.h"
void strtolower(char *str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {

		str[i] = tolower(str[i]);

	}

}

/*
 * type.h
 *
 *  Created on: Apr 20, 2021
 *      Author: shyma
 */

#ifndef TYPE_H_
#define TYPE_H_

struct record {
	char Name[40];
	char email[40];
	char PHoneNum[40];

};

typedef enum {
	NAME, EMAIL, PHONENUM
} search_t;


#endif /* TYPE_H_ */

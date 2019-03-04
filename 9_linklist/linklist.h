#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;

struct linklist
{
	datatype data;
	struct linklist *next;
};

extern void Init_head(struct linklist** head_loc);
extern bool Create_list(struct linklist* head);
extern bool Insert_data(struct linklist* head,int input,int loc);
extern bool Traverse_list(struct linklist* head);

#endif

#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct linklist
{
	int data;
	struct linklist* next;
}linklist;

extern linklist* Init_head(void);
extern bool Create_list(linklist* f);
extern void Traverse_list(linklist* f);
extern int Max_number(linklist* f);
extern int Inode_number(linklist* f);
extern float Average_list(linklist* f);
#endif

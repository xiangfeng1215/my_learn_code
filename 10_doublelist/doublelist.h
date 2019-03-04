#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dlist{
	int data;
	struct dlist* next;
	struct dlist* prev;
}dlist;

extern dlist* Init_ret_head(void);
extern bool Create_list(dlist* head);
extern void Traverse_list(dlist* head);
extern bool Insert_list(dlist* head,int key,int input);
extern bool Change_list(dlist* head,int key,int input);
extern bool Delete_list(dlist* head,int key);
extern bool Destory_list(dlist* head);



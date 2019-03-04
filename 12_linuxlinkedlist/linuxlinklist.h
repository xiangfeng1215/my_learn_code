#pragma once 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct list{
	char name[20];
	int score;
	int classs;
	struct list_head mylist;
}dlist;

extern dlist* Init(dlist* head);
extern bool Insert_tail(dlist* head,char *name,int score,int classs);
extern bool Delete_node(dlist* head,char *name);
extern bool fine_node(dlist* head,char *data);
extern void show_list(dlist* head);

#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

typedef struct node{
	int data;
	struct list_head list;
}node;

extern node* Init_ret_head(void);
extern bool Create_list(node *head);
extern void Treaverse(node* head);
extern bool List_move_tail(int key,node* head);


#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct linklist
{
		int data;
			struct linklist* next;
}linklist;

extern void Init_head(linklist** head_loc);
extern bool Create_list(linklist* head);
extern void Traverse_list(linklist* head);
extern bool Insert_list(linklist* head,int key,int input);
extern linklist* Inverse_list(linklist* head);

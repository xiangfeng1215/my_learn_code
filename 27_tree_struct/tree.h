#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int datatype;

typedef struct node{
	datatype data;
	struct node* lchild;
	struct node* rchild;
}node;

extern void Init_root(node** root,int input);
extern bool Insert_tree(node* root,int input);
extern void Pre_order(node* root);
extern void Mid_order(node* root);
extern void Rear_order(node* root);


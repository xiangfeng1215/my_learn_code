#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int datatype;

typedef struct node{
	struct node* lchild;
	struct node* rchild;
	datatype data;
}node;

extern void Init(node** t,datatype input);
extern bool Insert(node* t,datatype input);
extern void Pre_traverse(node* t);
extern void Mid_traverse(node* t);
extern void Rear_traverse(node* t);



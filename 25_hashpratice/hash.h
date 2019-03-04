#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int datatype;

typedef struct node{
	datatype data;
	int len;
	struct node* next;
}node;

typedef node* ARRAT_TYPE[10];

extern int Hash_func(datatype element);
extern void Init_hash(node* a[]);
extern bool Insert_hash(node* a[],datatype element);
extern bool Delete_hash(node* a[],datatype key);
extern bool Traverse_hash(node* a[]);
extern bool Search_hash(node* a[],datatype key);
extern bool Modity_hash(node* a[],datatype key);



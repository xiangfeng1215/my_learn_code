#pragma once 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node{
	datatype data;
	struct node* next;
	float padding;
}node;

typedef node* ARRAY_TYP[10];

extern int Hash_func(int element);
extern void Init_hash(node* arr[],int len);
extern bool Add_hash(node* arr[],int element);
extern void Traverse(node* arr[],int len);
extern bool Delete_hash(node* arr[],int key);
extern bool Search_hash(node* arr[],int key,int len);
extern bool Modify_hash(node* arr[],int key,int len);



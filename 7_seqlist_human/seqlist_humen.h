#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INIT_SIZE 5
#define INCRESIZE 10

struct humen
{
	char name[20];
	int age;
};

struct seqlist
{
	struct humen* data;
	int last;
	int size;
	int incresize;
};
extern void Init_list(struct seqlist* list);
extern bool Insert_data(struct seqlist* list,int loc,struct humen input);
extern void Traverse_list(struct seqlist list);
extern bool Delete_list(struct seqlist* list,int loc);
extern bool Change_list(struct seqlist* list,int key,struct humen input);
extern bool Search_list(struct seqlist list,int  key);
extern bool Destory_list(struct seqlist** list);


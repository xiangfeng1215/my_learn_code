#pragma once 
#include <stdio.h>
#include <stdlib.h>

typedef int typedata;

struct seqlist{
	typedata * data;
	int size;
	int last;
	int incresize;
};

extern void Init_list(seqlist* list,int init_size);
extern bool Insert_list(seqlist*list,int input,int loc);
extern bool Traverse_list(seqlist list);


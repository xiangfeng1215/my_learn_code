#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 10

typedef int datatype;

typedef struct doulstack{
	int top[2];
	int bot[2];
	datatype *V;
	int max_size;
}doulstack;

extern void Init_doul_stack(doulstack* s);

extern bool Is_empty_stack_top(doulstack* s);
extern bool Is_full_stack_top(doulstack* s);
extern bool Push_doul_stack_top(doulstack* s,datatype element);
extern bool Pop_doul_stack_top(doulstack* s);
extern void Display_doul_stack_top(doulstack* s);

//extern void Init_doul_stack_bot(doulstack* s);
extern bool Is_empty_stack_bot(doulstack* s);
extern bool Is_full_stack_bot(doulstack* s);
extern bool Push_doul_stack_bot(doulstack* s,datatype element);
extern bool Pop_doul_stack_bot(doulstack* s);
extern void Display_doul_stack_bot(doulstack* s);

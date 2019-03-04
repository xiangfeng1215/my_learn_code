#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char datatype;

struct seqstack
{
	datatype *data;
	int top;
	int size;
	int incresize;
};

typedef struct seqstack stack;

extern void Init_stack(stack* s);
extern bool Push(stack *s,datatype element);
extern bool Pop(stack* s);
extern void Display(stack s);
extern bool Is_empty(stack *s);
extern bool Is_full(stack *s);
extern bool Hui_wen(char* s);

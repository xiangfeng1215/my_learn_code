#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct linkstack{
	int data;
	struct linkstack* next;
}stack;

extern void Init_head(stack**  head);
extern bool Push(stack* head);
extern bool Pop(stack *head);
extern void Display(stack* head);



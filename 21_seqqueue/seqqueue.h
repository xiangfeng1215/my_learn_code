#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct seqqueue
{
	int *data;
	int size;
	int rear;
	int front;
	int incresize;
}queue;

void Init_q(queue* q);
bool entry_queue(queue* q,int ele);
bool out_queue(queue* q);
void Display(queue* q);
bool Incresize(queue* q);

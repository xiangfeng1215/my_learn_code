#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

typedef struct node{
	int data;
	struct list_head list;
}node;

typedef struct queue{
	struct node* front;
	struct node* rear;
}queue;

extern void Init_queue(queue* q);
extern bool Entry_queue(queue* q,int element);
extern bool Out_queue(queue* q);
extern void Show_queue(queue* q);


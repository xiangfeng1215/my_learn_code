#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node{
	int data;
	struct node* next;
}node;

typedef struct queue{
	struct node* front;
	struct node* rear;
}queue;

void Init_queue(queue* q);
void Entry_queue(queue*q,int ele);
bool Out_queue(queue* q);
void Display(queue* q);



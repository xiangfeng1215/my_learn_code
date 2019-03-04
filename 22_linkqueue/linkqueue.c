#include "linkqueue.h"

void Init_queue(queue* q)
{
	q->front = (node*)malloc(sizeof(node));
	if(!q->front){
		exit(-1);
	}
	q->front->data = -1;
	q->front->next = NULL;

	q->rear = q->front;
}//end init queue

bool Entry_queue(queue* q,int ele)
{
	node* pnew = (node*)malloc(sizeof(node));

	if(!pnew){
		return false;
	}
	pnew->data = ele;
	pnew->next = NULL;

	q->rear->next = pnew;
	q->rear = q->rear->next;
	
	return true;
}//end entry queue

bool Out_queue(queue* q)
{
	if(q->front == q->rear){
		printf("list is empty\n");
		return false;
	}
	q->front->next = q->front->next->next;
	free(q->front->next);
	return true;
}//end Out_queue

void Display(queue* q)
{
	queue* pcur = q->front->next;
	for(;pcur != q->rear->next;pcur = pcur->next){
		printf("->%d",pcur->data);
	}
	putchar(10);
}//end Display

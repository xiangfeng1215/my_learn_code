#include "seqqueue.h"

void Init_q(queue* q)
{
	q->data = (int *)malloc(40);
	if(!q->data){
		exit(-1);
	}
	q->size = 10;
	q->front = 0;
	q->rear = 0;
	q->incresize = 5;
}

bool entry_queue(queue* q,int ele)
{
	if(q->rear == q->size){//(q->rear+1 )%q->size == q->front
		printf("list is full!\n");
		return false;
	}
	//q->rear = q->rear%(q->size);
	q->data[q->rear] = ele;
	q->rear ++;

	return 0;
}//end entry_queue

bool out_queue(queue* q)
{
	if(q->rear == q->front){
		printf("list is empty!\n");
	}
	//q->front = (q->front)%(q->size);
	q->front ++;

	return true;
}//end out_queue

void Display(queue* q)
{
	int i = 0;
	for(i =q->front;i < q->rear; i++){ //i != q->rear;i = i%q->size;
		printf("->%d",q->data[i]);
	}
	putchar(10);
}//end Display

bool Incresize(queue* q)
{
	queue* qnew;
	qnew->data = (int *)malloc(sizeof(int)*(q->size + q->incresize));
	if(!qnew->data){
		printf("malloc failed!\n");
		return false;
	}
	qnew->size = q->size + q->incresize;
	qnew->front = 0;
	qnew->rear = 0;
	qnew->incresize = q->incresize;
	
	int i = q->front;
	for(;i < q->size;i++){ // i != q->rear,i = i%q->size;
		qnew->data[i] = q->data[i];
	}
	free(q->data);
	q = qnew;
	return true;
}//end Increasize

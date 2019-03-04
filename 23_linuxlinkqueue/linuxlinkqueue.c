#include "linuxlinkqueue.h"

void Init_queue(queue* q)
{
	q->front = (node*)malloc(sizeof(node));
	if(!q->front){
		printf("malloc failed!\n");
		exit(-1);
	}
	
	q->front->data = -1;
	INIT_LIST_HEAD(&q->front->list);
	
	q->rear = q->front;

}//end Init_queue

bool Entry_queue(queue* q,int element)
{
	node* pnew = (node*)malloc(sizeof(node));
	if(!pnew){
		return false;
	}
	pnew->data = element;
	INIT_LIST_HEAD(&pnew->list);

	list_add_tail(&pnew->list,&q->rear->list);

	return true;
}//end entry_queue

bool Out_queue(queue* q)	
{
	node* tmp = NULL;
	if(list_empty(&q->rear->list)){
		printf("queue is empty!\n");
		return false;
	}	
	//list_del(q->front->list.next);
	__list_del(q->front->list.next->prev, q->front->list.next->next);
	tmp = list_entry(q->front->list.next,node,list);
	free(tmp);
	return true;
}//end out_queue

void Show_queue(queue* q)
{
	node* pos;
	list_for_each_entry(pos,&q->front->list,list){
		printf("->%d",pos->data);
	}
}//end show_queue


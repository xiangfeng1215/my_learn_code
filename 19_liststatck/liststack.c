#include "liststack.h"

void Init_head(stack** head)
{
	*head = (stack*)malloc(sizeof(stack));
	if(!(*head)){
		exit(-1);
	}

	(*head)->data = -1;
    (*head)->next = NULL;	
}//end init_hea

bool Push(stack* head,int element)
{
	stack *pnew = NULL;
	pnew->data = (stack*)malloc(sizeof(stack));
	i(!pnew->data){
		return false;
	}

	pnew->data = element;
	pnew->next = NULL;

	pnew->next = head->next;
	head->next = pnew;

	return true;
}//end push

static inline bool Is_empty(stack* head)
{
	return (head->next == NULL);
}//end is empty

bool Pop(stack* head)
{
	if(Is_empty(head)){
		printf("empty\n");
	}

	stack* pcur = head->next;
	head->next = pcur->next;
	free(pcur);
}//end pop

stack* GetTop()
{

}




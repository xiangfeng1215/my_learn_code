#include "doublelist.h"

dlist* Init_ret_head(void)
{
	dlist *head = (dlist*)malloc(sizeof(dlist));
	if(!head){
		exit(-1);
	}

	head->data = -1;
	head->next = head;
	head->prev = head;

	return head;
}

bool Create_list(dlist* head)
{
	dlist* pnew = NULL;
	dlist* pcur = head;

	int input;
	printf("input data:\n");
	scanf("%d",&input);
	while(input != -2){
		pnew = (dlist*)malloc(sizeof(dlist));
		if(!pnew){
			return false;
		}
		pnew->data = input;
		pcur->next = pnew;
		pnew->prev = pcur;
		pnew->next = NULL;
		pcur = pnew;
		
		scanf("%d",&input);
	}
	head->prev = pcur;
	pcur->next = head;

	return true;
}//create list

void Traverse_list(dlist* head)
{
	dlist* pcur = head->next;
	while(pcur != head){
		printf("->%d",pcur->data);
		pcur = pcur->next;
	}
	putchar(10);
}//end traverse list

bool Insert_list(dlist* head,int key,int input)
{
	dlist* pnew = NULL;
	dlist* pcur = head->next;
	
	pnew = (dlist*)malloc(sizeof(dlist));
	if(!pnew){
		return false;
	}
	pnew->data = input;
	pnew->next = NULL;
	pnew->prev = NULL;

	while(pcur != head && pcur->data != key){
		pcur = pcur->next;
	}
	
	pnew->next = pcur->next;
	pcur->next->prev = pnew;
	pnew->prev = pcur;
	pcur->next = pnew;
	return 0;

}//end insert list


bool Change_list(dlist* head,int key,int input)
{
	dlist* pnew = NULL;
	dlist* pcur = head->next;
	
	while(pcur != head && pcur->data != key){
		pcur = pcur->next;
	}
	
	pcur->data = input;
	
	return 0;
}//end change list
bool Destory_list(dlist* head)
{
	dlist* pcur = head->next;
	while(pcur != head){
		head->next = pcur->next;
		free(pcur);
		pcur = pcur->next;
	}
	free(head);
	head = NULL;
}//end Desttory list

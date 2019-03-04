#include "list.h"

void Init_head(linklist* *head_loc)
{
	*head_loc = (linklist*)malloc(sizeof(linklist));	
	if(*head_loc == NULL){
		return;
	}

	(*head_loc)->data = -1;
	(*head_loc)->next = NULL;
}//INIT_HEAD

bool Create_list(linklist* head)
{
	linklist* pcur = head;	
	linklist* pnew = NULL;

	printf("please input data!\n");
	int input;
	scanf("%d",&input);

	while(input != -1)
	{
		pnew = (linklist*)malloc(sizeof(linklist));
		if(pnew == NULL)
			return false;
		pnew->next = NULL;
		pnew->data = input;

		pcur->next = pnew;
		pnew->next = NULL;
		pcur = pcur->next;

		scanf("%d",&input);
	}
	return true;
}//CREATE_LIST

void Traverse_list(linklist* head)
{
	linklist* pcur = head->next;
	while(pcur != NULL)
	{
		printf("->%d",pcur->data);
		pcur = pcur->next;
	}
	putchar(10);
}//TRAVERSE_LIST

bool Insert_list(linklist* head,int key,int input)
{
	linklist* pnew = (linklist*)malloc(sizeof(linklist));
	if(!pnew)
		return false;
	pnew->next = NULL;
	pnew->data = input;

	linklist* pcur = head->next;
	while(pcur != NULL && pcur->data != key)
		pcur = pcur->next;

	if(!pcur){
		printf("can't find the keyword!\n");
		return false;
	}

	pnew->next = pcur->next;
	pcur->next = pnew;

	return true;
}//INSERT_LIST

linklist *Inverse_list(linklist *head)
{
	linklist *pcur, *prev;
	pcur = head->next;
	head->next = NULL;
	while (pcur != NULL)
	{
		prev = pcur;
		pcur = pcur->next;

		prev->next = head->next;
		head->next = prev;
	}
	return head;
}//end Inverse_list

void Turnover(linklist* head)
{
	linklist* prev,*pcur,*pn;
	int cnt = 0;
	pcur = head->next;
	while(pcur != NULL){
		pcur = pcur->next;
		cnt ++;
	}
	if(cnt <=2){
		printf("too short!\n");
		return;
	}

	ppre = head->next;
	pcur = prev->next;
	pn = pcur->next;

	while(pn != NULL){
		pcur->next = prev;

		prev = pcur;
		pcur = pn;
		pn = pn->next;
	}
	pcur->next = prev;
	head->next = pcur;
}


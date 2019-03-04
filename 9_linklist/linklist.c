#include "linklist.h"

typedef struct linklist linklist;

void Init_head(linklist** head_loc)
{
	*head_loc = (linklist*)malloc(sizeof(linklist));
	if(!(*head_loc)){
		exit(-1);
	}
	(*head_loc)->data = -1;
	(*head_loc)->next = *head_loc;
	return ;
}//end init_head

bool Create_list(linklist* head)
{
	linklist* pcur = head;
	linklist* pnew = NULL;

	int input;
	printf("please input data:\n");
	scanf("%d",&input);

	while(input != -1){
		pnew = (linklist*)malloc(sizeof(linklist));
		if(!pnew){
			return false;
		}
		pnew->data = input;
		pnew->next = NULL;

		pcur->next = pnew;
		pnew->next = NULL;

		pcur = pcur->next;
		scanf("%d",&input);
	}
	pcur->next = head;
	
	return true;
}//end create list

bool Traverse_list(linklist* head)
{
	linklist* pcur = head->next;
	while(pcur != head){
		printf("->%d",pcur->data);
		pcur = pcur->next;
	}
	putchar(10);

	return true;
}//end traverse list

bool Destory_list(linklist** head_loc)
{
	linklist* pcur = (*head_loc)->next;
	while(pcur != *head_loc){
		(*head_loc)->next = pcur->next;
		free(pcur);
		pcur = (*head_loc)->next;
	}
	free(*head_loc);
	*head_loc = NULL;
	
	return true;
}


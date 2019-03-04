#include "linuxlinklist.h"

node* Init_ret_head()
{
	node* head = (node*)malloc(sizeof(node));
	if(!head){
		return NULL;
	}
	INIT_LIST_HEAD(&head->list);
	return head;
}

bool Create_list(node* head)
{
	node* pnew = NULL;
	printf("input data(int)\n");
	int input;
	scanf("%d",&input);
	while(input != -1){
		pnew = (node*)malloc(sizeof(node));
		if(!pnew){
			return false;
		}
		pnew->data = input;
		INIT_LIST_HEAD(&pnew->list);
		list_add(&pnew->list,&head->list);
		scanf("%d",&input);
	}
	return true;
}//end create list

void Traverse(node* head)
{
	node* pos = NULL;
	list_for_each_entry(pos,&head->list,list){
		printf("->%d",pos->data);
	}
	putchar(10);
}//end traverse

bool List_move_tail(int key,node* head)
{
	node* pos = NULL;
	list_for_each_entry(pos,&head->list,list){
		if(pos->data == key){
			list_move_tail(&pos->list,&head->list);
			return true;
		}
	}
	return false;
}//end list_move_tail

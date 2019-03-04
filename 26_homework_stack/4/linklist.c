#include "linklist.h"

linklist* Init_head(void)
{
	linklist* f = (linklist*)malloc(sizeof(linklist));
	if(!f)
		return NULL;
	f->data = 0;
	f->next = NULL;

	return f;
}//INIT_HEAD

bool Create_list(linklist* f)
{
	linklist* pcur = f;
	linklist* pnew = NULL;

	int input;
	scanf("%d",&input);

	while(input != -1)
	{
		pnew = (linklist*)malloc(sizeof(linklist));
		if(!pnew)
			return false;
		pnew->data = input;		
		pnew->next = NULL;

		pcur->next = pnew;
		pnew->next = NULL;
		pcur = pnew;

		scanf("%d",&input);
	}
	return true;	
}//CREATE_LINK

void Traverse_list(linklist* f)
{
	if(f == NULL){
		printf("list is destroyed!\n");
		return;
	}

	linklist* pcur = f->next;
	while(pcur != NULL)
	{
		printf("->%d",pcur->data);
		pcur = pcur->next;
	}
	putchar(10);
}//TRAVERSE_LIST	

int  Max_number(linklist* f)
{
	if(!f->next)
		return f->data;
	
	int tmp;
	tmp=Max_number(f->next);
	if(f->data > tmp)
		return f->data;
	else
		return tmp;
}

int Inode_number(linklist* f)
{
	if(!f->next)	
		return 0;
	int count=1;
	return count+Inode_number(f->next);
}

float Average_list(linklist* f)
{
	if(!f->next)
		return f->data;
	float sum=0;
	sum+=f->data;
	return sum+Average_list(f->next);
}

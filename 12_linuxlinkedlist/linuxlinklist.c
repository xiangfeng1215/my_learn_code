#include "linuxlinklist.h"

dlist* Init(dlist* head)
{
	head = (dlist*)malloc(sizeof(dlist));
	if(!head){
		perror("malloc head");
		exit(-1);
	}
	INIT_LIST_HEAD(&head->mylist);

	return head;
}//end dlist

bool Insert_tail(dlist* head,char *name,int score,int classs)
{
	dlist* pnew = (dlist*)malloc(sizeof(dlist));
	if(!pnew){
		return false;	
	}
	strcpy(pnew->name,name);
	pnew->score = score;
	pnew->classs = classs;

	list_add_tail(&(pnew->mylist),&(head->mylist));

	return true;
}

bool Delete_node(dlist* head,char *name)
{
	dlist* p = NULL;
	list_for_each_entry(p,&((head->mylist)),mylist){
		if(!strcmp(p->name,name)){
			list_del(&p->mylist);
			printf("%s is delete finsh!\n",name);
			return true;
		}else{
			printf("can't find the name!\n");
			return false;
		}
	}
	return true;
}

bool find_node(dlist* head,char *data)
{
	dlist* p = NULL;
	list_for_each_entry(p,&(head->mylist),mylist){
		if(!strcmp(p->name,data)){
			printf("you find name is %s\n",data);
			printf("name is %s,socre is %d class is %d\n",p->name,p->score,p->classs);
			return true;
		}else{
			printf("can't find \n");
			return false;
		}

	}
}

void show_list(dlist* head)
{
	dlist* p = NULL;
	list_for_each_entry(p,&head->mylist,mylist){
			printf("name is %s,socre is %d class is %d\n",p->name,p->score,p->classs);

	}
}


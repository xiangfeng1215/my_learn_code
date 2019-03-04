#include "linuxlinklist.h"


typedef struct node node;

void Init_head(node **head_loc)
{
	//malloc space
	(*head_loc) = (node*)malloc(sizeof(node));
	if(!(*head_loc)){
		exit(-1);
	}
	INIT_LIST_HEAD(&(*head_loc)->list);
}//end init_head


bool Create_list(node* head)
{
	struct humen tmp;
	printf("input name age number:\n");
	scanf("%s%d%d",tmp.name,&tmp.age,&tmp.number);

	while(tmp.number != -1 ||tmp.age != -1){
		struct node* pnew = NULL;
		pnew = (node*)malloc(sizeof(node));
		if(!pnew){
			return false;
		}
		pnew->data = tmp;

		INIT_LIST_HEAD(&pnew->list);

		list_add_tail(&pnew->list,&head->list);
		scanf("%s%d%d",tmp.name,&tmp.age,&tmp.number);
		
	}

}//end create_list

bool Insert_data(node* head,int num,struct humen* input)
{
	node* pos = NULL;
	node *pnew = (node*)malloc(sizeof(node));
	pnew->data = *input;
	list_for_each_entry(pos,&head->list,list){
		if(pos->data.number == num){
			__list_add(&pnew->list,&pos->list,pos->list.next);
			/*list_add(&pnew->list,&pos->list);*/
		}
	}
	
	return false;
}//end insert_data

bool Insert_data_tail(node* head,int num,struct humen* input)
{
	node* pos = NULL;
	node *pnew = (node*)malloc(sizeof(node));
	pnew->data = *input;
	list_for_each_entry(pos,&head->list,list){
		if(pos->data.number == num){
			list_add_tail(&pnew->list,&pos->list);
			//__list_add(&pnew->list,&pos->list.prev,pos->list);
		}
	}
	return false;
}//end data tail
bool Delete_data(node* head,int num)
{
	node* pos;
	list_for_each_entry(pos,&head->list,list){
		if(pos->data.number == num){
			__list_del(pos->list.prev,pos->list.next);
			//list_del(&pos->list);
			free(pos);
			pos = NULL;
			return true;
		}
	}
		return false;
}//end delete_data

struct node* Find_node_pos(struct node* head,int num)
{
	node* pos = NULL;
	list_for_each_entry(pos,&head->list,list){
		if(pos->data.number == num){
			return pos;
		}
	}
	return NULL;
}//end find node position

void Traverse(node* head)
{
	node* pos = NULL;
	list_for_each_entry(pos,&head->list,list){
		printf(" name:%s ,age :%d, number:%d \n",pos->data.name,pos->data.age,pos->data.number);
	}
}//end traverse

void Traverse_reverse(node* head)
{
	node* pos = NULL;
	list_for_each_entry_reverse(pos,&head->list,list){
		printf("name: %s,age:%d, number:%d \n",pos->data.name,pos->data.age,pos->data.number);
	}
}//end traverse reverese

void Traverse_continue(node* head,node* pos)
{	
   list_for_each_entry_continue(pos,&head->list,list){
		printf("name: %s,age:%d, number:%d \n",pos->data.name,pos->data.age,pos->data.number);

   }	   
}//end Traverse_continue

void Traverse_continue_reverse(node* head,node* pos)
{
	list_for_each_entry_continue_reverse(pos,&head->list,list){
		printf("name : %s, age : %d ,number : %d,\n",pos->data.name,pos->data.age,pos->data.number);
	}
}//end Traverse continue reverse

bool My_replace(struct node* head,int num,struct humen tmp)
{
	node* pos;
	list_for_each_entry(pos,&head->list,list){
		if(pos->data.number == num){
			__list_del(pos->list.prev,pos->list.next);
			//list_del(&pos->list);
			pos->data = tmp ;
			pos = NULL;
			return true;
		}
	}
	return false;	
}//end my_replace

bool My_move(struct node* head,int num)
{
	node* pos = NULL;
	list_for_each_entry(pos,&head->list,list){
		if(pos->data.number == num){
			list_move(&pos->list,&head->list);
			return true;
		}
	}
	return false;
}//end My_move

bool My_move_tail(struct node* head,int num)
{
	node* pos = NULL;
	list_for_each_entry(pos,&head->list,list){
		if(pos->data.number == num){
			__list_del_entry(&pos->list);
			list_add_tail(&pos->list,&head->list);
			return true;
		}
	}
	return false;
}//end My_move_tail


bool My_rotate_left(struct node* head){
	int i = 0;
	node* pos = NULL;
	list_for_each_entry(pos,&head->list,list){
		i++;
	}
	for(;i>=0;i--){
		list_rotate_left(&head->list);
	}
	return true;
}//end My_rotate_left

bool List_add_head(node* head,struct humen pnew)
{
	node* tmp = (node*)malloc(sizeof(node));
	if(!tmp){
		return false;
	}
	tmp->data = pnew;
	INIT_LIST_HEAD(&tmp->list);

	list_add(&tmp->list,&head->list);

	return true;
}//end list_add_head

bool List_empty(node* head)
{
	if(list_empty(&head->list) == true){
		return true;
	}
	
	return false;
}//end List_empty

bool List_is_singular(node* head)
{
	return (list_is_singular(&head->list) == true);
	
}//end list is singular

bool List_is_last(node* head,node* pos)
{
	return list_is_last(&pos->list,&head->list);
}

void List_copy(node* head_src,node* head_dest)
{
	list_cut_position(&head_dest->list,&head_src->list,head_src->list.prev);
}//list copy

bool List_cut_position(node* head_src,node* head_dest,int num)
{
	node *pos = NULL;
	list_for_each_entry(pos,&head_src->list,list){
		if(pos->data.number == num){
			list_cut_position(&head_dest->list,&head_src->list,&pos->list);
			return true;
		}
	}
	return false;
}//list cut position

void List_splice(node* head_src,node* head_dest)
{
	list_splice(&head_dest->list,&head_src->list);
}//end list splice

void List_splice_tail(node* head_src,node* head_dest)
{
	list_splice_tail(&head_dest->list,&head_src->list);
	
}//end list splice tail

void List_splice_init(node* head_src,node* head_dest)
{
	list_splice_init(&head_dest->list,&head_src->list);

}//end list splice init

void List_splice_tail_init(node* head_src,node* head_dest)
{
	list_splice_tail_init(&head_dest->list,&head_src->list);

}//end list splice tail init
